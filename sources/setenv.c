/*
** setenv.c for setenv.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr  3 16:40:42 2016 Antoine Roig
** Last update Thu May 26 12:01:10 2016 
*/

#include "42sh.h"

int     check_variable(char *variable, char *value, t_dlist *list)
{
  t_list        *tmp;

  tmp = list->begin;
  if (value == NULL)
    value = "";
  while (tmp)
    {
      if (!(my_strcmp(variable, tmp->variablenv)))
        {
          tmp->valuenv = value;
          return (1);
        }
      tmp = tmp->next;
    }
  return (0);
}
