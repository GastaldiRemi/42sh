/*
** echo.c for echo in /home/jabbar_y/function/echo
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Fri May 27 17:57:17 2016 Jabbari Yassir
** Last update Tue May 31 15:05:31 2016 Jabbari Yassir
*/

#include "echo.h"

void		free_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}

void		print_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    {
      my_putstr(tab[i]);
      if (tab[i + 1])
	my_putchar(' ');
    }
  my_putchar('\n');
}

void		print_tab_n(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    {
      my_putstr(tab[i]);
      if (tab[i + 1])
	my_putchar(' ');
    }
}

char		**stock_av(int ac, char **av, int i, int j)
{
  char		**tab;
  int		mark;

  mark = 0;
  mark = i;
  if ((tab = malloc(sizeof(char *) * (ac))) == NULL)
    return (NULL);
  while (av[++i])
    tab[j++] = my_strdup(av[i]);
  tab[j] = NULL;
  if (mark == 1)
    print_tab_n(tab);
  else
    print_tab(tab);
  return (tab);
}

int		echo(char **av, int ac)
{
  int		i;
  int		j;
  char		**tab;

  i = 0;
  j = 0;
  if (my_strncmp(av[1], "-n", 2) == 0)
    i++;
  if ((tab = stock_av(ac, av, i, j)) == NULL)
    return (-1);
  free_tab(tab);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac >= 2)
    echo(av, ac);
  else
    my_putchar('\n');
  return (0);
}
