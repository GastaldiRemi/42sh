/*
** parsing.c for parsing in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri May 27 15:55:40 2016 
** Last update Fri May 27 18:59:10 2016 
*/

#include		"42sh.h"

char			*pars_prompt(t_plist *list, char **env, char *st)
{
  t_pcmd		pcmd;
  t_psep		psep;
  t_cmd			*cmd;
  t_sep			*sep;

  if (init_prompt_list(&pcmd, &cmd, &psep, &sep) == -1)
    return (NULL);
  free_prompt_list(&pcmd, cmd, &psep, sep);
  return ("0");
}
