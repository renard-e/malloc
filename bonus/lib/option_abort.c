/*
** option_abort.c for malloc in /home/renard_e/2/systeme_unix_memoire/PSU_2016_malloc/lib
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Feb  7 02:48:14 2017 Gregoire Renard
** Last update Tue Feb  7 22:50:05 2017 Gregoire Renard
*/

#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

void		*option_abort(int reason)
{
  char		*str;

  if (info[0].status == FALSE || info[3].status == FALSE)
    return (NULL);
  str = (reason == 0) ? "Malloc faillure" : "Size smaller than one";
  fprintf(stderr, "Error : %s\n", str);
  abort();
}
