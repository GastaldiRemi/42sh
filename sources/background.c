/*
** background.c for background in /home/gastal_r/rendu/42sh/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu Jun  2 10:46:58 2016 
** Last update Sun Jun  5 22:50:29 2016 
*/

#include		"42sh.h"

int			background(t_plist *plist, char **cmd, char **env)
{
  char                  *path;
  int                   pid;

  if (cmd == NULL || my_strlen(cmd[0]) == 0)
    return (0);
  if ((path = test_access(plist, cmd[0])) != NULL)
    {
      if ((pid = vfork()) == 0)
      	{
      	  setpgid(pid, 0);
      	  execve(path, cmd, env);
      	}
      free(path);
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
