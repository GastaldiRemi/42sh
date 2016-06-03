/*
** init_fonc.c for init_fonc in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
**
** Made by
** Login   <gastal_r@epitech.net>
**
** Started on  Fri May 27 18:58:27 2016
** Last update	Fri Jun 03 14:26:52 2016 Full Name
*/

#include		"42sh.h"

int                     init_prompt_list(t_pcmd *pcmd, t_psep *psep)
{
  pcmd->end = NULL;
  pcmd->begin = NULL;
  psep->end = NULL;
  psep->begin = NULL;
  return (0);
}

int                     init_list(t_plist *plist)
{
  plist->end = NULL;
  plist->begin = NULL;
  plist->begin_h = NULL;
  plist->end_h = NULL;
  plist->begin_acmd = NULL;
  plist->end_acmd = NULL;
  plist->size = 0;
  return (0);
}

char                    **init_env(char **env, t_plist *plist)
{
  free_tab(env);
  if ((env = list_to_env(plist->begin, plist->begin)) == NULL)
    return (NULL);
  return (env);
}
