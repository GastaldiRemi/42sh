/*
** utils.c for utils.c in /home/roig_a/rendu/getnextline/PSU_2015_minishell1
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Mon Jan  4 15:41:33 2016 Antoine Roig
** Last update Wed Apr  6 21:03:41 2016 Antoine Roig
*/

#include "minishell2.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(1, &str[i++], 1);
  return (1);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  else
    return (s1[i] - s2[i]);
  return (0);
}

int	count_word(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      if (str[i] == ':')
	nb++;
      i++;
    }
  nb += 1;
  return (nb);
}
char    **my_str_to_wordtab_path(char *str)
{
  char  **tab;
  int   wnb;
  int   i;
  int   j;
  int   k;

  i = 0;
  j = 0;
  wnb = count_word(str);
  tab = xmalloc(sizeof(char *) * wnb + sizeof(char *));

  while (str[i])
    {
      tab[j] = xmalloc(sizeof(char) * my_strlen(str) + 1);
      k = 0;
      while (str[i] != ':' && str[i] != '\0')
	tab[j][k++] = str[i++];
      tab[j][k] = '\0';
      if (str[i] == ':')
	i++;
      j++;
    }
  tab[j] = NULL;
  return (tab);
}

char    **my_str_to_wordtab(char *str)
{
  char  **tab;
  int   wnb;
  int   i;
  int   j;
  int   k;

  i = 0;
  j = 0;
  wnb = count_word(str);
  tab = xmalloc(sizeof(char*) * (wnb + sizeof(char *)));
  while (str[i])
    {
      tab[j] = xmalloc(sizeof(char) * my_strlen(str) + 2);
      while ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' ||
      str[i] > 'z') && (str[i] <'-' || str[i] > '9') && (str[i] != '>')
	     && (str[i] != '<') && (str[i] != '|'))
        i++;
      k = 0;
      while (str[i] != ' ' && str[i] != '\0')
	tab[j][k++] = str[i++];
      tab[j][k] = '\0';
      j++;
    }
  tab[j] = NULL;
  return (tab);
}
