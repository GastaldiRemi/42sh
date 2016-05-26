/*
** my_strlen.c for my_strlen.c in /home/roig_a/rendu/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  2 12:42:02 2016 Antoine Roig
** Last update Thu May 26 11:59:45 2016 
*/

#include "42sh.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
