/*
** left_redir.c for left_redir in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May 29 18:08:25 2016 
** Last update Sun May 29 18:43:36 2016 
*/

#include		"42sh.h"

int			red_left(char **cmd)
{
 int		fd;

 fd = open(cmd[0], O_RDONLY);
 if (fd == -1)
   {
     my_putstr(cmd[0]);
     my_putstr(": No such file or directory\n");
     return (-1);
   }
 dup2(fd, 0);
 return (1);
}

int			looping(char *buff)
{
  int			pipefd[2];

  buff = my_strcat(buff, "\0", -1, -1);
  pipe(pipefd);
  write(pipefd[1], buff, my_strlen(buff));
  close(pipefd[1]);
  dup2(pipefd[0], 0);
  return (1);
}

/* int			double_red_left(t_plist *plist, char **cmd) */
/* { */
/*   char			*buff; */
/*   char			*buff2; */
/*   char			*buff3; */

/*   buff3 = line->args[i + 1]; */
/*   buff = '\0'; */
/*   while (1) */
/*     { */
/*       buff2 = get_next_line(0); */
/*       if (my_strcmp(buff2, buff3) == 0) */
/* 	return (looping(buff, line)); */
/*       if (buff) */
/* 	buff = my_strcat(buff, buff2); */
/*       else */
/* 	buff = buff2; */
/*       buff = my_strcat(buff, "\n"); */
/*     } */
/*   return (0); */
/* } */
