/*
** 42sh.h for 42sh in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/include
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May 26 21:26:35 2016 
** Last update Fri May 27 00:59:28 2016 
*/

#ifndef			_42_SH_H_
# define		_42_SH_H_

#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<sys/wait.h>
#include		<dirent.h>
#include		<fcntl.h>
#include		<signal.h>

typedef struct  s_list
{
  char			*name;
  char			*data;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

typedef struct		s_plist
{
  t_list		*begin;
  t_list		*end;
}			t_plist;

int			my_strlen(char *str);
char			*my_strdup(char *str, int size);
void                    env_to_list(t_plist *list, char *env);
void                    add_end(t_plist *list, char *name, char *data);
char			*my_strcat(char *, char *, int, int);
void			clear_list(t_plist *list);
char                    **list_to_env(t_list *tmp, t_list *list);

#endif			/* _42_SH_H_ */
