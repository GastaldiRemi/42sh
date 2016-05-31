/*
** main.c for main.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  2 11:41:10 2016 Antoine Roig
** Last update	Mon May 30 14:25:42 2016 Full Name
*/

#include "42sh.h"

void	clear_list_inst(t_dinstructions *list)
{
  t_instructions	*tmp;
  t_instructions	*tmp2;

  tmp = list->begin;
  while (tmp != NULL)
    {
      tmp2 = pop_list_begin_inst(list);
      tmp = list->begin;
      free(tmp2);
    }
  free(tmp);
}

char   **list_to_env(t_dlist *list)
{
  int   i;
  t_list        *tmp;
  char          **my_env;

  if (list->begin == NULL)
    return (NULL);
  tmp = list->begin;
  i = 0;
  my_env = xmalloc(sizeof(char *) * (list->size + 1));
  while (tmp)
    {
      my_env[i] = my_strcat(tmp->variablenv, my_strcat("=", tmp->valuenv));
      i++;
      tmp = tmp->next;
    }
  my_env[i] = NULL;
  return (my_env);
}

int    end(t_dlist *list)
{
  clear_list(list);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  t_dlist		*list_env;
  char			**my_env;
  char			**path;
  t_dinstructions	*list_instruct;
  char			*instruct;
  t_ret			*ret;

  new_list_instruct(&list_instruct);
  new_list(&list_env);
  my_env = init_env(list_env, env, ac, av);
  while (1)
    {
      path = search_path(list_env);
      instruct = get_instruct(0);
      if (instruct[0] != '\0')
	{
	  prepare_list_instruct(list_instruct, instruct, -1);
	  ret = ride(list_instruct, my_env, list_env, path);
	  if (ret->ex == 1)
	    return (ret->ret);
	  my_env = list_to_env(list_env);
	}
      clear_list_inst(list_instruct);
    }
  return (0);
}
