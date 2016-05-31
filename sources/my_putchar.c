/*
** my_putchar.c for 42sh in /home/prost/Rendu/Semestre_02/42sh/sources
**
** Made by Matthias PROST
** Login   <prost@epitech.net>
**
** Started on  Tue May 31 15:22:35 2016 Matthias PROST
** Last update Tue May 31 15:22:58 2016 Matthias PROST
*/

#include "42sh.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}
