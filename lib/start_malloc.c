/*
** start_malloc.c for malloc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_malloc/lib
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Wed Feb  1 03:13:44 2017 Rodrigue René
** Last update Sun Feb 12 19:35:52 2017 Rodrigue René
*/

#include "malloc.h"

void		push_in_list(t_alloc *prev,
			     t_alloc *next,
			     t_alloc *this,
			     status mode)
{
  this->next = next;
  this->prev = prev;
  this->free = FALSE;
  this->and = 0;
  this->size = sizeof(*this);
  this->mode = mode;
}

void		insert_after(t_alloc *prev,
			     t_alloc *this)
{
  this->next = prev->next;
  prev->next->prev = this;
  this->prev = prev;
  prev->next = this;
  this->ptr_start = memory;
  this->ptr_end = memory->ptr_end;
  this->and = 0;
}

static void	set_middle(t_alloc **middle, void *end)
{
  (*middle)->ptr = memory->ptr + sizeof(t_alloc);
  (*middle)->size = end - (*middle)->ptr;
  (*middle)->free = TRUE;
  (*middle)->ptr_start = (*middle)->ptr;
  (*middle)->mode = BLOCK;
}

int		start_malloc(void)
{
  void		*start;
  void		*end;
  int		gps;
  t_alloc	*ender;
  t_alloc	*middle;

  if ((gps = getpagesize()) < 1 || (start = sbrk(0)) == (void *)-1 ||
      (end = sbrk(gps + sizeof(*ender) + 1) + gps) == (void *)-1)
    return (-1);
  memory = start;
  ender = end + 1;
  push_in_list(NULL, ender, memory, START);
  push_in_list(memory, NULL, ender, END);
  memory->ptr_start = memory;
  memory->ptr_end = memory->ptr_start + sizeof(*memory);
  ender->ptr_start = ender;
  ender->ptr_end = ender + sizeof(*ender);
  memory->ptr = start + sizeof(*memory) + 1;
  middle = memory->ptr;
  insert_after(memory, middle);
  set_middle(&middle, end);
  return (0);
}
