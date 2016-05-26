/*
** list_fonc.c for list_fonc in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May 26 22:05:49 2016 
** Last update Fri May 27 00:56:05 2016 
*/

#include		"42sh.h"

/*   void			list_to_env(t_plist *list, char *name, char *data) */
/* { */
/*   t_list		*new; */

/*   if (!list) */
/*     return; */
/*   if ((new = malloc(sizeof(t_list))) == NULL) */
/*     return; */
/*   new->name = name; */
/*   new->data = data; */
/*   new->prev = NULL; */
/*   new->next = NULL; */
/*   if (list->begin == NULL) */
/*     { */
/*       list->begin = new; */
/*       pars_env_line(new,  */
/*       list->end = new; */
/*     } */
/*   else */
/*     { */
/*       list->end->next = new; */
/*       new->prev = list->end; */
/*       list->end = new; */
/*     } */
/* } */


void    clear_list(t_plist *list)
{
  t_list        *tmp;

  while ((tmp = list->begin) != NULL)
    {
      list->begin = list->begin->next;
      free(tmp->name);
      if (tmp->data)
      	free(tmp->data);
      free(tmp);
    }
  free(list);
}
