/*
** get_instruct.c for get_instruct.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  2 13:21:33 2016 Antoine Roig
** Last update Thu May  5 10:37:34 2016 Jabbari Yassir
*/

#include "minishell2.h"

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
    (*line)->args = my_str_to_wordtab(instruct);
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
    {
      my_putstr("exit\n");
      free(instruct);
      return (NULL);
    }
  instruct = my_epurstr(instruct);
  instruct = without_space_pipe(instruct, 0, 0);
  instruct = without_space_redg(instruct, 0, 0);
  instruct = without_space_redd(instruct, 0, 0);
  return (instruct);
}
