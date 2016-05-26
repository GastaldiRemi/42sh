/*
** cmd_check.c for cmd_check.c in /home/roig_a/rendu/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  9 15:59:06 2016 Antoine Roig
** Last update Thu May 26 11:56:58 2016 
*/

#include "42sh.h"

int	cmd_check(t_instruct *line, pid_t pid, char **env, char **path)
{
  if (check_redir(line) == 1)
    exec_cmd_2(line, pid, env, path);
  else if (check_redir2(line) == 1)
    exec_cmd_2(line, pid, env, path);
  else if (check_redir_g(line) == -1)
    exit(0);
  else if (check_redir_g(line) == 1)
    exec_cmd_2(line, pid, env, path);
  else if (check_redir_dg(line, -1) == 1)
    exec_cmd_2(line, pid, env, path);
  else if (check_pipe(line, env, path) == 1)
    {
      free(line->cmd);
      return (0);
    }
  else
    exec_cmd_2(line, pid, env, path);
  return (0);
}
