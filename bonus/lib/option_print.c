/*
** option_print.c for  in /home/renard_e/2/systeme_unix_memoire/PSU_2016_malloc/bonus
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Feb  7 17:12:59 2017 Gregoire Renard
** Last update Mon Feb 13 17:21:57 2017 Gregoire Renard
*/

#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

void			*option_print(t_alloc *this)
{
  if (info[4].status == TRUE)
    fprintf(stderr,
	    "Malloc/Realloc allocated %i bytes at : adress : %p to %p\n",
	    this->size, this->ptr, this->ptr + this->size);
  return (this->ptr);
}
