/*
** 42sh.h for 42sh in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/include
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May 26 21:26:35 2016 
** Last update Sat May 28 19:16:47 2016 
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

# define SEPARATOR	"<>|;"

typedef struct		 s_list
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

typedef struct		s_cmd
{
  char			**cmd;
  struct s_cmd		*prev;
  struct s_cmd		*next;
}			t_cmd;

typedef struct		s_pcmd
{
  t_cmd			*begin;
  t_cmd			*end;
}			t_pcmd;

typedef struct		s_sep
{
  char			*sep;
  struct s_sep		*prev;
  struct s_sep		*next;
}			t_sep;

typedef struct		s_psep
{
  t_sep			*begin;
  t_sep			*end;
}			t_psep;

void                    show_sep(t_psep *psep);
void                    show_cmd(t_pcmd *pcmd);
void                    add_sep(t_psep *list, char *buff);
void                    add_cmd(t_pcmd *list, char *buff);
char			**my_str_to_wordtab(char *str);
char                    **init_env(char **env, t_plist *plist);
char			*get_next_line(const int fd);
void			my_putstr(char *str);
int			my_strlen(char *str);
char			*my_strdup(char *str);
void                    env_to_list(t_plist *list, char *env);
char			*my_strcat(char *, char *, int, int);
void			clear_list(t_plist *list);
char                    **list_to_env(t_list *tmp, t_list *list);
int                     pars_prompt(t_plist *list, char **env, char *st);
int			my_getnbr(char *str);
int                     prompt(char **env, t_plist *plist);
void                    free_env(char **env);
void                    free_prompt_list(t_pcmd *pcmd, t_cmd *cmd,
					 t_psep *psep, t_sep *sep);
int                     init_prompt_list(t_pcmd *pcmd, t_cmd **cmd,
					 t_psep *psep, t_sep **sep);
int                     init_list(t_plist *plist, t_list **list);
void                    free_list(t_plist *plist, t_list *list);
int			my_strcmp(char *, char *);
char                    **get_path(t_plist *plist);
char                    *test_access(t_plist *plist, char *cmd);
void                    free_path(char **path);
#endif			/* _42_SH_H_ */
