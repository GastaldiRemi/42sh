/*
** launch.c for 42 in
**
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
**
** Started on  Sat May 28 16:01:27 2016 Juliani Renaud
** Last update Wed Jun  1 17:28:55 2016 
*/

#include	"42sh.h"

int		check_action(char **tab, char **env, t_plist *envlist)
{
  if (my_strcmp(tab[0], "env") == 0)
    envlist->exit_value = show_list(envlist);
  else if (my_strcmp(tab[0], "setenv") == 0)
    envlist->exit_value = set_env(envlist, tab);
  else if (my_strcmp(tab[0], "unsetenv") == 0)
    envlist->exit_value = unset_env(envlist, tab);
  else if (my_strcmp(tab[0], "cd") == 0)
    envlist->exit_value = cd_main(envlist, tab);
  else if (my_strcmp(tab[0], "echo") == 0)
    envlist->exit_value = echo(tab);
  else if (my_strcmp(tab[0], ">") == 0)
    envlist->exit_value = red_right(envlist, tab, env);
  else if (my_strcmp(tab[0], ">>") == 0)
    envlist->exit_value = double_red_right(envlist, tab, env);
  else if (my_strcmp(tab[0], "<") == 0)
    envlist->exit_value = red_left(tab);
  else if (my_strcmp(tab[0], "<<") == 0)
    envlist->exit_value = double_red_left(envlist, tab, env);
  else if ((envlist->exit_value = exec_fonc(tab, env)) == 1)
    envlist->exit_value = system_fonc(envlist, tab, env);
  return (envlist->exit_value);
}

void		move_tmp(t_cmd **tmp, int i, t_sep **sep)
{
  if (!(*sep))
    {
      (*tmp) = (*tmp)->next;
      return;
    }
  if (my_strcmp((*sep)->sep, "&&") == 0)
    {
      (*tmp) = (*tmp)->next;
      if (i == 0)
	return;
      else if ((*tmp) && i != 0)
	(*tmp) = (*tmp)->next;
    }
  else if (my_strcmp((*sep)->sep, "||") == 0)
    {
      (*tmp) = (*tmp)->next;
      if ((*tmp) && i == 0)
	(*tmp) = (*tmp)->next;
      else
	return;
    }
  else
    (*tmp) = (*tmp)->next;
  (*sep) = (*sep)->next;
  return;
}

int		exit_end(t_plist *list, int i)
{
  list->exit_value = i;
  return (-1);
}

int		launch(t_env *env, t_plist *envlist, t_pcmd *cmd, t_psep *sep)
{
  t_sep		*tmp_sep;
  t_cmd		*tmp;
  int		i;

  tmp = cmd->begin;
  tmp_sep = sep->begin;
  while (tmp)
    {
      if (my_strcmp(tmp->cmd[0], "exit") == 0)
	{
	  my_putstr("exit\n");
	  if (tmp->cmd[1] != NULL && tmp->cmd[1][0] >= '0'
	      && tmp->cmd[1][0] <= '9')
	    return (exit_end(envlist, my_getnbr(tmp->cmd[1])));
	  else
	    return (exit_end(envlist, 1));
	}
      i = check_action(tmp->cmd, env->env, envlist);
      move_tmp(&tmp, i, &tmp_sep);
      env->env = init_env(env->env, envlist);
    }
  return (0);
}
