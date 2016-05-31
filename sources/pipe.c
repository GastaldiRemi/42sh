/*
** pipe.c for pipe.c in /home/roig_a/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr 10 03:35:07 2016 Antoine Roig
** Last update Tue May 31 14:55:48 2016 
*/

#include		"42sh.h"

void			dad(int *ppid, , int pid, char **cmd)
{
  char			*first_path_name;
  char			*path;
  int			j;
  int			ret;
  int			status;

  close(ppid[1]);
  dup2(ppid[0], 0);
  close(ppid[0]);
  waitpid(pid, &status, 0);
  if ((path = test_access(plist, cmd[0])) != NULL)
    execve(path, cmd, s_path.env);
  if (ret == -1)
    exec_cmd_2_unknown(line->args[0]);
  if (pathname)
    free(pathname);
  kill(pid, SIGINT);
}

void			child(int *ppid, )
{
  int			ret;
  char			*first_path_name;
  char			*pathname;

  close(ppid[0]);
  dup2(ppid[1], 1);
  close(ppid[1]);
  while (s_path.path[++s_path.i])
    {
      first_path_name = my_strcat(s_path.path[s_path.i], "/");
      pathname = my_strcat(first_path_name, line->args[0]);
      if ((ret = access(pathname, F_OK | X_OK)) != -1)
	execve(pathname, line->args, s_path.env);
    }
  if (ret == -1)
    exec_cmd_2_unknown(line->args[0]);
  if (pathname)
    free(pathname);
}

int			check_pipe(t_env *env, char **cmd)
{
  int			i;
  int			pid;
  int			ppid[2];

  pipe(ppid);
  pid = fork();
  s_path.i = i;
  if (pid > 0)
    dad(ppid, pid, cmd);
  else
    child(ppid, line, s_path);
  return (1);
}
