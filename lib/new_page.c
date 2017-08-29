/*
** new_page.c for malloc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_malloc/lib
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Wed Feb  1 03:53:47 2017 Rodrigue René
** Last update Thu Feb  9 00:22:57 2017 Gregoire Renard
*/

#include "malloc.h"

static void		build_middle(t_alloc **middle,
				     t_alloc *new_start,
				     void *end)
{
  (*middle)->ptr = new_start->ptr + sizeof(t_alloc);
  (*middle)->size = end - (*middle)->ptr;
  (*middle)->free = TRUE;
  (*middle)->ptr_start = (*middle)->ptr;
  (*middle)->mode = BLOCK;
}

static int		build_page(t_alloc **middle,
				    t_alloc **ex_end,
				    int new_size)
{
  void			*start;
  void			*end;
  t_alloc		*ender;
  t_alloc		*new_start;

  if ((start = sbrk(0)) == (void *)-1
      || (end = sbrk(new_size + sizeof(*ender)) + new_size) == (void *)-1)
    return (-1);
  new_start = start;
  ender = end;
  new_start->size = sizeof(t_alloc);
  ender->size = sizeof(t_alloc);
  push_in_list((*ex_end), ender, new_start, START);
  push_in_list(new_start, NULL, ender, END);
  new_start->ptr_start = new_start;
  new_start->ptr_end = new_start->ptr_start + sizeof(t_alloc);
  ender->ptr_start = ender;
  ender->ptr_end = ender + sizeof(*ender);
  new_start->ptr = start + sizeof(t_alloc);
  (*middle) = new_start->ptr;
  insert_after(new_start, (*middle));
  build_middle(middle, new_start, end);
  (*ex_end)->next = (*middle)->prev;
  (*middle)->prev->prev = (*ex_end);
  return (0);
}

int			new_page(t_alloc **this,
				  int size)
{
  t_alloc		*tmp;
  int			gps;

  if (size <= 0)
    return (-1);
  gps = getpagesize();
  tmp = memory;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if (size > (int)(gps - (2 * sizeof(t_alloc) + 1)))
    {
      if (build_page(this, &tmp, size + 2 * sizeof(t_alloc)) == -1)
	return (-1);
    }
  else
    if (build_page(this, &tmp, getpagesize()) == -1)
      return (-1);
  return (0);
}
