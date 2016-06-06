/*
** sig.c for sig in /home/jabbar_y/rendu/42sh
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Mon Jun  6 13:31:59 2016 Jabbari Yassir
** Last update Mon Jun  6 13:34:01 2016 Jabbari Yassir
*/

#include "42sh.h"

int		sig_func_dad(int pid, int status)
{
  signal(SIGINT, SIG_IGN);
  waitpid(pid, &status, 0);
  signal(SIGINT, SIG_DFL);
  return (status);
}
