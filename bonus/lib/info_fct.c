/*
** info_fct.c for  in /home/renard_e/2/systeme_unix_memoire/PSU_2016_malloc/lib
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Feb  3 17:28:49 2017 Gregoire Renard
** Last update Tue Feb  7 17:04:36 2017 Gregoire Renard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"

static FILE		*get_file()
{
  char			*path;
  FILE			*file;

  if ((path = getenv("MALLOC_OPTIONS")) == NULL)
    {
      path = malloc(10);
      free(path);
      return (NULL);
    }
  if ((file = fopen(path, "r")) == NULL)
    return (NULL);
  return (file);
}

static int		set_info(int tmp, char *status)
{
  if (info[tmp].change == TRUE)
    return (-1);
  if ((word_word(status, "FALSE")) == 1)
    {
      info[tmp].change = TRUE;
      info[tmp].status = FALSE;
      return (1);
    }
  else if ((word_word(status, "TRUE")) == 1)
    {
      info[tmp].change = TRUE;
      info[tmp].status = TRUE;
      return (1);
    }
  return (-1);
}

static int		check_tab(char **tab)
{
  int			tmp;

  tmp = 0;
  if (((strlen_tab(tab) != 3) || (word_word(tab[1], ":") == -1)))
    {
      if (strlen_tab(tab) == 5)
	return (set_info_pagesize(tab));
      return (-1);
    }
  while (info[tmp].flag != NULL)
    {
      if ((word_word(info[tmp].flag, tab[0])) == 1)
	return (set_info(tmp, tab[2]));
      tmp++;
    }
  return (-1);
}

static void		read_info()
{
  t_parse		parse;

  parse.size = 0;
  parse.cpt = 0;
  if ((parse.file = get_file()) != NULL)
    {
      while ((getline(&parse.line, &parse.size, parse.file)) > 0
	     && parse.cpt < 8)
	{
	  if (strlen(parse.line) > 0)
	    parse.line[strlen(parse.line) - 1] = 0;
	  if ((parse.tab = my_str_to_word_tab(parse.line)) == NULL
	      || (check_tab(parse.tab)) == -1)
	    parse.cpt = 8;
	  else
	    parse.cpt++;
	  parse.size = 0;
	}
    }
}

void			init_info()
{
  int			cpt;

  cpt = 0;
  info[0].flag = "A";
  info[1].flag = "R";
  info[2].flag = "V";
  info[3].flag = "X";
  info[4].flag = "PRINT";
  info[5].flag = "PAGE_SIZE";
  info[6].flag = "BEST";
  info[7].flag = NULL;
  while (info[cpt].flag != NULL)
    {
      info[cpt].value = 0;
      info[cpt].status = FALSE;
      info[cpt].change = FALSE;
      cpt++;
    }
  read_info();
}
