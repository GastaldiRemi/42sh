/*
** utils2.c for utils2.C in /home/roig_a/rendu/getnextline/PSU_2015_minishell1
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Tue Jan  5 20:19:25 2016 Antoine Roig
** Last update Wed May 25 17:59:53 2016 
*/

#include "minishell2.h"

char    *my_strdup_o(char *src)
{
  char *new;

  new = xmalloc(sizeof(char) * (my_strlen(src) + 1));
  if (new == NULL)
    return (new);
  my_strcpy(new, src);
  return (new);
}

int     my_show_wordtab(char **tab)
{
  int   i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      write(1, "\n", 1);
      i++;
    }
  return (0);
}

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   j;
  char  *tmp;

  j = 0;
  i = my_strlen(dest);
  tmp = xmalloc(sizeof(char) * (i + my_strlen(src) + 1));
  i = 0;
  while (dest[j])
    tmp[i++] = dest[j++];
  j = 0;
  while (src[j])
    tmp[i++] = src[j++];
  tmp[i] = '\0';
  return (tmp);
}
