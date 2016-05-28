/*
** init_fonc.c for init_fonc in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri May 27 18:58:27 2016 
** Last update Sat May 28 14:53:17 2016 
*/

#include		"42sh.h"

int                     init_prompt_list(t_pcmd *pcmd, t_cmd **cmd,
					 t_psep *psep, t_sep **sep)
{
  if ((*cmd = malloc(sizeof(t_cmd))) == NULL)
    return (-1);
  if ((*sep = malloc(sizeof(t_sep))) == NULL)
    return (-1);
  pcmd->end = NULL;
  pcmd->begin = NULL;
  psep->end = NULL;
  psep->begin = NULL;
  return (0);
}

int                     init_list(t_plist *plist, t_list **list)
{
  if ((*list = malloc(sizeof(t_list))) == NULL)
    return (-1);
  plist->end = NULL;
  plist->begin = NULL;
  return (0);
}

char                    **init_env(char **env, t_plist *plist)
{
  free_env(env);
  if ((env = list_to_env(plist->begin, plist->begin)) == NULL)
    return (NULL);
  return (env);
}

