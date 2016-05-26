/*
** get_instruct.c for get_instruct.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  2 13:21:33 2016 Antoine Roig
** Last update Thu May 26 18:34:25 2016 
*/

#include "42sh.h"

int     get_prompt_length(char **prompt)
{
  int   i;

  i = 0;
  while (prompt[i] != NULL)
    i++;
  return (i);
}

char    **order_args(char **prompt)
{
  int   i;
  int   j;
  char  **buff;

  j = 2;
  i = -1;
  buff = malloc(sizeof(char *) * (get_prompt_length(prompt) + 1));
  while (++i < get_prompt_length(prompt))
    buff[i] = malloc(sizeof(char) * (my_strlen(prompt[i]) + 1));
  i = 0;
  if (my_strcmp(">", prompt[0]) == 0 || my_strcmp(">>", prompt[0]) == 0
      || my_strcmp("<", prompt[0]) == 0 || my_strcmp("<<", prompt[0]) == 0)
    return (prompt);
  while (prompt[i] != NULL)
    {
      if (my_strcmp(">", prompt[i]) == 0 || my_strcmp(">>", prompt[i]) == 0
	  || my_strcmp("<", prompt[i]) == 0 || my_strcmp("<<", prompt[i]) == 0)
	{
	  buff[0] = prompt[i];
	  buff[1] = prompt[i + 1];
	  while (j - 2 < i)
	    {
	      buff[j] = prompt[j - 2];
	      j++;
	    }
	  return (buff);
	}
      i++;
    }
  return (prompt);
}

char	**pars_prompt(char **prompt)
{
  int   i;
  int   j;
  char  **buff;

  i = 0;
  j = 0;
  buff = malloc(sizeof(char *) * (get_prompt_length(prompt) + 1));
  while (prompt[i] != NULL)
    {
      buff[j] = my_realloc(prompt[i], my_strlen(prompt[i]));
      if (prompt[i] != NULL && prompt[i + 1] != NULL
	  && prompt[i][0] != '\0' && prompt[i][0] == ';')
      	{
	  buff[j] = NULL;
	  buff = order_args(buff);
	  j = -1;
	}
      j++;
      i++;
    }
  (buff[j - 1][0] == ';' ? buff[j - 1] = NULL : 0);
  buff[j] = NULL;
  /* buff = order_args(buff); */
  return (buff);
}

void    fille_line(t_instruct **line, char *instruct)
{
  int   i;

  i = 0;
  while (instruct[i] != ' ' && instruct[i] != '\0')
    i++;
  (*line)->cmd = xmalloc(sizeof(char) * i + 1);
  i = 0;
  while (instruct[i] != ' ' && instruct[i] != '\0')
    {
      (*line)->cmd[i] = instruct[i];
      i++;
    }
  (*line)->cmd[i] = '\0';
  i = 0;
  if (instruct)
    {
      (*line)->args = my_str_to_wordtab(instruct);
      (*line)->args = pars_prompt((*line)->args);
    }
  else
    (*line)->args = NULL;
}

t_instruct      *prepare_line(char *instruct)
{
  t_instruct    *line;

  line = xmalloc(sizeof(t_instruct));
  fille_line(&line, instruct);
  return (line);
}

char    *my_strncpy(char *dest, char *src, int nb)
{
  int   i;

  i = 0;
  while (src[i] && i < nb)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

void	prepare_list_instruct(t_dinstructions *list_instruct, /* on va donc prépae notre listr d'instructions */
			      char *instruct, int i)
{
  int		j;
  int		k;
  char		*inst_cpy;
  t_instruct	*line;

  k = 1;
  j = 0;
  while (instruct[++i])
    {
      if (instruct[i] == ';' || instruct[i + 1] == '\0')
	{
	  inst_cpy = xmalloc(sizeof(char) * k + 1);
	  my_strncpy(inst_cpy, (char *)instruct + j, k);
	  inst_cpy = my_epurstr(inst_cpy);
	  if (inst_cpy[my_strlen(inst_cpy) - 1] == ';')
	    inst_cpy[my_strlen(inst_cpy) - 1] = '\0';
	  line = prepare_line(inst_cpy);
	  free(inst_cpy);
	  add_list_end_inst(list_instruct, line);
	  j = i + 1;
	  k = 0;
	}
      k++;
    }
}

char 	*get_instruct(int fd) /* on va prendre le parsing de rémi pour les redir et pipes */
{
  char	*instruct;

  instruct = get_next_line(fd);
  if (instruct == NULL)
    exit(0);
  instruct = my_epurstr(instruct);
  instruct = without_space_pipe(instruct, 0, 0);
  instruct = without_space_redg(instruct, 0, 0);
  instruct = without_space_redd(instruct, 0, 0);
  return (instruct);
}
