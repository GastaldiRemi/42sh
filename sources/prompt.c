/*
** prompt.c for prompt in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri May 27 11:38:43 2016 
** Last update Wed Jun  1 16:23:04 2016 
*/

#include		"42sh.h"

void			get_user(t_plist *plist)
{
  t_list		*list;

  if (!plist)
    return ;
  list = plist->begin;
    while (list && my_strcmp(list->name, "USER") != 0)
      {
	list = list->next;
	if (list == NULL)
	  return ;
      }
  my_putstr(ROUGE);
  (list->data != NULL ? my_putstr(list->data) : (void)0);
  write(1, " ", 1);
  my_putstr(NORMAL);
}

char			*aff_prompt(t_plist *plist)
{
  char			*st;

  get_user(plist);
  my_putstr(CYANCLAIR);
  write(1, "~", 1);
  my_putstr(VERTCLAIR);
  my_putstr(get_pwd(plist));
  write(1, " ", 1);
  my_putstr(NORMAL);
  st = get_next_line(0);
  return (st);
}

char			*check_prompt(char *prompt)
{
  int			i;

  i = 0;
  if (prompt[0] == '\0')
    return (NULL);
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
      st = aff_prompt(plist);
      if (st == NULL)
      	{
      	  free_tab(env->env);
      	  return (0);
      	}
      while (check_prompt(st) == NULL)
	{
	  free(st);
	  st = aff_prompt(plist);
	}
      signal(SIGINT, SIG_DFL);
      if (pars_prompt(plist, env, st) != 0)
	{
	  free(st);
	  free_tab(env->env);
	  return (0);
      	}
      free(st);
    }
  free_tab(env->env);
  return (0);
}
