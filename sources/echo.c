/*
** echo.c for echo in /home/jabbar_y/rendu/42sh/NE_PAS_TOUCHER
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Tue May 31 15:15:24 2016 Jabbari Yassir
** Last update Tue May 31 15:32:05 2016 Matthias PROST
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
  tab[0][0] = '\\';
  tab[1][0] = 'a';
  tab[2][0] = 'b';
  tab[3][0] = 'f';
  tab[4][0] = 'n';
  tab[5][0] = 'r';
  tab[6][0] = 't';
  tab[7][0] = 'v';
  tab[8] = NULL;
  funct[0] = &f_slash;
  funct[1] = &f_a;
  funct[2] = &f_b;
  funct[3] = &f_f;
  funct[4] = &f_n;
  funct[5] = &f_r;
  funct[6] = &f_t;
  funct[7] = &f_v;
  funct[8] = NULL;
}

int		check_char(char *str)
{
  int		i;
  int		a;
  char		*tab[9];
  int		(*funct[9])();

  i = -1;
  tab_funct(tab, funct);
  while (str[++i])
    {
      a = -1;
      if (str[i] == '\\')
	{
	  while (tab[++a])
	    if (str[i + 1] == tab[a][0])
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
