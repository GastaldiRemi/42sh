/*
** launch.c for 42 in 
** 
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
** 
** Started on  Sat May 28 16:01:27 2016 Juliani Renaud
** Last update Mon May 30 23:51:34 2016 
*/

#include	"42sh.h"

int		check_action(char **tab, char **env, t_plist *envlist)
{
  if (my_strcmp(tab[0], "env") == 0)
    return (show_list(envlist));
  else if (my_strcmp(tab[0], "setenv") == 0)
    return (set_env(envlist, tab));
  else if (my_strcmp(tab[0], "unsetenv") == 0)
    return (unset_env(envlist, tab));
  else if (my_strcmp(tab[0], "cd") == 0)
    return (cd_main(envlist, tab));
  else if (my_strcmp(tab[0], ">") == 0)
    return (red_right(envlist, tab, env));
  else if (my_strcmp(tab[0], ">>") == 0)
    return (double_red_right(envlist, tab, env));
  else if (my_strcmp(tab[0], "<") == 0)
    return (red_left(tab));
  else if (my_strcmp(tab[0], "<<") == 0)
    return (double_red_left(envlist, tab, env));
  else if (exec_fonc(tab, env) == -1)
    return (system_fonc(envlist, tab, env));
  return (-1);
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
      if (i == 1)
	return;
      else if ((*tmp)->next && i != 1)
	(*tmp) = (*tmp)->next;
    }
  else if (my_strcmp((*sep)->sep, "||") == 0)
    {
      (*tmp) = (*tmp)->next;
      if ((*tmp)->next && i == 1)
	(*tmp) = (*tmp)->next;
      else
	return;
    }
  else
    (*tmp) = (*tmp)->next;
  (*sep) = (*sep)->next;
  return;
}

char		*launch(t_env *env, t_plist *envlist, t_pcmd *cmd, t_psep *sep)
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
	  if (tmp->cmd[1] != NULL && tmp->cmd[1][0] >= '0'
	      && tmp->cmd[1][0] <= '9')
	    return (tmp->cmd[1]);
	  else
	    return ("1");
	}
      i = check_action(tmp->cmd, env->env, envlist);
      move_tmp(&tmp, i, &tmp_sep);
      env->env = init_env(env->env, envlist);
    }
  return (NULL);
}
