/*
** alias2.c for alias2
**
** Made by	Full Name
** Login	Full Name
**
** Started on	Fri Jun 03 15:05:44 2016 Full Name
** Last update	Fri Jun 03 15:19:57 2016 Full Name
*/

#include "42sh.h"

int	pop_list_alias_beg(t_plist *list)
{
  t_alias_cmd	*tmp;

  tmp = list->begin_acmd;
  list->begin_acmd = tmp->next;
  tmp->next->prev = NULL;
  tmp->next = NULL;
  list->size = list-> size - 1;
  return (1);
}

int	pop_list_alias_end(t_plist *list)
{
  t_alias_cmd	*tmp;

  tmp = list->end_acmd;
  list->end_acmd = tmp->prev;
  tmp->prev->next = NULL;
  tmp->prev = NULL;
  list->size = list-> size - 1;
  return (1);
}

int	pop_list_alias(t_plist *list, int pos)
{
  t_alias_cmd	*tmp;

  tmp = list->begin_acmd;
  if (list->size == 1)
  {
    list->begin_acmd = NULL;
    list->end_acmd = NULL;
    list->size = 0;
    return (0);
  }
  if (pos == 0)
    return(pop_list_alias_beg(list));
  if (pos + 1 == list->size)
    return (pop_list_alias_end(list));
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
  return (0);
}

void	pop_alias_cmd(char **tab, t_plist *list)
{
  t_alias_cmd *tmp;
  int i;

  i = 0;
  tmp = list->begin_acmd;
  while (tmp)
  {
      if (my_strcmp(tmp->alias, tab[1]) == 0)
      {
        pop_list_alias(list, i);
        return;
      }
      i++;
      tmp = tmp->next;
  }
}

int	check_exist(t_plist *list, char *alias, char *cmd)
{
  t_alias_cmd *tmp;

  tmp = list->begin_acmd;
  while (tmp)
  {
    if (my_strcmp(tmp->alias, alias) == 0)
    {
      tmp->cmd = order_args(my_str_to_wordtab(cmd), -1, 2);
      return (1);
    }
    tmp = tmp->next;
  }
  return (0);
}
