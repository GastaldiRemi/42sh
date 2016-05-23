/*
** without_space.c for without_space.c in /home/roig_a/rendu/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Fri Apr  8 22:28:47 2016 Antoine Roig
** Last update Sun Apr 10 04:13:44 2016 Antoine Roig
*/

#include "minishell2.h"

char	*init_vars(char *str)
{
  char	*new;

  new = xmalloc(sizeof(char) * my_strlen(str) + 2);
  return (new);
}

char	*without_space_pipe(char *str, int i, int j)
{
  char	*new;

  new = init_vars(str);
  while (str[i])
    {
      if (str[i] == '|')
	{
	  if (str[i - 1] != ' ')
	    new[j++] = ' ';
	  if (str[i + 1] != ' ')
	    {
	      new[j++] = str[i++];
	      new[j++] = ' ';
	      continue;
	    }
	  new[j++] = str[i++];
	}
      else
	new[j++] = str[i++];
    }
  new[j] = '\0';
  return (new);
}

char	*without_space_redg(char *str, int i, int j)
{
  char	*new;

  new = init_vars(str);
  while (str[i])
    {
      if (str[i] == '<' && (str[i + 1] != '<' && str[i - 1] != '<'))
	{
	  if (str[i - 1] != ' ')
	    new[j++] = ' ';
	  if (str[i + 1] != ' ')
	    {
	      new[j++] = str[i++];
	      new[j++] = ' ';
	      continue;
	    }
	  new[j++] = str[i++];
	}
      else
	new[j++] = str[i++];
    }
  new[j] = '\0';
  return (new);
}

char	*without_space_redd(char *str, int i, int j)
{
  char	*new;

  new = init_vars(str);
  while (str[i])
    {
      if (str[i] == '>' && (str[i + 1] != '>' && str[i - 1] != '>'))
	{
	  if (str[i - 1] != ' ')
	    new[j++] = ' ';
	   if (str[i + 1] != ' ')
	    {
	      new[j++] = str[i++];
	      new[j++] = ' ';
	      continue;
	    }
	  new[j++] = str[i++];
	}
      else
	new[j++] = str[i++];
    }
  new[j] = '\0';
  return (new);
}
