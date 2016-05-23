/*
** env.c for env.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  2 11:52:26 2016 Antoine Roig
** Last update Mon May 23 13:41:48 2016 gastal_r
*/

#include "42sh.h"

t_dlist *unset_env(t_instruct *line, t_dlist *list)
{
  t_list        *tmp;
  int           i;
  int           j;

  j = 1;
  while (line->args[j])
    {
      tmp = list->begin;
      i = 0;
      while (tmp)
        {
          if ((my_strcmp(tmp->variablenv, line->args[j])) == 0)
            pop_list_somewhere(list, i);
          tmp = tmp->next;
          i++;
        }
      j++;
    }
  return (list);
}

void    get_linenv(t_linenv **line, char *line_env)
{
  int   i;
  int   l;

  l = 0;
  i = -1;
  while (line_env[++i] != '=');
  (*line)->variable = xmalloc(sizeof(char) * i + 1);
  i = 0;
  while (line_env[i] != '=')
    {
      (*line)->variable[i] = line_env[i];
      i++;
    }
  (*line)->variable[i] = '\0';
  while (line_env[i] != '\0')
    {
      l++;
      i++;
    }
  (*line)->value = xmalloc(sizeof(char) * l + 1);
  i -= l - 1;
  l = 0;
  while (line_env[i] != '\0')
    (*line)->value[l++] = line_env[i++];
  (*line)->value[l] = '\0';
}

char    **get_my_env(char **env)
{
  char  **my_env;
  int   i;

  i = 0;
  if (env[0] == NULL)
    {
      my_env = xmalloc(sizeof(char*) * 1);
      my_env[0] = NULL;
      return (my_env);
    }
  while (env[i])
    i++;
  my_env = xmalloc(sizeof(char*) * (i + 1));
  i = 0;
  while (env[i])
    {
      my_env[i] = my_strdup_o(env[i]);
      i++;
    }
  my_env[i] = NULL;
  return (my_env);
}

void    get_env(char **env, t_dlist *list_env)
{
  int   i;
  t_linenv *line;

  if (env[0] == NULL)
    return;
  line = xmalloc(sizeof(t_linenv));
  i = 0;
  while (env[i])
    {
      get_linenv(&line, env[i]);
      add_list_end(list_env, line->variable, line->value);
      i++;
    }
  free(line);
}

char    **init_list_env(t_dlist *list_env, char **env)
{
  char  **my_env;

  my_env = get_my_env(env);
  get_env(my_env, list_env);
  return (my_env);
}
