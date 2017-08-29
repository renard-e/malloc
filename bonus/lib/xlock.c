/*
** xlock.c for malloc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_malloc
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Sun Feb  5 04:44:57 2017 Rodrigue René
** Last update Mon Feb  6 18:45:01 2017 Gregoire Renard
*/

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "malloc.h"

void	xlocker(pthread_mutex_t *lockl)
{
  pthread_mutex_lock(lockl);

}

void	dexlocker(pthread_mutex_t *lockl)
{
  pthread_mutex_unlock(lockl);
}
