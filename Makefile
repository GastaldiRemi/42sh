##
## Makefile for Makefile in /home/roig_a/PSU_2015_minishell2
## 
## Made by Antoine Roig
## Login   <roig_a@epitech.net>
## 
## Started on  Sun Apr 10 05:14:49 2016 Antoine Roig
## Last update Tue May 24 17:37:06 2016 Jabbari Yassir
##

CC              =       gcc

NAME            =       42sh

CFLAGS          =       -Wextra -Wall -W -pedantic -Iinclude

SRC             =       sources/main.c		\
			sources/env.c		\
			sources/add_list.c	\
			sources/pop_list.c	\
			sources/utils_list.c	\
			sources/utils2.c	\
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

all             :       $(NAME)

$(NAME)         :       $(OBJ)
			$(CC) -o $(NAME) $(OBJ)

clean           :
			rm -f $(OBJ)

fclean          :       clean
			$(RM) $(NAME)

re              :        fclean all

.PHONY          :       all clean fclean re

