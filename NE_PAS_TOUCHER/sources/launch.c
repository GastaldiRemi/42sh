/*
** launch.c for 42 in 
** 
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
** 
** Started on  Sat May 28 16:01:27 2016 Juliani Renaud
** Last update Mon May 30 16:01:40 2016 
*/

#include	"42sh.h"

int		check_action(char **tab, char **env, t_plist *envlist)
{
  if (my_strcmp(tab[0], "setenv") == 0)
    return (set_env(envlist, tab));
  else if (my_strcmp(tab[0], "unsetenv") == 0)
    return (unset_env(envlist, tab));
  else if (my_strcmp(tab[0], "cd") == 0)
    return (cd_main(envlist, tab));
  else if (my_strcmp(tab[0], ">") == 0)
    return (red_right(envlist, tab, env));
  else if (my_strcmp(tab[0], ">>") == 0)
    return (double_red_right(envlist, tab, env));
  else if (my_strcmp(tab[0], "<") == 0)
    return (red_left(envlist, tab ,env));
  else if (my_strcmp(tab[0], "<<") == 0)
    return (double_red_left(envlist, tab, env));
  else
    return (system_fonc(envlist, tab, env));
  return (1);
}

char		*check_exit(char **tab)
{
  if (my_strcmp(tab[0], "exit") == 0)
    {
      if (tab[1] != NULL)
	return (tab[1]);
      else
	return ("OK");
    }
  return ("FAIL");
}

char		*launch(char **env, t_plist *envlist, t_pcmd *cmd, t_psep *sep)
{
  t_cmd		*tmp;
  char		*acces;
  int		i;

  tmp = cmd->begin;
  while (tmp)
    {
      if (my_strcmp(check_exit(tmp->cmd), "FAIL") != 0)
	{
	  if (tmp->cmd[1] != NULL)
	    return (tmp->cmd[1]);
	  else
	    return ("0");
	}
      i = check_action(tmp->cmd, env, envlist);
      env = init_env(env, envlist);
      tmp = tmp->next;
    }
  return (NULL);
}
