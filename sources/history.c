/*
** history.c for mysh in 
** 
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
** 
** Started on  Thu Jun  2 13:34:44 2016 Juliani Renaud
** Last update Fri Jun  3 15:21:07 2016 
*/

#include "42sh.h"

char		*check_cmd_history(t_plist *list, char *str, int i, int j)
{
  char		*str2;

  if ((str2 = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    {
      dprintf(2, "Error with malloc\n");
      return (NULL);
    }
  while (str[i] == '!')
    i++;
  while (str[i] != '\0' && ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
    i++;
  if (str[i] == '\0')
    return (str);
  else
    {
      while (str[i])
	str2[j++] = str[i++];
      str2[j] = '\0';
      cmd_to_history(list, str2);
    }
  free(str2);
  return (str);
}

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
  int			space;

  tmp = list->begin_h;
  while (tmp)
    {
      space = 0;
      if (tmp->ligne < 10)
	while (space++ < 5)
	  my_putstr(" ");
      else if (tmp->ligne < 100)
	while (space++ < 4)
	  my_putstr(" ");
      else if (tmp->ligne < 1000)
	while (space++ < 3)
	  my_putstr(" ");
      else
	while (space++ < 2)
	  my_putstr(" ");
      my_putnbr(tmp->ligne);
      my_putstr("\t");
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
