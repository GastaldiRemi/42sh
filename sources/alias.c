/*
** alias.c for alias in /home/gastal_r/rendu/42sh/sources
**
** Made by
** Login   <gastal_r@epitech.net>
**
** Started on  Thu Jun  2 01:35:59 2016
** Last update	Fri Jun 03 15:04:17 2016 Full Name
*/

#include		"42sh.h"

char			**test_alias(t_plist *plist, char *cmd)
{
  t_alias		*alias;
  t_alias_cmd		*alias_cmd;

  alias_cmd = plist->begin_acmd;
  while (alias_cmd)
  {
    if (my_strcmp(alias_cmd->alias, cmd) == 0)
      return (alias_cmd->cmd);
    alias_cmd = alias_cmd->next;
  }
  alias = plist->begin_a;
  if (alias == NULL)
    return (NULL);
  while (my_strcmp(alias->alias, cmd) != 0)
    {
      alias = alias->next;
      if (alias == NULL)
      	return (NULL);
    }
  return (alias->cmd);
}

void			add_alias(t_plist *list, char *alias, char *cmd)
{
  t_alias               *new;

  new = list->begin_a;
  if (!list)
    return;
  if ((new = malloc(sizeof(t_list))) == NULL)
    return;
  new->alias = my_strdup(alias);
  new->cmd = order_args(my_str_to_wordtab(cmd), -1, 2);
  new->prev = NULL;
  new->next = NULL;
  if (list->begin_a == NULL)
    {
      list->begin_a = new;
      list->end_a = new;
    }
  else
    {
      list->end_a->next = new;
      new->prev = list->end_a;
      list->end_a = new;
    }
}

void			add_alias_cmd_list(t_plist *list, char *alias, char *cmd)
{
  t_alias_cmd               *new;

  new = list->begin_acmd;
  if (!list)
    return;
  if ((new = malloc(sizeof(t_list))) == NULL)
    return;
  new->alias = my_strdup(alias);
  new->cmd = order_args(my_str_to_wordtab(cmd), -1, 2);
  new->prev = NULL;
  new->next = NULL;
  if (list->begin_acmd == NULL)
    {
      list->begin_acmd = new;
      list->end_acmd = new;
    }
  else
    {
      list->end_acmd->next = new;
      new->prev = list->end_acmd;
      list->end_acmd = new;
    }
    list->size++;
}

int	show_alias(t_plist *list)
{
  t_alias_cmd *tmp;
  tmp = list->begin_acmd;
  while (tmp)
  {
    my_putstr(tmp->alias);
    write(1, "\n", 1);
    tmp = tmp->next;
  }
  return (0);
}
int	add_alias_cmd(char **tab, t_plist *list)
{
  char	*alias;
  char	*cmd;
  int	i;

  if (tab[1] == NULL)
    return (show_alias(list));
  alias = my_strdup(tab[1]);
  i = 2;
  while (tab[i])
  {
    alias = my_strcat(alias, " ", -1, -1);
    alias = my_strcat(alias, tab[i], -1, -1);
    i++;
  }
  i = 0;
  while (alias[i] != '\'')
    i++;
  cmd = (char *)alias + i + 1;
  alias[i - 1] = '\0';
  i = 0;
  while (cmd[i])
    i++;
  cmd[i - 1] = '\0';
  add_alias_cmd_list(list, alias, cmd);
  return (1);
}

void	pop_list_alias(t_plist *list, int pos)
{
  t_alias_cmd	*tmp;

  tmp = list->begin_acmd;
  if (list->size == 1)
  {
    list->begin_acmd = NULL;
    list->end_acmd = NULL;
    list->size = 0;
    return;
  }
  if (pos == 0)
  {
    list->begin_acmd = tmp->next;
    tmp->next->prev = NULL;
    tmp->next = NULL;
    list->size = list-> size - 1;
    return;
  }
  if (pos + 1 == list->size)
  {
    tmp = list->end_acmd;
    list->end_acmd = tmp->prev;
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    list->size = list-> size - 1;
    return;
  }
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
