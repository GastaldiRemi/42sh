/*
** history.c for mysh in 
** 
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
** 
** Started on  Thu Jun  2 13:34:44 2016 Juliani Renaud
** Last update Thu Jun  2 13:57:55 2016 Juliani Renaud
*/

#include "42sh.h"

void                    cmd_to_history(t_plist *list, char *cmd)
{
  t_history		*new;

  if (!list)
    return;
  if ((new = malloc(sizeof(t_list))) == NULL)
    return;
  new->prev = NULL;
  new->next = NULL;
  if (list->begin_h == NULL)
    {
      new->cmd = my_strdup(cmd);
      list->begin_h = new;
      list->end_h = new;
    }
  else
    {
      new->cmd = my_strdup(cmd);
      new->prev = list->end_h;
      list->end_h->next = new;
      list->end_h = new;
    }
}

void			show_history(t_plist *list)
{
  t_history		*tmp;

  tmp = list->begin_h;
  while (tmp)
    {
      my_putstr(tmp->cmd);
      my_putstr("\n");
      tmp = tmp->next;
    }
}

void			clear_history(t_plist *list)
{
  t_history		*tmp;

  while ((tmp = list->begin_h) != NULL)
    {
      list->begin_h = list->begin_h->next;
      free(tmp->cmd);
      free(tmp);
    }
}
