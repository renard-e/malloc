/*
** word_word.c for  in /home/renard_e/2/ProgElem/trade/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Jan 30 11:28:08 2017 Gregoire Renard
** Last update Mon Feb  6 13:14:08 2017 Gregoire Renard
*/

#include <stdlib.h>
#include "malloc.h"

int		word_word(const char *str1, const char *str2)
{
  int		cpt;

  cpt = 0;
  if (str1 == NULL || str2 == NULL)
    return (-1);
  while (str1[cpt] != '\0' && str2[cpt] != '\0')
    {
      if (str1[cpt] != str2[cpt])
	return (-1);
      cpt++;
    }
  if (str1[cpt] == '\0' && str2[cpt] == '\0')
    return (1);
  return (-1);
}
