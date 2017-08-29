/*
** malloc.c for malloc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_malloc/lib
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Wed Jan 25 15:50:22 2017 Rodrigue René
** Last update Thu Feb  9 00:22:40 2017 Gregoire Renard
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"

pthread_mutex_t		mutexm = PTHREAD_MUTEX_INITIALIZER;

static bool		block_is_valid(int size,
				       t_alloc *tmp,
				       t_alloc **previous,
				       int *i)
{
  if (tmp->free == TRUE && tmp->size >= size)
    {
      if (tmp->size == size)
	return (TRUE);
      if (tmp->next->next == NULL)
	{
	  if (tmp->size > size)
	    if ((*i) == 0 || (*previous)->size > tmp->size)
	      return (TRUE);
	}
      else if ((*i) == 0)
	{
	  (*previous) = tmp;
	  (*i)++;
	}
      else if ((*previous)->size > tmp->size)
	return (TRUE);
    }
  return (FALSE);
}

static t_alloc		*check_memory(int size)
{
  t_alloc		*tmp;
  t_alloc		*previous;
  int			i;

  i = 0;
  tmp = memory;
  previous = NULL;
  while (tmp->next != NULL)
    {
      if (block_is_valid(size, tmp, &previous, &i))
	return (tmp);
      tmp = tmp->next;
    }
  return (previous);
}

static void		split_memory_in_two(t_alloc *this,
					    int	size)
{
  t_alloc		*new;

  new = this->ptr + size;
  new->size = (this->size - size) - sizeof(*new);
  new->free = TRUE;
  new->ptr = this->ptr + size + sizeof(*new);
  new->prev = this;
  new->next = this->next;
  this->next = new;
  this->free = FALSE;
  this->size = size;
  new->ptr_end = this->ptr_end;
  this->ptr_end = this->ptr + size;
  new->ptr_start = new->ptr;
  this->and = 0;
  new->and = 0;
  new->mode = BLOCK;
}

static void		split_memory(t_alloc *this, int size)
{
  if (this->size != size && (int)(this->size - (size + sizeof(*this))) >= 1)
    split_memory_in_two(this, size);
  else if (this->size != size)
    {
      this->free = FALSE;
      this->and = this->size - size;
      this->size = size;
      this->ptr_end = this->ptr + size;
    }
  else
    this->free = FALSE;
}

void			*malloc(size_t size)
{
  static int	i = 0;
  t_alloc	*this;

  xlocker(&mutexm);
  if (i == 0)
    {
      if ((start_malloc()) == -1)
	return (NULL);
      i++;
    }
  this = check_memory(size);
  if (this == NULL && (new_page(&this, size)) == -1)
    return (NULL);
  split_memory(this, size);
  dexlocker(&mutexm);
  return (this->ptr);
}
