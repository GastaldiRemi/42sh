/*
** builtins.2.c for builtins2.c in /home/roig_a/rendu/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr  3 16:28:15 2016 Antoine Roig
** Last update Thu Apr  7 14:57:27 2016 Antoine Roig
*/

#include "minishell2.h"

int     change_pwd2(char *buff, t_dlist *list)
{
  t_list        *tmp;
  char          *pwd;

  tmp = list->begin;
  while (tmp)
    {
      if (!(my_strcmp(tmp->variablenv, "PWD")))
        {
          pwd = tmp->valuenv;
          tmp->valuenv = buff;
        }
      if (!(my_strcmp(tmp->variablenv, "OLDPWD")))
        tmp->valuenv = pwd;
      tmp = tmp->next;
    }
  return (1);
}

int     change_pwd(t_dlist *list)
{
  char          *buff;
  int           i;
  char          *ptr;

  i = 1;
  buff = NULL;
  while (buff == NULL)
    {
      buff = xmalloc(sizeof(char) * (SIZE_PWD * i));
      ptr = buff;
      buff = getcwd(buff, SIZE_PWD * i + 1);
      if (buff == NULL)
        free(ptr);
      i++;
    }
  return (change_pwd2(buff, list));
}

char    *get_user(t_dlist *list)
{
  t_list        *tmp;
  char          *user;

  tmp = list->begin;
  user = NULL;
  while (tmp)
    {
      if (!(my_strcmp(tmp->variablenv, "HOME")))
        {
          user = tmp->valuenv;
          break;
        }
      tmp = tmp->next;
    }
  return (user);
}
