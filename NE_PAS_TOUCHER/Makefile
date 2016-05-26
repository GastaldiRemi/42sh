##
## Makefile for Makefile in /home/roig_a/PSU_2015_minishell2
## 
## Made by Antoine Roig
## Login   <roig_a@epitech.net>
## 
## Started on  Sun Apr 10 05:14:49 2016 Antoine Roig
## Last update Fri May 27 00:55:47 2016 
##

ECHO            =       /bin/echo -e
DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[0;31m"

CC              =       gcc -g3

NAME            =       42sh

CFLAGS          =       -Wextra -Wall -W -pedantic -Iinclude

SRC             =       sources/main.c			\
			sources/get_next_line.c		\
			sources/list_fonc.c		\
			sources/env_list_fonc.c		\
			sources/utils.c

OBJ             =       $(SRC:.c=.o)

all             :       title $(NAME)

title:
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

