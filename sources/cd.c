/*
** cd.c for cd.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr  3 16:44:33 2016 Antoine Roig
** Last update Thu May 26 11:56:23 2016 
*/

#include "42sh.h"

void    go_old_2(t_dlist *list, char *old_pwd)
{
  t_list        *tmp;

  tmp = list->begin;
  while (tmp)
    {
      if (!(my_strcmp(tmp->variablenv, "PWD")))
        tmp->valuenv = old_pwd;
      tmp = tmp->next;
    }
}

int     go_old(t_dlist *list)
{
  char           *pwd;
  t_list        *tmp;
  char            *old_pwd;

  old_pwd = NULL;
  tmp = list->begin;
  while (tmp)
    {
      if (!(my_strcmp(tmp->variablenv, "PWD")))
        pwd = tmp->valuenv;
      if (!(my_strcmp(tmp->variablenv, "OLDPWD")))
        {
          old_pwd = tmp->valuenv;
          tmp->valuenv = pwd;
        }
      tmp = tmp->next;
    }
  if (chdir(old_pwd) == -1)
    return (my_putstr("cd: OLDPWD not set.\n"));
  go_old_2(list, old_pwd);
  return (1);
}

int     just_cd(t_dlist *list)
{
  return (change_pwd(list));
}

void    just_cd_error()
{
  my_putstr("cd: Can't change to home directory\n");
}

void    cd_error(t_instruct *line)
{
  write(1, line->args[1], my_strlen(line->args[1]));
  my_putstr(": No such file or directory.\n");
}
