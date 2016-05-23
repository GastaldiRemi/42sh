/*
** pop_list.c for pop_list.c in /home/roig_a/rendu/getnextline/PSU_2015_minishell1
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Fri Jan  8 00:20:24 2016 Antoine Roig
** Last update Sun Apr  3 16:48:11 2016 Antoine Roig
*/

#include "minishell2.h"

t_instructions	*pop_list_begin_inst(t_dinstructions *list)
{
  t_instructions	*tmp;

  if (!list)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (list->begin == NULL || list->end == NULL)
    return (NULL);
  tmp = list->begin;
  if (list->size == 1)
    {
      list->begin = NULL;
      list->end = NULL;
      list->size = list-> size - 1;
      return (tmp);
    }
  list->begin = tmp->next;
  tmp->next->prev = NULL;
  tmp->next = NULL;
  list->size = list-> size - 1;
  return (tmp);
}

t_list	*pop_list_begin(t_dlist *list)
{
  t_list	*tmp;

  if (!list)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (list->begin == NULL || list->end == NULL)
    return (NULL);
  tmp = list->begin;
  if (list->size == 1)
    {
      list->begin = NULL;
      list->end = NULL;
      list->size = list-> size - 1;
      return (tmp);
    }
  list->begin = tmp->next;
  tmp->next->prev = NULL;
  tmp->next = NULL;
  list->size = list-> size - 1;
  return (tmp);
}

t_list	*pop_list_end(t_dlist *list)
{
  t_list	*tmp;

  if (!list)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (list->begin == NULL || list->end == NULL)
    return (NULL);
  tmp = list->end;
  if (list->size == 1)
    {
      list->begin = NULL;
      list->end = NULL;
      list->size = list-> size - 1;
      return (tmp);
    }
  list->end = tmp->prev;
  tmp->prev->next = NULL;
  tmp->prev = NULL;
  list->size = list-> size - 1;
  return (tmp);
}

t_list  *pop_list_somewhere2(t_dlist *list, int pos)
{
  t_list        *tmp;

  tmp = list->begin;
  while (pos != 0)
    {
      tmp = tmp->next;
      pos--;
    }
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  tmp->next = NULL;
  tmp->prev = NULL;
  list->size = list->size - 1;
  return (tmp);
}

t_list  *pop_list_somewhere(t_dlist *list, int pos)
{
  if (!list)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (list->begin == NULL || list->end == NULL)
    return (NULL);
  if (pos <= 0)
    return (pop_list_begin(list));
  else if (pos + 1 == list->size || pos >= list->size)
    return (pop_list_end(list));
  else
    return (pop_list_somewhere2(list, pos));
}
