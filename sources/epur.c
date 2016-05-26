/*
** epur.c for epur.c in /home/roig_a/rendu/getnextline/PSU_2015_minishell1
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sat Jan 23 23:42:55 2016 Antoine Roig
** Last update Thu May 26 15:39:45 2016 
*/

#include "42sh.h"

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

int     char_isalpha(char str)
{
  if (str != ' ')
    return (1);
  else
    return (0);
}

char    *pre_parsing2(char *prompt, int *i)
{
  char  *buff;

  if ((buff = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  buff[0] = '\0';
  while (prompt[*i] == ';')
    (*i)++;
  return (buff);
}

void    pre_parsing3(char *prompt, char *buff, int *i, int *j)
{
  buff[*j] = prompt[*i];
  buff[*j + 1] = ' ';
  buff[*j + 2] = ';';
  buff[*j + 3] = ' ';
  buff[*j + 4] = '\0';
  (*j) += 4;
  (*i)++;
  while ((prompt[*i] == ' ' ||
	            prompt[*i] == ';' ||
	  prompt[*i] == '\t') && prompt[*i] != '\0')
    (*i)++;
}

char    *my_epurstr(char *prompt)
{
  t_pars        pars;

  pars.j = 0;
  pars.i = 0;
  pars.buff = (pre_parsing2(prompt, &pars.i));
  while (prompt[pars.i])
    {
      if ((char_isalpha(prompt[pars.i]) == 1 || prompt[pars.i] == ' '||
	   prompt[pars.i] == '\t')
	  && prompt[pars.i + 1] == ';')
	{
	  pars.buff = my_realloc(pars.buff, pars.j + 5);
	  pre_parsing3(prompt, pars.buff, &pars.i, &pars.j);
	}
      else
	{
	  pars.buff = my_realloc(pars.buff, pars.j + 2);
	  pars.buff[pars.j] = prompt[pars.i];
	  pars.buff[pars.j + 1] = '\0';
	  pars.i++;
	  pars.j++;
	}
    }
  pars.buff[pars.j] = '\0';
  return (pars.buff);
}
