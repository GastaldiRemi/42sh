##
## Makefile for Makefile in /home/roig_a/PSU_2015_minishell2
## 
## Made by Antoine Roig
## Login   <roig_a@epitech.net>
## 
## Started on  Sun Apr 10 05:14:49 2016 Antoine Roig
## Last update Thu May  5 19:32:21 2016 
##


ECHO            =       /bin/echo -e
DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[0;31m"

CC              =       gcc

NAME            =       mysh

CFLAGS		+=	-D_POSIX_C_SOURCE -D_XOPEN_SOURCE -D_POSIX_SOURCE

CFLAGS          +=       -Wextra -Wall -W -pedantic -ansi -g -Iinclude

SRC             =       sources/main.c		\
			sources/env.c		\
			sources/add_list.c	\
			sources/pop_list.c	\
			sources/utils_list.c	\
			sources/utils2.c	\
			sources/free_memorie.c	\
			sources/utils.c		\
			sources/my_strlen.c	\
			sources/path.c		\
			sources/get_instruct.c	\
			sources/epur.c		\
			sources/getnextline.c	\
			sources/cmd.c		\
			sources/cmd3.c		\
			sources/cmd_check.c	\
			sources/builtins.c	\
			sources/builtins2.c	\
			sources/my_getnbr.c	\
			sources/setenv.c	\
			sources/cmd_er.c	\
			sources/redir.c		\
			sources/cd.c		\
			sources/pipe.c		\
			sources/without_space.c

OBJ             =       $(SRC:.c=.o)

all             :       title $(NAME)

title		:
			@$(ECHO) $(GREEN)42$(TEAL)sh$(DEFAULT)

$(NAME)         :       $(OBJ)
			@$(CC) -o $(NAME) $(OBJ) && \
			 $(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT)  || \
			 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME)

clean           :
			@rm -f $(OBJ)

fclean          :       clean
			@$(RM) $(NAME)

re              :        fclean all

.PHONY          :       all clean fclean re

.c.o		:
			@$(CC) $(CFLAGS) -c $< -o $@  && \
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
			$(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)
