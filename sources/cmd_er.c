/*
** cmd_er.c for cmd_er.c in /home/roig_a/rendu/PSU_2015_minishell2
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr  3 18:18:53 2016 Antoine Roig
** Last update Mon May 23 13:41:19 2016 gastal_r
*/

#include "42sh.h"

int    exec_cmd_2_unknown(char *cmd)
{
  my_putstr(cmd);
  my_putstr(": Command not found.\n");
  return (-1);
}
