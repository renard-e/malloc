/*
** realloc.c for malloc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_malloc/lib
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Wed Jan 25 15:53:49 2017 Rodrigue René
** Last update Thu Feb  9 00:16:25 2017 Gregoire Renard
*/

#include <unistd.h>
#include <string.h>
#include "malloc.h"

extern pthread_mutex_t	mutexm;

t_alloc			*search_bestptr(int size, t_alloc **tmp)
{
  void			*new;

  (*tmp)->free = TRUE;
  (*tmp)->size += (*tmp)->and;
  (*tmp)->and = 0;
  if ((new = malloc(size)) == NULL)
    return (NULL);
  return (new - sizeof(t_alloc));
}

void			*realloc(void *ptr, size_t size)
{
  t_alloc		*tmp;
  t_alloc		*new;

  if (size == 0)
    free(ptr);
  else if (ptr == NULL)
    return (new = malloc(size));
  tmp = ptr - sizeof(t_alloc);
  if ((new = search_bestptr(size, &tmp)) == NULL)
    return (NULL);
  xlocker(&mutexm);
  memcpy(new->ptr, ptr, (tmp->size > new->size) ? new->size : (int)size);
  new->size = size;
  dexlocker(&mutexm);
  if (new->ptr != tmp->ptr)
    free(ptr);
  return (new->ptr);
}
