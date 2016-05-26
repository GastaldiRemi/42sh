/*
** pipe.c for pipe.c in /home/roig_a/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr 10 03:35:07 2016 Antoine Roig
** Last update Thu May 26 12:00:20 2016 
*/

#include "42sh.h"

void	dad(int *ppid, t_instruct *line, t_path s_path, int pid)
{
  char  *first_path_name;
  char  *pathname;
  int	j;
  int	ret;
  int	status;

  close(ppid[1]);
  dup2(ppid[0], 0);
  close(ppid[0]);
  waitpid(pid, &status, 0);
  line->args = (char **)(line->args + (s_path.i + 1));
  j = -1;
  while (s_path.path[++j])
    {
      first_path_name = my_strcat(s_path.path[j], "/");
      pathname = my_strcat(first_path_name, line->args[0]);
      if ((ret = access(pathname, F_OK | X_OK)) != -1)
	execve(pathname, line->args, s_path.env);
    }
  if (ret == -1)
    exec_cmd_2_unknown(line->args[0]);
  if (pathname)
    free(pathname);
  kill(pid, SIGINT);
}

void	child(int *ppid, t_instruct *line, t_path s_path)
{
  int   ret;
  char  *first_path_name;
  char  *pathname;

  line->args[s_path.i] = NULL;
  close(ppid[0]);
  dup2(ppid[1], 1);
  close(ppid[1]);
  s_path.i = -1;
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

int	check_pipe(t_instruct *line,  char **env, char **path)
{
  int	i;
  int	pid;
  int	ppid[2];
  t_path	s_path;

  s_path.env = env;
  s_path.path = path;
  i = 0;
  while (line->args[i])
    {
      if (line->args[i][0] == '|' && line->args[i][1] == '\0')
	{
	  pipe(ppid);
	  pid = fork();
	  s_path.i = i;
	  if (pid > 0)
	    dad(ppid, line, s_path, pid);
	  else
	    child(ppid, line, s_path);
	  return (1);
	}
      i++;
    }
  return (0);
}
