/*
** path.c for path.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  2 13:12:33 2016 Antoine Roig
** Last update Tue May  3 15:16:09 2016 prost
*/

#include "minishell2.h"

void    free_path(char **path)
{
  int   i;

  i = 0;
  if (path)
    while (path[i])
      {
        free(path[i]);
        i++;
      }
  free(path);
}

char    **search_path(t_dlist *list)
{
  char          *line_path;
  t_list        *tmp;

  my_putstr("42sh > ");
  if (list->begin == NULL)
    return (NULL);
  tmp = list->begin;
  while (tmp)
    {
      if (!(my_strcmp(tmp->variablenv, "PATH")))
        {
          line_path = tmp->valuenv;
          return (my_str_to_wordtab_path(line_path));
        }
      tmp = tmp->next;
    }
  return (NULL);
}

void	init(int ac, char **av)
{
  ac = ac;
  av = av;
}

char	**init_env(t_dlist *list_env, char **env, int ac, char **av)
{
  char	**my_env;

  init(ac, av);
  if (env[0])
    my_env  = init_list_env(list_env, env);
  else
    my_env = NULL;
  return (my_env);
}

t_ret	*ride(t_dinstructions *list_instruct, char **my_env,
	      t_dlist *list_env, char **path)
{
  t_instructions	*tmp;
  t_ret			*ret;

  ret = xmalloc(sizeof(*ret) * 2);
  ret->ex = 0;
  ret->ret = 0;
  tmp = list_instruct->begin;
  while (tmp) /* on parcourt la liste d'instructions */
    {
      if (!(my_strcmp(tmp->inst->cmd, "exit"))) /* on verirife ic'est un exit pour quitter */
	{
	  ret = builtin_exit(tmp->inst, ret);
	  return (ret);
	}
      search_cmd(tmp->inst, path, my_env, list_env); /* c'est tipar, on cherche les commandes ! */
      tmp = tmp->next;
    }
  return (ret);
}
