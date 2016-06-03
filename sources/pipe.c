/*
** pipe.c for pipe.c in /home/roig_a/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr 10 03:35:07 2016 Antoine Roig
** Last update Fri Jun  3 16:42:58 2016 
*/

#include		"42sh.h"

int			check_action_pipe(t_plist *envlist, char **tab, char **env)
{
  if (test_alias(envlist, tab[0]) != NULL)
    envlist->exit_value = system_fonc_pipe(envlist, test_alias(envlist, tab[0]), env);
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
    envlist->exit_value = red_left(tab);
  else if (my_strcmp(tab[0], "<<") == 0)
    envlist->exit_value = double_red_left(envlist, tab, env);
  else if (my_strcmp(tab[0], "alias") == 0)
    add_alias_cmd(tab, envlist);
  else if ((envlist->exit_value = exec_fonc_pipe(tab, env)) == 1)
    envlist->exit_value = system_fonc_pipe(envlist, tab, env);
  return (envlist->exit_value);
}

int          my_pipe_bis(t_plist *plist, char **cmd1, char **cmd2, char **env)
{
  int		pid2;
  int		pipefd[2];

  if (pipe(pipefd) == -1)
    return (-1);
  if ((pid2 = fork()) == 0)
    {
      close(pipefd[0]);
      if ((dup2(pipefd[1], 1)) == -1)
	return (-1);
      check_action_pipe(plist, cmd1, env);
      close(pipefd[1]);
    }
  else if (pid2 > 0)
    {
      close(pipefd[1]);
      if ((dup2(pipefd[0], 0)) == -1)
	return (-1);
      check_action_pipe(plist, cmd2, env);
      close(pipefd[0]);
    }
  return (0);
}

int             my_pipe(t_plist *plist, char **cmd1, char **cmd2, char **env)
{
  int		pid1;

  if ((pid1 = fork()) == 0)
    {
      if (my_pipe_bis(plist, cmd1, cmd2, env) == -1)
	return (1);
    }
  else if (pid1 > 0)
    waitpid(pid1, NULL, 0);
  return (0);
}
