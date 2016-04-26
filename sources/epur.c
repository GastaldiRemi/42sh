/*
** epur.c for epur.c in /home/roig_a/rendu/getnextline/PSU_2015_minishell1
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sat Jan 23 23:42:55 2016 Antoine Roig
** Last update Sat Apr  2 17:34:23 2016 Antoine Roig
*/

#include "minishell2.h"

char	*epur_first_part(char *string)
{
  int	i;
  char	*str;

  i = 0;
  str = xmalloc(sizeof(char) * (my_strlen(string) + 1));
  my_strcpy(str, string);
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  str = (char*) str + i;
  i = 0;
  while (str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  if (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == ';')
    str[i - 1] = '\0';
  return (str);
}

char	*my_epurstr(char *str)
{
  char	*ret;
  int	i;
  int	j;

  j = 0;
  i = 0;
  str = epur_first_part(str);
  ret = xmalloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[i])
    {
      ret[j] = str[i];
      if ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] == ' '
						|| str[i + 1] == '\t'))
	while ((str[i] == ' ' || str[i] == '\t'))
	  i++;
      else
      	i++;
      j++;
    }
  ret[j] = '\0';
  if (ret[my_strlen(ret) - 1] == ' ' || ret[my_strlen(ret) - 1] == '\t')
    ret[my_strlen(ret) - 1] = '\0';
  return (ret);
}
