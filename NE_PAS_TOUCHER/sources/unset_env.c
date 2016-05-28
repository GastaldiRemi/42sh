/*
** unset_env.c for 42sh in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sat May 28 22:44:19 2016 
** Last update Sat May 28 23:04:50 2016 
*/

#include		"42sh.h"

int			unset_env(t_plist *plist, char **cmd)
{
  t_list		*list;
  t_list		*tmp;
  
  list = plist->begin;
  if (cmd[1] == NULL)
    return (0);
  while (my_strcmp(list->name, cmd[1]) != 0)
    {
      if (list->next == NULL)
        return (0);
      list = list->next;
    }
  tmp = list;
  tmp->next->prev = tmp->prev;
  tmp->prev->next = tmp->next;
  free(list->name);
  free(list->data);
  free(list);
  list = tmp;
  return (0);
}
