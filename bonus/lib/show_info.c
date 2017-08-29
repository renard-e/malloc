/*
** show_info.c for  in /home/renard_e/2/systeme_unix_memoire/PSU_2016_malloc/lib
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  6 11:43:22 2017 Gregoire Renard
** Last update Tue Feb  7 01:33:05 2017 Gregoire Renard
*/

#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

static char		*status_str(bool status)
{
  if (status == FALSE)
    return ("FALSE");
  else
    return ("TRUE");
}

void			show_info()
{
  int			cpt;

  cpt = 0;
  while (info[cpt].flag != NULL)
    {
      if ((word_word(info[cpt].flag, "PAGE_SIZE")) == 1)
	fprintf(stderr, "%s : %s : %i\n", info[cpt].flag,
		status_str(info[cpt].status), info[cpt].value);
      else
	fprintf(stderr, "%s : %s\n", info[cpt].flag,
		status_str(info[cpt].status));
      cpt++;
    }
}
