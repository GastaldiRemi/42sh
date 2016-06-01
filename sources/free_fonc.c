/*
** free_fonc.c for free_fonc in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri May 27 18:59:53 2016 
** Last update Wed Jun  1 16:22:32 2016 
*/

#include		"42sh.h"

void                    free_prompt_list(t_pcmd *pcmd, t_psep *psep)
{
  t_cmd                 *cmd_tmp;
  t_sep                 *sep_tmp;
  int                   i;

  while ((cmd_tmp = pcmd->begin) != NULL)
    {
      i = -1;
      pcmd->begin = pcmd->begin->next;
      while (cmd_tmp->cmd[++i])
	free(cmd_tmp->cmd[i]);
      free(cmd_tmp->cmd);
      free(cmd_tmp);
    }
  while ((sep_tmp = psep->begin) != NULL)
    {
      psep->begin = psep->begin->next;
      free(sep_tmp->sep);
      free(sep_tmp);
    }
}

void                    clear_list(t_plist *list)
{
  t_list                *tmp;

  while ((tmp = list->begin) != NULL)
    {
      list->begin = list->begin->next;
      free(tmp->name);
      if (tmp->data)
	free(tmp->data);
      free(tmp);
    }
}

void                    free_tab(char **env)
{
  int                   i;

  i = -1;
  if (env == NULL)
    return;
  while (env[++i])
    free(env[i]);
  free(env);
}

void                    free_list(t_plist *plist, t_list *list)
{
  clear_list(plist);
  free(list);
}
