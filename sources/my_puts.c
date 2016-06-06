/*
** my_puts.c for my_puts in /home/jabbar_y/rendu/42sh
**
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
**
** Started on  Thu Jun  2 13:40:21 2016 Jabbari Yassir
** Last update Mon Jun  6 02:52:22 2016 
*/

#include "42sh.h"

void		my_puts(char *str)
{
  my_putstr(str);
  my_putchar('\n');
}

void    my_putchar(char c)
{
  write (1, &c, 1);
}
