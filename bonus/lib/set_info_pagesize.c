/*
** set_info_pagesize.c for  in /home/renard_e/2/systeme_unix_memoire/PSU_2016_malloc/lib
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  6 17:18:52 2017 Gregoire Renard
** Last update Tue Feb  7 17:37:25 2017 Gregoire Renard
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "malloc.h"

static int		check_alpha(char *str)
{
  int			cpt;

  cpt = 0;
  while (str[cpt] != '\0')
    {
      if (str[cpt] < '0' && str[cpt] > '9')
	return (-1);
      cpt++;
    }
  return (0);
}

static int			set_value_pagesize(char *nb)
{
  int				number;

  if (strlen(nb) > 8)
    return (-1);
  number = atoi(nb);
  if (number < 4096)
    return (-1);
  return (number);
}

static int			set_last_pagesize(int tmp, char **tab)
{
  if ((word_word(tab[2], "FALSE")) == 1)
    {
      info[tmp].status = FALSE;
      info[tmp].change = TRUE;
      return (1);
    }
  if ((word_word(tab[2], "TRUE")) == 1)
    {
      if ((info[tmp].value = set_value_pagesize(tab[4])) == -1)
	return (-1);
      info[tmp].status = TRUE;
      info[tmp].change = TRUE;
      return (1);
    }
  else
    return (-1);
}

int			set_info_pagesize(char **tab)
{
  int			tmp;

  tmp = 0;
  if ((word_word(tab[1], ":")) == -1 || (word_word(tab[3], ":")) == -1
      || (word_word(tab[0], "PAGE_SIZE")) == -1)
    return (-1);
  while (info[tmp].flag != NULL &&
	 (word_word(tab[0], info[tmp].flag)) != 1)
    tmp++;
  if (info[tmp].change == TRUE)
    return (-1);
  if ((check_alpha(tab[4])) == -1)
    return (-1);
  return (set_last_pagesize(tmp, tab));
}
