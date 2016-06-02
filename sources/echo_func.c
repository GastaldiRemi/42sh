/*
** echo_func.c for echo_func in /home/jabbar_y/rendu/42sh
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Tue May 31 16:41:32 2016 Jabbari Yassir
** Last update Thu Jun  2 13:41:34 2016 Jabbari Yassir
*/

#include "42sh.h"

int		f_slash()
{
  my_putchar('\\');
  return (0);
}

int		f_a()
{
  my_putchar('\a');
  return (0);
}

int		f_b()
{
  my_putchar('\b');
  return (0);
}

void            echo_valuenv(char **tab, t_list *list)
{
  int           j;
  int		i;
  char		*tmp;

  j = 0;
  i = 1;
  if (tab[1])
    {
      if ((tmp = malloc(sizeof(char) * my_strlen(tab[1]))) == NULL)
	return;
      if (tab[1][i + 1])
	{
	  while (tab[1][i])
	    tmp[j++] = tab[1][i++];
	}
      else
	{
	  my_puts(tab[1]);
	  return;
	}
      tmp[j] = '\0';
      while (my_strcmp(list->name, tmp) != 0)
	list = list->next;
      my_puts(list->data);
      free(tmp);
    }
}
