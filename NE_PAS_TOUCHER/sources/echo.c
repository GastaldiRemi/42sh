/*
** echo.c for echo in /home/jabbar_y/rendu/42sh/NE_PAS_TOUCHER
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Tue May 31 15:15:24 2016 Jabbari Yassir
** Last update Tue May 31 15:28:03 2016 Jabbari Yassir
*/

#include "42sh.h"

int		echo(char **tab)
{
  int		i;

  i = 1;
  if ((my_strcmp("-n", tab[i])) == 0)
    i++;
  else
    {
      while (tab[i])
	{
	  my_putstr(tab[i]);
	  if (tab[i + 1])
	    my_putstr(" ");
	  i++;
	}
      my_putstr("\n");
    }
  return (0);
}
