/*
** left_redir.c for left_redir in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May 29 18:08:25 2016 
** Last update Mon May 30 15:50:41 2016 
*/

#include		"42sh.h"

int			red_left(char **cmd)
{
 int		fd;

 fd = open(cmd[1], O_RDONLY);
 if (fd == -1)
   {
     my_putstr(cmd[1]);
     my_putstr(": No such file or directory\n");
     return (-1);
   }
 dup2(fd, 0);
 return (1);
}

int			looping(t_plist *plist, char **cmd, char *buff, char **env)
{
  int			pipefd[2];

  pipe(pipefd);
  write(pipefd[1], buff, my_strlen(buff));
  close(pipefd[1]);
  dup2(pipefd[0], 0);
  cmd += 2;
  system_fonc(plist, cmd, env); 
  free(buff);
  return (1);
}

int			double_red_left(t_plist *plist, char **cmd, char **env)
{
  char			*buff;
  char			*buff2;
  char			*buff3;

  buff3 = cmd[1];
  buff = NULL;
  while (1)
    {
      buff2 = get_next_line(0);
      if (my_strcmp(buff2, buff3) == 0)
	{
	  free(buff2);
	  return (looping(plist, cmd, buff, env));
	}
      buff = my_strcat(buff, buff2, -1, -1);
      buff = my_strcat(buff, "\n", -1, -1);
      free(buff2);
    }
  return (0);
}
