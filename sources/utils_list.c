/*
** utils_list.c for utils_list.c in /home/roig_a/rendu/getnextline/PSU_2015_minishell1
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Fri Jan  8 00:20:39 2016 Antoine Roig
** Last update Thu May 26 12:01:50 2016 
*/

#include "42sh.h"

void	*xmalloc(int size)
{
  void	*element;

  element = malloc(size);
  if (!element)
    exit(EXIT_FAILURE);
  return (element);
}

void	new_list(t_dlist **list)
{
  (*list) = xmalloc(sizeof(t_dlist *) * 3);
  (*list)->begin = NULL;
  (*list)->end = NULL;
  (*list)->size = 0;
}

void	new_list_instruct(t_dinstructions **instruct)
{
  (*instruct) = xmalloc(sizeof(t_dinstructions *) * 3);
  (*instruct)->begin = NULL;
  (*instruct)->end = NULL;
  (*instruct)->size = 0;
}

void	clear_list(t_dlist *list)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = list->begin;
  while (tmp != NULL)
    {
      tmp2 = pop_list_begin(list);
      tmp = list->begin;
      free(tmp2->variablenv);
      if (tmp2->valuenv)
	free(tmp2->valuenv);
      free(tmp2);
    }
  free(tmp);
  free(list);
}
