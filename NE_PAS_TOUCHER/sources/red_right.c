/*
** red_right.c for red_right in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May 29 17:59:32 2016 
** Last update Sun May 29 18:56:59 2016 
*/

#include		"42sh.h"

void			red_right(t_plist *plist, char **cmd, char **env)
{
  int			out;
  int			pid;
  char			*path;

  out = open(cmd[0], O_WRONLY | O_TRUNC | O_CREAT, 0666);
  cmd += 1;
  if ((pid = fork()) == 0)
    {
      if ((path = test_access(plist, cmd[0])) == NULL)
	kill(getpid(), SIGKILL);
      dup2(out, 1);
      execve(path, cmd,  env);
      free(path);
    }
  else
    wait(NULL);
  close(out);
}

void			double_red_right(t_plist *plist, char **cmd, char **env)
{
  int			out;
  int			pid;
  char			*path;

  out = open(cmd[0], O_WRONLY | O_APPEND | O_CREAT, 0666);
  cmd += 1;
  if ((pid = fork()) == 0)
    {
      if ((path = test_access(plist, cmd[0])) == NULL)
	kill(getpid(), SIGKILL);
      dup2(out, 1);
      execve(path, cmd,  env);
      free(path);
    }
  else
    wait(NULL);
  close(out);
}
