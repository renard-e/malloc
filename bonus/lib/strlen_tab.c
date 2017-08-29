/*
** strlen_tab.c for  in /home/renard_e/2/systeme_unix_memoire/PSU_2016_malloc/lib
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  6 16:25:20 2017 Gregoire Renard
** Last update Mon Feb  6 16:26:52 2017 Gregoire Renard
*/

#include <stdlib.h>
#include "malloc.h"

int			strlen_tab(char **tab)
{
  int			cpt;

  cpt = 0;
  while (tab[cpt] != NULL)
    cpt++;
  return (cpt);
}
