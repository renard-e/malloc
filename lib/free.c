/*
** free.c for  in /home/renard_e/2/systeme_unix_memoire/PSU_2016_malloc/lib
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Sun Jan 29 12:17:45 2017 Gregoire Renard
** Last update Thu Feb  9 00:15:55 2017 Gregoire Renard
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "malloc.h"

extern pthread_mutex_t		mutexm;

static void			remove_block(t_alloc *this)
{
  t_alloc			*tmp;

  tmp = this->next;
  this->size += tmp->size + sizeof(*tmp) + this->and + tmp->and;
  this->ptr_end = this->ptr_start + this->size;
  this->next->next->prev = this;
  this->next = this->next->next;
  this->ptr = this->ptr_start;
  this->and = 0;
  tmp = NULL;
}

static t_alloc			*get_memory_ptr(void *ptr)
{
  t_alloc			*this;

  this = ptr - sizeof(*this);
  if (this == NULL || this->mode == START ||
      this->mode == END || this->free == TRUE)
    return (NULL);
  return (this);
}

static t_alloc			*count_block(t_alloc *this, int *cpt, int opt)
{
  status			mode_type;

  if (opt == 1)
    mode_type = START;
  else
    mode_type = END;
  while ((this != NULL) && (this->mode != mode_type) && ((*cpt) < 1))
    {
      if (this->mode == BLOCK && this->free == FALSE)
	(*cpt)++;
      if (opt == 1)
	this = this->prev;
      else if (opt == 2)
	this = this->next;
    }
  return (this);
}

void				check_page(t_alloc *this)
{
  t_alloc			*tmp_start;
  t_alloc			*tmp_end;
  int				cpt;

  cpt = 0;
  tmp_start = count_block(this, &cpt, 1);
  tmp_end = count_block(this, &cpt, 2);
  if (cpt == 0)
    {
      if (tmp_start != NULL && tmp_start->prev != NULL)
	{
	  if (tmp_end != NULL)
	    tmp_start->prev->next = tmp_end->next;
	  if (tmp_end == NULL)
	    tmp_start->prev->next = NULL;
	  if (tmp_end != NULL && tmp_end->next != NULL)
	    tmp_end->next->prev = tmp_start->prev;
	  brk(tmp_start->ptr_start);
	}
    }
}

void				free(void *ptr)
{
  t_alloc			*this;

  if (ptr != NULL)
    {
      xlocker(&mutexm);
      if ((this = get_memory_ptr(ptr)) != NULL)
	{
	  this->free = TRUE;
	  if (this->next->free == TRUE)
	    remove_block(this);
	}
      dexlocker(&mutexm);
    }
}
