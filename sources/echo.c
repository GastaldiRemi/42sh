/*
** echo.c for echo in /home/jabbar_y/rendu/42sh/NE_PAS_TOUCHER
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Tue May 31 15:15:24 2016 Jabbari Yassir
** Last update Mon Jun  6 17:53:59 2016 Juliani Renaud
*/

#include	"42sh.h"

int		echo_n(char **tab)
{
  int		i;

  i = 2;
  if (tab[i])
    {
      while (tab[i])
	{
	  my_putstr(tab[i]);
	  if (tab[i + 1])
	    my_putstr(" ");
	  i++;
	}
    }
  return (0);
}

void		custom_putstr(char **tab, int i, int j)
{
  while (tab[i][j])
    {
      if (tab[i][j] == 34)
	j++;
      if (tab[i][j] != '\0')
	my_putchar(tab[i][j++]);
    }
}

int		echo(t_plist *plist, char **tab, char **env)
{
  int		i;
  int		j;
  t_list	*list;

  (void)env;
  list = plist->begin;
  i = 1;
  j = 0;
  if (tab[i] && ((my_strcmp("-n", tab[i])) == 0))
    echo_n(tab);
  else if (tab[i] && (tab[i][0] == '$'))
    echo_valuenv(tab, list);
  else
    {
      while (tab[i])
	{
	  custom_putstr(tab, i, j);
	  if (tab[i + 1])
	    my_putstr(" ");
	  i++;
	  j = 0;
	}
      my_putstr("\n");
    }
  return (0);
}
