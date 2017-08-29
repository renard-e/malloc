##
## Makefile for  in /home/renard_e/2/systeme_unix_memoire/PSU_2016_malloc
## 
## Made by Gregoire Renard
## Login   <renard_e@epitech.net>
## 
## Started on  Tue Jan 24 16:57:44 2017 Gregoire Renard
## Last update Wed Feb  8 10:50:01 2017 Gregoire Renard
##

CC	=	gcc -pthread -lpthread -Iincludes/

RM	=	rm -fr

NAME	=	libmy_malloc.so

CFLAGS	=	-W -Werror -Wextra

FLAGS1	=	-c -fPIC

FLAGS2	=	-shared -o

SRCS    =	lib/malloc.c \
	 	lib/free.c \
		lib/realloc.c \
		lib/show_alloc_mem.c \
		lib/start_malloc.c \
		lib/new_page.c \
		lib/info_fct.c \
		lib/set_info_pagesize.c \
		lib/xlock.c \
		lib/show_info.c \
		lib/word_word.c \
		lib/my_str_to_word_tab.c \
		lib/strlen_tab.c \
		lib/option_abort.c \
		lib/option_print.c \


OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(FLAGS1) $(SRCS)
		$(CC) $(FLAGS2) $(NAME) *.o

clean:
		$(RM) $(OBJS)
		$(RM) *.o

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all re clean fclean
