/*
** pipe.c for pipe.c in /home/roig_a/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr 10 03:35:07 2016 Antoine Roig
** Last update Fri Jun  3 00:57:03 2016 
*/

#include		"42sh.h"

void			dad(t_plist *plist, int *ppid, char **cmd, int pid, char **env)
{
  char			*path;
  int			status;

  close(ppid[1]);
  dup2(ppid[0], 0);
  close(ppid[0]);
  waitpid(pid, &status, 0);
  if ((path = test_access(plist, cmd[0])) == NULL)
    return;
  system_fonc(plist, cmd, env);
  free(path);
  kill(pid, SIGINT);
}

void			child(t_plist *plist, int *ppid, char **cmd, char **env)
{
  char			*path;

  close(ppid[0]);
  dup2(ppid[1], 1);
  close(ppid[1]);
  if ((path = test_access(plist, cmd[0])) == NULL)
    return;
  system_fonc(plist, cmd, env);
  free(path);
}

/* int			check_pipe(t_plist *plist, char **cmd1, char **cmd2,  char **env) */
/* { */
/*   int			pid; */
/*   int			ppid[2]; */

/*   /\* if (fork() == 0) *\/ */
/*   /\*   { *\/ */
/*       pipe(ppid); */
/*       pid = fork(); */
/*       if (pid > 0) */
/*       	dad(plist, ppid, cmd1, pid, env); */
/*       else */
/*       	child(plist, ppid, cmd2, env); */
/*   /\*   } *\/ */
/*   /\* else *\/ */
/*   /\*   wait(NULL); *\/ */
/*   return (0); */
/* } */

int          my_pipe_bis(t_plist *plist, int pid1, int pipefd[2], char **cmd1, char **cmd2, char **env)
{
  int		pid2;

  if ((pid2 = fork()) == -1)
    return (-1);
  if (pid2 == 0)
    {
      close(pipefd[0]);
      if ((dup2(pipefd[1], 1)) == -1)
	return (-1);
      if (check_action(cmd1, env, plist) != 0)
	if (execve(test_access(plist, cmd1[0]), cmd1, env) == -1)
	  exit(-1);
    }
  else
    {
      close(pipefd[1]);
      if ((dup2(pipefd[0], 0)) == -1)
	return (-1);
      if (check_action(cmd2, env, plist) != 0)
	if (execve(test_access(plist, cmd2[0]), cmd2, env) == -1)
	  exit(-1);
    }
  return (0);
}
 
int             check_pipe(t_plist *plist, char **cmd1, char **cmd2, char **env)
{
  int		pid1;
  int		pipefd[2];

  if (pipe(pipefd) == -1)
    return (-1);
  if ((pid1 = fork()) == -1)
    return (-1);
  if (pid1 == 0)
    {
      if (my_pipe_bis(plist, pid1, pipefd, cmd1, cmd2, env) == -1)
	return (-1);
    }
  else
    {
      close(pipefd[0]);
      close(pipefd[1]);
      waitpid(pid1, NULL, 0);
    }
  return (0);
}
