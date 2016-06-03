/*
** alias_func.c for alias_func in /home/jabbar_y/rendu/42sh
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Fri Jun  3 17:35:27 2016 Jabbari Yassir
** Last update Fri Jun  3 23:23:38 2016 Jabbari Yassir
*/

#include "42sh.h"

void		parser_alias_bis(t_plist *list, char *str, t_data data_alias)
{
  if (str[data_alias.i + 1] == 39)
    data_alias.i++;
  data_alias.j = data_alias.i;
  while (str[data_alias.i] != 39 && str[data_alias.i])
    data_alias.i++;
  if ((data_alias.cmd2 = malloc(sizeof(char) * data_alias.i + 1)) == NULL)
    return;
  data_alias.i = ++data_alias.j;
  data_alias.j = 0;
  while (str[data_alias.i + 1])
    data_alias.cmd2[data_alias.j++] = str[data_alias.i++];
  data_alias.cmd2[data_alias.j] = '\0';
  add_alias(list, data_alias.cmd1, data_alias.cmd2);
  free(data_alias.cmd2);
}

void		parser_alias(t_plist *list, char *str)
{
  t_data	data_alias;

  data_alias.i = 0;
  data_alias.j = 0;
  if (my_strcmp(str, "alias") == 0)
    return;
  while (str[data_alias.i] != '=' && str[data_alias.i])
    data_alias.i++;
  if ((data_alias.cmd1 = malloc(sizeof(char) * data_alias.i + 1)) == NULL)
    return;
  data_alias.i = 0;
  while (str[data_alias.i] != '=' && str[data_alias.i])
    {
      data_alias.cmd1[data_alias.i] = str[data_alias.i];
      data_alias.i++;
    }
  data_alias.cmd1[data_alias.i] = '\0';
  parser_alias_bis(list, str, data_alias);
  free(data_alias.cmd1);
}

char		*xread(int fd)
{
  int		rd;
  char		*buffer;

  rd = 0;
  if ((buffer = malloc(sizeof(char) * 4096)) == NULL)
    return (NULL);
  rd = read(fd, buffer, 4095);
  if (rd == -1)
    return (NULL);
  buffer[rd] = '\0';
  return (buffer);
}

void		alias(t_plist *list)
{
  int		fd;
  char		*buffer;
  char		**tab;
  int		i;

  i = 0;
  if ((fd = open(".42shrc", O_RDONLY)) == -1)
    {
      if ((fd = open(".42shrc", O_RDWR | O_CREAT, 0666)) == -1)
	return;
    }
  else
    {
      if ((buffer = xread(fd)) == NULL)
	return;
      if ((tab = my_str_to_wordtab(buffer)) == NULL)
	return;
      while (tab[i])
	parser_alias(list, tab[i++]);
      free(buffer);
    }
  free_tab(tab);
}
