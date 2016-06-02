/*
** alias.c for alias in /home/gastal_r/rendu/42sh/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu Jun  2 01:35:59 2016 
** Last update Thu Jun  2 02:31:13 2016 
*/

#include		"42sh.h"

char			**test_alias(t_plist *plist, char *cmd)
{
  t_alias		*alias;

  alias = plist->begin_a;
  while (my_strcmp(alias->alias, cmd) != 0)
    {
      alias = alias->next;
      if (alias == NULL)
      	return (NULL);
    }
  return (alias->cmd);
}

void			add_alias(t_plist *list, char *alias, char *cmd)
{
  t_alias               *new;

  new = list->begin_a;
  if (!list)
    return;
  if ((new = malloc(sizeof(t_list))) == NULL)
    return;
  new->alias = my_strdup(alias);
  new->cmd = order_args(my_str_to_wordtab(cmd), -1, 2);
  new->prev = NULL;
  new->next = NULL;
  if (list->begin_a == NULL)
    {
      list->begin_a = new;
      list->end_a = new;
    }
  else
    {
      list->end_a->next = new;
      new->prev = list->end_a;
      list->end_a = new;
    }  
}
