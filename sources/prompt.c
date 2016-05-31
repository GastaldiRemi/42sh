/*
** prompt.c for prompt in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri May 27 11:38:43 2016 
** Last update Tue May 31 23:51:52 2016 
*/

#include		"42sh.h"

char			*aff_prompt()
{
  char			*st;

  my_putstr("42sh ");
  st = get_next_line(0);
  return (st);
}

char			*check_prompt(char *prompt)
{
  int			i;

  i = 0;
  if (my_strlen(prompt) == 0)
    return (NULL);
  while (prompt[i])
    {
      if (prompt[i] != ' ' && prompt[i] != '\t')
	return (prompt);
      i++;
    }
  return (NULL);
}

int			prompt(t_env *env, t_plist *plist)
{
  char			*st;

  if ((env->env = init_env(env->env, plist)) == NULL)
    return (0);
  while (1)
    {
      signal(SIGINT, SIG_IGN);
      st = aff_prompt();
      if (st == NULL || st[0] == '\0')
      	{
	  (st != NULL ? free(st) : (void)0);
      	  free_env(env->env);
      	  return (0);
      	}
      while (check_prompt(st) == NULL)
	{
	  free(st);
	  st = aff_prompt();
	}
      signal(SIGINT, SIG_DFL);
      if (pars_prompt(plist, env, st) != 0)
	{
	  free(st);
	  free_env(env->env);
	  return (0);
      	}
      free(st);
    }
  free_env(env->env);
  return (0);
}
