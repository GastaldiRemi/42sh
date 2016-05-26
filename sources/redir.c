/*
** redir.c for redir.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Thu Apr  7 10:47:25 2016 Antoine Roig
** Last update Thu May 26 12:00:59 2016 
*/

#include "42sh.h"

int	check_redir(t_instruct *line)
{
  int	i;
  int	fd;

  i = 0;
  while (line->args[i])
    {
      if (line->args[i][0] == '>' && line->args[i][1] == '\0')
      	{
      	  fd = open(line->args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
		    | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	  line->args[i] = NULL;
      	  dup2(fd, 1);
	  close(fd);
      	  return (1);
      	}
      i++;
    }
  return (0);
}

int	check_redir2(t_instruct *line)
{
  int	i;
  int	fd;

  i = 0;
  while (line->args[i])
    {
      if (line->args[i][0] == '>' && line->args[i][1] == '>' &&
	  line->args[i][2] == '\0')
      	{
      	  fd = open(line->args[i + 1], O_WRONLY | O_CREAT | O_APPEND, S_IRUSR
		    | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	  line->args[i] = NULL;
      	  dup2(fd, 1);
	  close(fd);
      	  return (1);
      	}
      i++;
    }
  return (0);
}

int	check_redir_g(t_instruct *line)
{
  int		i;
  int		fd;

  i = 0;
  while (line->args[i])
    {
      if (line->args[i][0] == '<' && line->args[i][1] == '\0')
	{
	  fd = open(line->args[i + 1], O_RDONLY);
	  if (fd == -1)
	    {
	      my_putstr(line->args[i + 1]);
	      my_putstr(": No such file or directory\n");
	      return (-1);
	    }
	  line->args[i] = NULL;
	  dup2(fd, 0);
	  return (1);
	}
      i++;
    }
  return (0);
}

int	looping(char *buff, t_instruct *line, int i)
{
  int   pipefd[2];

  buff = my_strcat(buff, "\0");
  pipe(pipefd);
  write(pipefd[1], buff, my_strlen(buff));
  close(pipefd[1]);
  dup2(pipefd[0], 0);
  line->args[i] = NULL;
  return (1);
}

int     check_redir_dg(t_instruct *line, int i)
{
  char  *buff;
  char  *buff2;
  char  *buff3;

  while (line->args[++i])
    {
      if (line->args[i][0] == '<' && line->args[i][1] == '<' &&
          line->args[i][2] == '\0')
        {
          buff3 = line->args[i + 1];
	  buff = '\0';
          while (1)
            {
              buff2 = get_next_line(0);
              if (my_strcmp(buff2, buff3) == 0)
		return (looping(buff, line, i));
              if (buff)
                buff = my_strcat(buff, buff2);
              else
                buff = buff2;
              buff = my_strcat(buff, "\n");
            }
        }
    }
  return (0);
}
