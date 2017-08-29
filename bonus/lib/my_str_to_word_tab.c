/*
** my_str_to_word_tab.c for my_str_to_word_tab in /home/renard_e/bin/Makefile_lib/lib/my
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Thu Mar 31 15:57:34 2016 gregoire renard
** Last update Mon Feb  6 16:57:56 2017 Gregoire Renard
*/

#include <stdlib.h>
#include "malloc.h"

static void	set_null(char **cmd)
{
  int		null;

  null = 0;
  while (cmd[null] != NULL)
    {
      if (cmd[null][0] == '\0')
	cmd[null] = NULL;
      null++;
    }
}

static void	remp_2d(t_all *all, char **cmd, char *arg)
{
  while (all->remp < all->e)
    {
      cmd[all->dimen][all->i] = arg[all->remp];
      all->i = all->i + 1;
      all->remp = all->remp + 1;
    }
  all->i = 0;
  all->dimen = all->dimen + 1;
}

static int	all_cmd_di_2(char *arg, char **cmd, int cpt)
{
  t_all		all;

  all.s = 0;
  all.i = 0;
  all.dimen = 0;
  while (all.dimen <= cpt && arg[all.s] != '\0')
    {
      while ((arg[all.s] == ' ' || arg[all.s] == '\t') && arg[all.s] != '\0')
        all.s++;
      all.e = all.s;
      while (arg[all.e] != ' ' && arg[all.e] != '\t' && arg[all.e] != '\0')
        all.e = all.e + 1;
      all.dif = all.e - all.s;
      if ((cmd[all.dimen] = malloc(all.dif + 1)) == NULL)
        return (0);
      cmd[all.dimen][all.dif] = '\0';
      all.remp = all.s;
      remp_2d(&all, cmd, arg);
      all.s = all.e;
    }
  cmd[all.dimen] = NULL;
  return (1);
}

char		**my_str_to_word_tab(char *arg)
{
  int		i;
  int		cpt;
  char		**cmd;

  i = 0;
  cpt = 0;
  while (arg[i] != '\0')
    {
      while ((arg[i] == ' ' || arg[i] == '\t') && arg[i] != '\0')
        i = i + 1;
      cpt = cpt + 1;
      while (arg[i] != ' ' && arg[i] != '\t' && arg[i] != '\0')
        i = i + 1;
    }
  if ((cmd = malloc((cpt + 1) * sizeof(char *))) == NULL)
    return (NULL);
  if ((all_cmd_di_2(arg, cmd, cpt)) == 0)
    return (NULL);
  set_null(cmd);
  return (cmd);
}
