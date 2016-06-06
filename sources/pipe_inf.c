/*
** pipe_inf.c for pipe_inf in /home/gastal_r/rendu/42sh/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sat Jun  4 22:09:08 2016 
** Last update Mon Jun  6 10:49:43 2016 
*/

#include		"42sh.h"

int			loop_pipe(t_plist *plist, int *in_out, char **cmd, char **env)
{
  pid_t			pid;

  if ((pid = fork ()) == 0)
    {
      if (in_out[0] != 0)
	{
	  dup2(in_out[0], 0);
	  close(in_out[0]);
	}
      if (in_out[1] != 1)
	{
	  dup2(in_out[1], 1);
	  close(in_out[1]);
	}
      check_exit_pipe(cmd, env, plist);
    }
  return (pid);
}

void			check_exit_pipe(char **cmd, char **env, t_plist *plist)
{
  plist->pipe = 1;
  if ((plist->exit_value = check_action(cmd, env, plist)) == 1)
    exit(1);
}

int			pipe_inf(t_plist *plist, t_cmd **cmd, int n, char **env)
{
  int			i;
  int			fd[2];
  int			in_out[2];
  int			pid;
  int			status;

  if ((pid = fork()) == 0)
    {
      in_out[0] = 0;
      i = -1;
      while (++i < n -1)
	{
	  pipe(fd);
	  in_out[1] = fd[1];
	  loop_pipe(plist, in_out, (*cmd)->cmd, env);
	  *cmd = (*cmd)->next;
	  close (fd[1]);
	  in_out[0] = fd[0];
	}
      if (in_out[0] != 0)
	dup2(in_out[0], 0);
      check_exit_pipe((*cmd)->cmd, env, plist);
    }
  else
    waitpid(pid, &status, 0);
  plist->pipe = 0;
  if (WIFEXITED(status) == 1)
    if (WEXITSTATUS(status))
      return (1);
  return (0);
}
