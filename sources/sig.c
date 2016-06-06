/*
** sig.c for sig in /home/jabbar_y/rendu/42sh
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Mon Jun  6 13:31:59 2016 Jabbari Yassir
** Last update Mon Jun  6 14:00:24 2016 Jabbari Yassir
*/

#include "42sh.h"

int		sig_func_dad(int pid, int status)
{
  signal(SIGINT, SIG_IGN);
  waitpid(pid, &status, 0);
  signal(SIGINT, SIG_DFL);
  return (status);
}

void		print_sig(int status)
{
  if (WTERMSIG(status) == SIGSEGV)
    dprintf(2, "Segmentation fault (core dumped)\n");
  else if (WTERMSIG(status) == SIGHUP)
    dprintf(2, "Hangup\n");
  else if (WTERMSIG(status) == SIGQUIT)
    dprintf(2, "Quit (core dumped)\n");
  else if (WTERMSIG(status) == SIGILL)
    dprintf(2, "Illegal instruction (core dumped)\n");
  else if (WTERMSIG(status) == SIGABRT)
    dprintf(2, "Abort (core dumped)\n");
  else if (WTERMSIG(status) == SIGFPE)
    dprintf(2, "Floating exception (core dumped)\n");
  else if (WTERMSIG(status) == SIGKILL)
    dprintf(2, "Killed\n");
  else if (WTERMSIG(status) == SIGALRM)
    dprintf(2, "Alarm clock");
  else if (WTERMSIG(status) == SIGPIPE)
    dprintf(2, "Broken pipe\n");
  else if (WTERMSIG(status) == SIGSTOP)
    dprintf(2, "Suspended (signal)\n");
  else if (WTERMSIG(status) == SIGTERM)
    dprintf(2, "Terminated\n");
}
