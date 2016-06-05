/*
** launch.c for 42 in
**
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
**
** Started on  Sat May 28 16:01:27 2016 Juliani Renaud
** Last update	Fri Jun 03 14:15:54 2016 Full Name
*/

#include	"42sh.h"

int		check_action(char **tab, char **env, t_plist *envlist)
{
  if (test_alias(envlist, tab[0]) != NULL)
    envlist->exit_value = system_fonc(envlist, test_alias(envlist, tab[0]), env);
  else if (tab[1] != NULL && my_strcmp(tab[0], "history") == 0
	   && my_strcmp(tab[1], "-c") == 0)
    clear_history_c(envlist);
  else if (my_strcmp(tab[0], "history") == 0)
    show_history(envlist);
  else if (my_strcmp(tab[0], "env") == 0)
    envlist->exit_value = show_list(envlist);
  else if (my_strcmp(tab[0], "setenv") == 0)
    envlist->exit_value = set_env(envlist, tab);
  else if (my_strcmp(tab[0], "unsetenv") == 0)
    envlist->exit_value = unset_env(envlist, tab);
  else if (my_strcmp(tab[0], "cd") == 0)
    envlist->exit_value = cd_main(envlist, tab);
  else if (my_strcmp(tab[0], "echo") == 0)
    envlist->exit_value = echo(tab, envlist->begin);
  else if (my_strcmp(tab[0], ">") == 0)
    envlist->exit_value = red_right(envlist, tab, env);
  else if (my_strcmp(tab[0], ">>") == 0)
    envlist->exit_value = double_red_right(envlist, tab, env);
  else if (my_strcmp(tab[0], "<") == 0)
    envlist->exit_value = red_left(envlist, tab, env);
  else if (my_strcmp(tab[0], "<<") == 0)
    envlist->exit_value = double_red_left(envlist, tab, env);
  else if (my_strcmp(tab[0], "alias") == 0)
    add_alias_cmd(tab, envlist);
  else if (my_strcmp(tab[0], "unalias") == 0)
    pop_alias_cmd(tab, envlist);
  else if ((envlist->exit_value = exec_fonc(envlist, tab, env)) == 1)
    envlist->exit_value = system_fonc(envlist, tab, env);
  envlist->pipe == 1 ? kill(getpid(), SIGINT) : 0;
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
  else if (*tmp)
    (*tmp) = (*tmp)->next;
  (*sep) = (*sep)->next;
  return;
}

int		exit_end(t_plist *list, int i)
{
  list->exit_value = i;
  return (-1);
}

int		count_pipe(t_sep **sep)
{
  int		i;

  i = 0;
  while ((*sep) && my_strcmp((*sep)->sep, "|") == 0)
    {
      i++;
      (*sep) = (*sep)->next;
    }
  return (i);
}

int		check_nb_arg(int nb_pipe, t_cmd *cmd)
{
  int		i;
  t_cmd		*tmp;

  i = 0;
  tmp = cmd;
  while ((i < (nb_pipe + 1)) && tmp)
    {
      tmp = tmp->next;
      i++;
    }
  if (i == (nb_pipe + 1))
    return (0);
  else
    return (1);
}

int		launch(t_env *env, t_plist *envlist, t_pcmd *cmd, t_psep *sep)
{
  t_sep		*tmp_sep;
  t_cmd		*tmp;
  int		i;
  int		nb_pipe;

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
      else if (tmp_sep != NULL && my_strcmp(tmp_sep->sep, "|") == 0)
	{
	  if (tmp->next == NULL)
	    {
	      dprintf(2, "Invalid null command.\n");
	      return (0);
	    }
	}
      else if (tmp_sep != NULL && tmp->next != NULL && my_strcmp(tmp_sep->sep, "|") == 0)
      	{
	  envlist->pipe = 1;
	  nb_pipe = count_pipe(&tmp_sep);
	  if ((check_nb_arg(nb_pipe, tmp)) == 1)
	    {
	      dprintf(2, "Invalid null command.\n");
	      return (0);
	    }
	  pipe_inf(envlist, &tmp, nb_pipe + 1, env->env);
	  tmp = tmp->next;
      	}
      else if (tmp_sep != NULL && my_strcmp(tmp_sep->sep, "&") == 0)
	background(envlist, tmp->cmd, env->env);
      else
	i = check_action(tmp->cmd, env->env, envlist);
      move_tmp(&tmp, i, &tmp_sep);
      env->env = init_env(env->env, envlist);
    }
  return (0);
}
