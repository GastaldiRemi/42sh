/*
** main.c for 42sh in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May 26 21:45:20 2016 
** Last update Fri May 27 00:58:25 2016 
*/

#include		"42sh.h"

void			free_fonc(char **env, t_plist *plist, t_list *list)
{
  int			i;

  i = -1;
  while (env[++i])
    free(env[i]);
  free(list);
  clear_list(plist);
}

int			init_list(t_plist **plist, t_list **list)
{
  if ((*list = malloc(sizeof(t_list))) == NULL)
    return (-1);
  if ((*plist = malloc(sizeof(t_plist))) == NULL)
    return (-1);
  (*plist)->end = NULL;
  (*plist)->begin = NULL;
  return (0);
}

int			main(int ac, char **av, char **env)
{
  int			i;
  t_plist		*plist;
  t_list		*list;
  char			**my_env;
  int			exit_value;

  (void)ac;
  (void)av;
  if (env[0] == NULL)
    return (0);
  if (init_list(&plist, &list) == -1)
    return (0);
  i = -1;
  while (env[++i] != NULL)
    env_to_list(plist, env[i]);
  if ((my_env = list_to_env(plist->begin, plist->begin)) == NULL)
    return (0);
  /* exit = my_getnbr(prompt(my_env, env, list)); */
  free_fonc(my_env, plist, list);
  exit_value = 0;
  return (exit_value);
}