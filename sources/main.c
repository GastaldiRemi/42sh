/*
<<<<<<< HEAD
** main.c for main.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  2 11:41:10 2016 Antoine Roig
** Last update	Mon May 30 14:25:42 2016 Full Name
=======
** main.c for 42sh in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May 26 21:45:20 2016 
** Last update Tue May 31 13:51:57 2016 
>>>>>>> 2bb95306c7df2b5c0e220edee3603b94da3453b1
*/

#include		"42sh.h"

int			exit_end(char *st)
{
  int			tmp;

  tmp = my_getnbr(st);
  /* free(st); */
  return (tmp);
}

int			main(int ac, char **av, char **env)
{
<<<<<<< HEAD
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
=======
  int			i;
  t_plist		plist;
  t_list		*list;
  char			*exit_value;
  t_env			my_env;

  (void)ac;
  (void)av;
  my_env.env = NULL;
  if (env[0] == NULL)
    return (0);
  if (init_list(&plist, &list) == -1)
    return (0);
  i = -1;
  while (env[++i] != NULL)
    env_to_list(&plist, env[i]);
  exit_value = prompt(&my_env, &plist);
  free_list(&plist, list);
  return (exit_end(exit_value));
>>>>>>> 2bb95306c7df2b5c0e220edee3603b94da3453b1
}
