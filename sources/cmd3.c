/*
** cmd3.c for cmd3.c in /home/roig_a/rendu/PSU_2015_minishell2/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Apr  9 16:42:46 2016 Antoine Roig
** Last update Thu May 26 11:56:34 2016 
*/

#include "42sh.h"

int	init_pid(int fd)
{
  int	pid;

  close(fd);
  pid = fork();
  return (pid);
}
