/*
** show_alloc_mem.c for  in /home/renard_e/2/systeme_unix_memoire/PSU_2016_malloc/lib
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Sun Jan 29 12:24:13 2017 Gregoire Renard
** Last update Tue Feb  7 02:36:11 2017 Gregoire Renard
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "malloc.h"

void			show_alloc_mem()
{
  t_alloc		*tmp;

  tmp = memory;
  fprintf(stderr, "break : %p\n", tmp->ptr_start);
  tmp = tmp->next;
  while (tmp->next != NULL)
    {
      if (tmp->free == FALSE && tmp->mode == BLOCK)
	fprintf(stderr, "%p - %p : %d bytes\n", tmp->ptr_start,
		tmp->ptr_end, tmp->size);
      tmp = tmp->next;
    }
}
