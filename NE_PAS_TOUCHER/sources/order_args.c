/*
** order_args.c for order_args in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Mon May 30 10:16:07 2016 
** Last update Mon May 30 12:19:30 2016 
*/

#include		"42sh.h"

int			get_prompt_length(char **prompt)
{
  int			i;

  i = 0;
  while (prompt[i] != NULL)
    i++;
  return (i);
}

char			**order_args(char **prompt)
{
  int			i;
  int			j;
  char			**buff;
  int			k;

  k = -1;
  j = 2;
  if ((my_strcmp(">", prompt[0]) == 0 || my_strcmp(">>", prompt[0]) == 0)
      || (my_strcmp("<", prompt[0]) == 0 || my_strcmp("<<", prompt[0]) == 0))
    return (prompt);
  i = 0;
  while (prompt[i] != NULL)
    {
      if ((my_strcmp(">", prompt[i]) == 0 || my_strcmp(">>", prompt[i]) == 0)
	  || (my_strcmp("<", prompt[i]) == 0 || my_strcmp("<<", prompt[i]) == 0))
	{
	  buff = malloc(sizeof(char *) * (get_prompt_length(prompt) + 1));
	  buff[0] = my_strdup(prompt[i]);
	  buff[1] = my_strdup(prompt[i + 1]);
	  while (j - 2 < i)
	    {
	      buff[j] = my_strdup(prompt[j - 2]);
	      j++;
	    }
	  buff[j] = NULL;
	  k = -1;
	  while (prompt[++k])
	    free(prompt[k]);
	  free(prompt);
	  return (buff);
	}
      i++;
    }
  return (prompt);
}
