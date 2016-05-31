/*
** echo.c for echo in /home/jabbar_y/rendu/42sh/NE_PAS_TOUCHER
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Tue May 31 15:15:24 2016 Jabbari Yassir
** Last update Tue May 31 17:11:18 2016 Jabbari Yassir
*/

#include "42sh.h"

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

void	tab_funct(char **tab, int (*funct[])())
{
  tab[0] = '\\';
  tab[1] = 'a';
  tab[2] = 'b';
  tab[3] = 'c';
  tab[4] = 'e';
  tab[5] = 'f';
  tab[6] = 'n';
  tab[7] = 'r';
  tab[8] = 't';
  tab[9] = 'v';
  tab[11] = NULL;
  tab[0] = f_slash;
  tab[1] = f_a:
  tab[2] = f_b;
  tab[3] = f_c;
  tab[4] = f_e;
  tab[5] = f_f;
  tab[6] = f_n;
  tab[7] = f_r;
  tab[8] = f_t;
  tab[9] = f_v;
  tab[11] = NULL;
}

int		check_char(char *str)
{
  int		i;
  int		a;
  char		*tab[12];
  int		(*funct[12])();

  i = -1;
  tab_funt(tab, funct);
  while (str[++i])
    {
      a = -1;
      if (str[i] == '\\')
	{
	  while (tab[++a])
	    if (str[i + 1] == tab[a])
	      funct[a]();
	}
    }
  return (0);
}

int		echo_e(char **tab)
{
  int		i;

  i = 2;
  if (tab[i])
    {
      while (tab[i])
	{
	  if ((check_char(tab[i])) == 0)
	    i++;
	  my_putstr(tab[i]);
	  if (tab[i + 1])
	    my_putstr(" ");
	  i++;
	}
    }
  return (0);
}

int		echo(char **tab)
{
  int		i;

  i = 1;
  if ((my_strcmp("-n", tab[i])) == 0)
    echo_n(tab);
  else if ((my_strcmp("-e", tab[i])) == 0)
    echo_e(tab);
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
