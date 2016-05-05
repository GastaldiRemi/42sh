/*
** add_list.c for add_list.c in /home/roig_a/rendu/getnextline/PSU_2015_minishell1
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Fri Jan  8 00:20:12 2016 Antoine Roig
** Last update Thu May  5 10:12:44 2016 Jabbari Yassir
*/

#include "minishell2.h"

void    add_list_end(t_dlist *list, char *variable, char *value)
{
  t_list        *new;

  if (!list)
    return;
  new = xmalloc(sizeof(*new));
  new->variablenv = variable;
  new->valuenv = value;
  new->next = NULL;
  new->prev = NULL;
  if (list->begin == NULL)
    {
      list->begin = new;
      list->end = new;
      list->size = 1;
    }
  else
    {
      new->prev = list->end;
      list->end->next = new;
      list->end = new;
      list->size = list->size + 1;
    }
}

void	add_list_end_inst(t_dinstructions *list_instruct, t_instruct *instru)
{
  t_instructions        *new;

  if (!list_instruct)
    return;
  new = xmalloc(sizeof(*new));
  new->inst = instru;
  new->next = NULL;
  new->prev = NULL;
  if (list_instruct->begin == NULL)
    {
      list_instruct->begin = new;
      list_instruct->end = new;
      list_instruct->size = 1;
    }
  else
    {
      new->prev = list_instruct->end;
      list_instruct->end->next = new;
      list_instruct->end = new;
      list_instruct->size = list_instruct->size + 1;
    }
}
