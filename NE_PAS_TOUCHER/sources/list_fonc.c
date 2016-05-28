/*
** list_fonc.c for list_fonc in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May 26 22:05:49 2016 
** Last update Sat May 28 14:47:12 2016 
*/

#include		"42sh.h"

void			show_cmd(t_pcmd *pcmd)
{
  t_cmd			*cmd;
  int			i;

  cmd = pcmd->begin;
  while (cmd)
    {
      i = -1;
      while (cmd->cmd[++i])
	{
	  my_putstr(cmd->cmd[i]);
	  my_putstr("\n");
	}
      cmd = cmd->next;
    }
}

void			show_sep(t_psep *psep)
{
  t_sep			*sep;

  sep = psep->begin;
  while (sep)
    {
      my_putstr(sep->sep);
      my_putstr("\n");
      sep = sep->next;
    }
}

void                    add_cmd(t_pcmd *list, char *buff)
{
  t_cmd                *new;

  if (!list)
    return;
  if ((new = malloc(sizeof(t_list))) == NULL)
    return;
  new->cmd = my_str_to_wordtab(buff);
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

void                    add_sep(t_psep *list, char *buff)
{
  t_sep			*new;

  if (!list)
    return;
  if ((new = malloc(sizeof(t_list))) == NULL)
    return;
  new->sep = my_strdup(buff, my_strlen(buff));
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
