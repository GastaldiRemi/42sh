/*
** getnextline.c for get_next_line.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  2 16:41:53 2016 Antoine Roig
** Last update Mon Apr  4 09:55:01 2016 Antoine Roig
*/

#include "minishell2.h"

char    *my_strncat(char *dest, char *src, int nb)
{
  int   i;
  int   j;

  j = 0;
  i = my_strlen(dest);
  while (src[j] && j < nb)
    {
      dest[i] = src[j];
      i += 1;
      j += 1;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_strdup(char *src, char **save)
{
  int   i;
  char *new;

  if (save)
    {
      new = my_strdup(*save, NULL);
      *save = NULL;
      return (new);
    }
  else
    {
      i = 0;
      new = xmalloc(sizeof(char) * my_strlen(src) + 1);
      if (new == NULL)
        return (new);
      while (src[i])
        {
          new[i] = src[i];
          i++;
        }
      new[i] = '\0';
      return (new);
    }
}

t_var   *get_next_second_part(t_var *var)
{
  var->keep = NULL;
  var->keep = my_strdup(var->s_tmp, NULL);
  var->keep[my_strlen(var->keep)] = '\0';
  if (var->save_stat)
    {
      var->s_tmp = xmalloc(sizeof(char) * (my_strlen(var->buff)
					   + var->i + my_strlen(var->save_stat) + 1));
      my_strncat(var->s_tmp, my_strdup(var->save_stat, NULL),
                 my_strlen(my_strdup(var->save_stat, NULL)));
      var->save_stat = NULL;
    }
  else
    var->s_tmp = xmalloc(sizeof(char) * (my_strlen(var->buff)
					 + var->i + 2 + my_strlen(var->keep)));
  my_strncat(var->s_tmp, var->keep, my_strlen(var->keep));
  my_strncat(var->s_tmp, var->buff, my_strlen(var->buff));
  return (var);
}

char    *get_next_line(const int fd)
{
  static        char    *s;
  t_var                 *var;

  s = NULL;
  var = xmalloc(sizeof(*var));
  var->s_tmp = my_strdup("", NULL);
  while (1)
    {
      var->buff = xmalloc(sizeof(char) * (READ_SIZE + 1));
      if (read(fd, var->buff, READ_SIZE) == 0)
        return (s ? my_strdup(s, &s) : var->s_tmp[0] != 0 ? var->s_tmp : NULL);
      var->i = -1;
      var->buff[READ_SIZE] = '\0';
      while (var->buff[++var->i])
        if (var->buff[var->i] == '\n')
          {
            s ? my_strncat(var->s_tmp, s, my_strlen(s)) : "";
            my_strncat(var->s_tmp, var->buff, var->i);
            s = (char*)(var->buff + var->i + 1);
            return (var->s_tmp);
          }
      var->save_stat = s;
      get_next_second_part(var);
      s = var->save_stat;
    }
}
