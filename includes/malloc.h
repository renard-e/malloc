/*
** malloc.h for malloc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_malloc/includes
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Wed Jan 25 17:35:34 2017 Rodrigue René
** Last update Thu Feb  9 00:22:23 2017 Gregoire Renard
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef enum		e_bool
  {
    FALSE,
    TRUE
  }			bool;

typedef enum		e_status
  {
    START,
    BLOCK,
    END
  }			status;

typedef struct		s_alloc
{
  struct s_alloc	*prev;
  struct s_alloc	*next;
  int			size;
  bool			free;
  void			*ptr;
  void			*ptr_start;
  void			*ptr_end;
  int			and;
  status		mode;
}			t_alloc;

typedef struct		s_info
{
  char			*flag;
  bool			status;
  int			value;
  bool			change;
}			t_info;

typedef struct		s_parse
{
  size_t		size;
  int			cpt;
  char			*line;
  char			**tab;
  FILE			*file;
}			t_parse;

typedef struct		s_all
{
  int			s;
  int			e;
  int			dif;
  int			remp;
  int			i;
  int			dimen;
}			t_all;

t_alloc			*memory;
t_info			info[8];

void			show_alloc_mem();
void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
int			start_malloc(void);
int			new_page(t_alloc **this, int size);
void			push_in_list(t_alloc *prev, t_alloc *next, t_alloc *this, status mode);
void			insert_after(t_alloc *prev, t_alloc *this);
void			xlocker(pthread_mutex_t *lockl);
void			dexlocker(pthread_mutex_t *lockl);
void			init_info();
int			set_info_pagesize(char **tab);
void			show_info();
int			word_word(const char *str1, const char *str2);
char			**my_str_to_word_tab(char *str);
int			strlen_tab(char **tab);
void			init_info();
void			*option_abort(int reason);

#endif /* !MALLOC_H_ */
