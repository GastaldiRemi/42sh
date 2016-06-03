/*
** pipe.c for pipe.c in /home/roig_a/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr 10 03:35:07 2016 Antoine Roig
** Last update Fri Jun  3 22:53:09 2016 
*/

#include		"42sh.h"

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
      check_action(cmd1, env, plist);
      close(pipefd[1]);
    }
  else if (pid2 > 0)
    {
      close(pipefd[1]);
      if ((dup2(pipefd[0], 0)) == -1)
	return (-1);
      check_action(cmd2, env, plist);
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
  plist->pipe = 0;
  return (0);
}
