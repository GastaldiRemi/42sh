/*
** show_list.c for show_list in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sat May 28 21:25:01 2016 
** Last update Mon May 30 13:59:13 2016 
*/

#include			"42sh.h"

void			show_list(t_plist *plist)
{
  t_list		*tmp;

  tmp = plist->begin;
  while (tmp)
    {
      my_putstr(tmp->name);
      write(1, "=", 1);
      my_putstr(tmp->data);
      write(1, "\n", 1);
      tmp = tmp->next;
    }
}

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
