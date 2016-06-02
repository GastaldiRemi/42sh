/*
** history.c for mysh in 
** 
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
** 
** Started on  Thu Jun  2 13:34:44 2016 Juliani Renaud
** Last update Thu Jun  2 14:20:40 2016 Juliani Renaud
*/

#include "42sh.h"

void                    cmd_to_history(t_plist *list, char *cmd)
{
  t_history		*new;
  static int		i = 1;

  if (!list)
    return;
  if ((new = malloc(sizeof(t_list))) == NULL)
    return;
  new->prev = NULL;
  new->next = NULL;
  if (list->begin_h == NULL)
    {
      new->cmd = my_strdup(cmd);
      new->ligne = i;
      list->begin_h = new;
      list->end_h = new;
    }
  else
    {
      new->ligne = i;
      new->cmd = my_strdup(cmd);
      new->prev = list->end_h;
      list->end_h->next = new;
      list->end_h = new;
    }
  i++;
}

void			show_history(t_plist *list)
{
  t_history		*tmp;

  tmp = list->begin_h;
  while (tmp)
    {
      my_putstr("\t");
      my_putnbr(tmp->ligne);
      my_putstr(" ");
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