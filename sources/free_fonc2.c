/*
** free_fonc2.c for free_fonc2 in /home/gastal_r/rendu/42sh/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri Jun  3 17:25:17 2016 
** Last update Fri Jun  3 17:38:46 2016 
*/

#include		"42sh.h"

void                    free_alias_cmd(t_plist *list)
{
  t_alias_cmd           *tmp;

  while ((tmp = list->begin_acmd) != NULL)
    {
      list->begin_acmd = list->begin_acmd->next;
      free(tmp->alias);
      if (tmp->cmd)
	free(tmp->cmd);
      free(tmp->cmd);
      free(tmp);
    }
}
