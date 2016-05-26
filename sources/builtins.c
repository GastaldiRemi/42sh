/*
** buitins.c for builtins.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr  3 16:20:42 2016 Antoine Roig
** Last update Thu May 26 11:56:11 2016 
*/

#include "42sh.h"

t_ret	*builtin_exit(t_instruct *line, t_ret *reti)
{
  int ret;

  reti->ex = 1;
  my_putstr("exit\n");
  if (line->args[1])
    {
      ret = my_getnbr(line->args[1]);
      reti->ret = ret;
      return (reti);
    }
  else
    {
      reti->ret = 0;
      return (reti);
    }
}

int     builtin_setenv(t_instruct *line, t_dlist *list, char **env)
{
  int   i;

  i = 0;
  while (line->args[i])
    i++;
  if (i == 1)
    {
      my_show_wordtab(env);
      return (1);
    }
  if (check_variable(line->args[1], line->args[2], list) == 1)
    return (1);
  else if (line->args[1] && line->args[2] == NULL)
    {
      add_list_end(list, line->args[1], "");
      return (1);
    }
  else if (line->args[1] && line->args[2])
    {
      add_list_end(list, line->args[1], line->args[2]);
      return (1);
    }
  return (0);
}

int     builtin_unsetenv(t_instruct *line, t_dlist *list)
{
  list = unset_env(line, list);
  return (1);
}

int     builtin_env(char **env)
{
  my_show_wordtab(env);
  return (1);
}

int     builtin_cd(t_instruct *line, t_dlist *list)
{
  int   i;
  char  *user;

  i = -1;
  while (line->args[++i]);
  if (i == 1)
    {
      user = get_user(list);
      if (user == NULL || user[0] == '\0')
        my_putstr("cd: Can't change to home directory\n");
      else if (chdir(user) != -1)
        return (just_cd(list));
      else
        just_cd_error();
    }
  else if (line->args[1][0] == '-')
    return (go_old(list));
  else if (line->args[1] && open(line->args[1], O_RDONLY) != -1)
    {
      if (chdir(line->args[1]) != -1)
        return (change_pwd(list));
    }
  else
    cd_error(line);
  return (1);
}
