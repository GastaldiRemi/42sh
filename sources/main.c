/*
** main.c for main.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  2 11:41:10 2016 Antoine Roig
** Last update Thu May  5 10:38:56 2016 Jabbari Yassir
*/

#include "minishell2.h"

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

char		**list_to_env(t_dlist *list)
{
  int		i;
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
  free(tmp);
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

  new_list_instruct(&list_instruct); /* création d'une liste pour contenir les instructions*/
  new_list(&list_env); /* création d'une liste pour contenir l'env */
  my_env = init_env(list_env, env, ac, av); /* création d'un my_env pour travailler avec notre env perso */
  while (1)
    {
      path = search_path(list_env); /* on stock la varaible d'env PATH */
      if ((instruct = get_instruct(0)) == NULL)  /* on récupère l'entrée standad dans une instruction */
	{
	  free_memorie(list_env, my_env, list_instruct, path);
	  return (-1);
	}
      if (instruct[0] != '\0')
	{
	  prepare_list_instruct(list_instruct, instruct, -1); /* on met les instructions contenues dans instruct dns une liste */
	  ret = ride(list_instruct, my_env, list_env, path); /* c'est parti on va executer des trucs ! */
	  if (ret->ex == 1)
	    return (ret->ret);
	  my_env = list_to_env(list_env); /* on met à jour notre env */
	}
      clear_list_inst(list_instruct); /* on clean la liste d'instruction */
    }
  return (0);
}
