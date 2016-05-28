/*
** list_fonc.c for list_fonc in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May 26 22:05:49 2016 
** Last update Sat May 28 12:12:48 2016 
*/

#include		"42sh.h"

void                    add_cmd(t_pcmd *list, char *buff)
{
  t_cmd                *new;

  if (!list)
    return;
  if ((new = malloc(sizeof(t_list))) == NULL)
    return;
  new->cmd = my_str_to_wordtab(buff);
  int i = - 1;
  while (new->cmd[++i])
    printf("==%s\n", new->cmd[i]);
  new->prev = NULL;
  new->next = NULL;
  if (list->begin == NULL)
    {
      list->begin = new;
      list->end = new;
    }
  else
    {
      list->end->next = new;
      new->prev = list->end;
      list->end = new;
    }
}
