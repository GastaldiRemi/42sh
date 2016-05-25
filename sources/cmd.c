/*
** cmd.c for cmd.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr  3 16:04:34 2016 Antoine Roig
** Last update Wed May 25 15:56:23 2016 
*/

#include "minishell2.h"

void    exec_cmd_2(t_instruct *line, int pid, char **env, char **path)
{
  int   i;
  char  *first_path_name;
  char  *pathname;
  int   ret;

  i = -1;
  while (path[++i]) /* parcours des paths  pour l'execution */
    {
      first_path_name = my_strcat(path[i], "/");
      pathname = my_strcat(first_path_name, line->cmd);
      if ((ret = access(pathname, F_OK | X_OK)) != -1 && pid == 0)
	execve(pathname, line->args, env);
    }
  if (ret == -1)
    exec_cmd_2_unknown(line->cmd); /* message d'erreur */
  if (pathname)
    free(pathname);
  signal(SIGINT, SIG_DFL);
  kill(pid, SIGINT);
}

int     exec_cmd(t_instruct *line, char **path, char **env)
{
  pid_t pid;
  int   status;

  pid = fork();
  if (pid > 0) /* père */
    {
      signal(SIGINT, SIG_IGN);
      waitpid(pid, &status, WUNTRACED);
      signal(SIGINT, SIG_DFL);
      kill(pid, SIGTERM);
    }
  else /* fils */
    cmd_check(line, pid, env, path); /* verification de s'il y a des redirs ou pipe */
  free(line->cmd);
  free_path(line->args);
  free(line);
  return (0);
}

int     exec_builtins(t_instruct *line, t_dlist *list, char **env)
{
  if (!(my_strcmp(line->cmd, "unsetenv")))
    return (builtin_unsetenv(line, list));
  else if (!(my_strcmp(line->cmd, "setenv")))
    return (builtin_setenv(line, list, env));
  else if (!(my_strcmp(line->cmd, "env")))
    return (builtin_env(env));
  else if (!(my_strcmp(line->cmd, "cd")))
    return (builtin_cd(line, list));
  else
    return (0);
}

int     exec_func(t_instruct *line, char **env)
{
  int   fd;
  int   pid;
  int   status;

  status = 0;
  if ((fd = open(line->cmd, O_RDONLY)) != -1)
    {
      pid = init_pid(fd);
      if (pid > 0)
        {
          signal(SIGINT, SIG_IGN);
          waitpid(pid, &status, 0);
          signal(SIGINT, SIG_DFL);
          kill(pid, SIGINT);
        }
      else
	execve(line->cmd, line->args, env);
      if (status == 11)
        write(2, "segmentation fault\n", my_strlen("segmentation fault\n"));
      signal(SIGINT, SIG_DFL);
      kill(pid, SIGINT);
    }
  else
    return (-1);
  return (0);
}

int     search_cmd(t_instruct *line, char **path, char **env, t_dlist *list) /* ordre de recherche des fonctions à revoir */
{
  int           built;
  int		built2;

  if (exec_func(line, env) == 0) /* recherche d'une fonction perso , genre "./mysh" */
    built2 = 1;
  else
    built2 = 0;
  built = exec_builtins(line, list, env); /* recherche des builtins */
  if (built2 == 0 && built == 0)
    exec_cmd(line, path, env); /* recherche de fonction système */
  return (0);
}
