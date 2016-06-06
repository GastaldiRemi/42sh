/*
** exec_fonc.c for exec_fonc in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May 29 18:46:02 2016 
** Last update Mon Jun  6 10:46:05 2016 
*/

#include		"42sh.h"

int			system_fonc(t_plist *plist, char **cmd, char **env)
{
  char			*path;
  int			pid;
  int			status;

  status = 0;
  if (cmd == NULL || my_strlen(cmd[0]) == 0)
    return (0);
  if ((path = test_access(plist, cmd[0])) != NULL)
    {
      if (plist->pipe == 1 || (pid = fork()) == 0)
      	execve(path, cmd, env);
      else
      	{
      	  signal(SIGINT, SIG_IGN);
      	  waitpid(pid, &status, 0);
      	  signal(SIGINT, SIG_DFL);
      	}
      free(path);
      if (WIFEXITED(status) == 1)
	if (WEXITSTATUS(status))
	  return (1);
    }
  else
    {
      write(2, cmd[0], my_strlen(cmd[0]));
      write(2, ": Command not found.", 20);
      write(2, "\n", 1);
      return (1);
    }
  return (0);
}

int			init_pid(t_plist *plist, int fd)
{
  int			pid;

  close(fd);
  (plist->pipe == 0 ? pid = fork() :0);
  return (pid);
}

int			exec_fonc(t_plist *plist, char **cmd, char **env)
{
  int			fd;
  int			pid;
  int			status;

  status = 0;
  if (cmd[0] && (my_strcmp(cmd[0], "..") == 0 || my_strcmp(cmd[0], ".") == 0
		 || my_strcmp(cmd[0], "./") == 0))
    return (0);
  if ((fd = open(cmd[0], O_RDONLY)) != -1)
    {
      pid = init_pid(plist, fd);
      if (pid > 0)
      	{
	  signal(SIGINT, SIG_IGN);
	  waitpid(pid, &status, 0);
	  signal(SIGINT, SIG_DFL);
	  kill(pid, SIGINT);
      	}
      else
	execve(cmd[0], cmd, env);
      if (WIFSIGNALED(status))
	{
	  if (WTERMSIG(status) == SIGSEGV)
	    dprintf(2, "segmentation fault\n");
	}
      if (WIFEXITED(status) == 1)
	if (WEXITSTATUS(status))
	  return (1);
      signal(SIGINT, SIG_DFL);
      kill(pid, SIGINT);
    }
  else
    return (1);
  return (0);
}
