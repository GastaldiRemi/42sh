/*
** free_memories.c for free_memorie in /home/jabbar_y/rendu/42sh
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Thu May  5 10:26:34 2016 Jabbari Yassir
** Last update Thu May  5 11:06:23 2016 Jabbari Yassir
*/

#include "minishell2.h"

void		my_free_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
}

void		free_memorie(t_dlist *list_env, char **my_env,
			     t_dinstructions *list_instruct, char **path)
{
  while (list_env->begin != list_env->end)
    {
      free(list_env->begin->variablenv);
      free(list_env->begin->valuenv);
      list_env->begin = list_env->begin->next;
      free(list_env->begin->prev);
    }
  while (list_instruct->begin != list_instruct->end)
    {
      free(list_instruct->begin->inst->cmd);
      my_free_tab(list_instruct->begin->inst->args);
      list_instruct->begin = list_instruct->begin->next;
      free(list_instruct->begin->prev);
    }
  my_free_tab(my_env);
  my_free_tab(path);
}
