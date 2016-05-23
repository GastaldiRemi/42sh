/*
** my_getnbr.c for my_getnbr.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr  3 16:37:49 2016 Antoine Roig
** Last update Mon May 23 13:42:50 2016 gastal_r
*/

#include "42sh.h"

int     is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int     is_neg(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
        n++;
      i++;
    }
  if (n % 2 != 0)
    return (1);
  else
    return (0);
}

int     my_getnbr(char *str)
{
  int   i;
  int   nbr;
  int   num;

  i = 0;
  nbr = 0;
  while ((num = is_num(str[i])) == 0 && str[i] != '\0')
    i++;
  if (num == 0)
    return (0);
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] -'0'));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = nbr * -1;
  return (nbr);
}
