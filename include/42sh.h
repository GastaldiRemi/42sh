/*
** 42sh.h for 42sh in /home/gastal_r/rendu/42sh/NE_PAS_TOUCHER/include
**
** Made by
** Login   <gastal_r@epitech.net>
**
** Started on  Thu May 26 21:26:35 2016
** Last update Thu Jun  2 00:25:50 2016 
*/

# ifndef		_42_SH_H_
# define		_42_SH_H_

#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<sys/wait.h>
#include		<dirent.h>
#include		<fcntl.h>
#include		<signal.h>

# define SEPARATOR	"&|;"

# define BLEUCLAIR	"\033[01;34m"
# define ROUGE		"\033[00;31m"
# define ROUGEFONCE     "\033[0;31m"
# define SOULIGNE	"\033[04m"
# define NORMAL		"\033[00m"
# define ROSE		"\033[1;31m"
# define VERTFONCE	"\033[0;32m"
# define VERTCLAIR	"\033[1;32m"
# define ORANGE		"\033[0;33m"
# define JAUNE		"\033[1;33m"
# define BLEU		"\033[00;34m"
# define BLEUFONCE	"\033[0;34m"
# define BLEURCLAIR	"\033[1;34m"
# define VIOLETFONCE	"\033[0;35m"
# define VIOLETCLAIR	"\033[1;35m"
# define CYANFONCE	"\033[0;36m"
# define CYANCLAIR	"\033[1;36m"

typedef struct		 s_list
{
  char			*name;
  char			*data;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

typedef struct		s_plist
{
  int			exit_value;
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

typedef struct		s_env
{
  char			**env;
}			t_env;

int			f_slash();
int			f_a();
int			f_b();
int			f_f();
int			f_n();
int			f_r();
int			f_t();
int			f_v();
void			my_putchar(char c);
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
int			echo(char **tab);
char			*my_strcat(char *, char *, int, int);
void			clear_list(t_plist *list);
char                    **list_to_env(t_list *tmp, t_list *list);
int                     pars_prompt(t_plist *plist, t_env *env, char *st);
int			my_getnbr(char *str);
int                     prompt(t_env *env, t_plist *plist);
void                    free_tab(char **env);
void                    free_prompt_list(t_pcmd *pcmd, t_psep *psep);
int                     init_prompt_list(t_pcmd *pcmd, t_psep *psep);
int                     init_list(t_plist *plist, t_list **list);
void                    free_list(t_plist *plist, t_list *list);
int			my_strcmp(char *, char *);
char                    **get_path(t_plist *plist);
char                    *test_access(t_plist *plist, char *cmd);
void                    free_path(char **path);
int			set_env(t_plist *plist, char **cmd);
int			show_list(t_plist *plist);
void                    act_pwd(t_plist *plist, char *path);
char                    *get_oldpwd(t_plist *plist);
char                    *get_pwd(t_plist *plist);
void                    act_oldpwd(t_plist *plist, char *path);
int                     cd_tile(t_plist *plist, char *dir);
void                    cd_prec(t_plist *plist, char *path);
int                     cd_home(t_plist *plist);
int                     cd_dir(t_plist *plist, char *dir);
int                     cd_old(t_plist *plist);
char			*my_realloc(char *, int);
int                     cd_main(t_plist *plist, char **cmd);
int                     double_red_right(t_plist *plist, char **cmd,
					 char **env);
int                     red_right(t_plist *plist, char **cmd, char **env);
char                    **order_args(char **prompt, int i, int j);
int                     system_fonc(t_plist *plist, char **cmd, char **env);
int                     unset_env(t_plist *plist, char **cmd);
int                     red_right(t_plist *plist, char **cmd, char **env);
int                     red_left(char **cmd);
int                     double_red_left(t_plist *plist, char **cmd,
					char **env);
int			launch(t_env *env, t_plist *envlist,
			       t_pcmd *cmd, t_psep *sep);
int                     exec_fonc(char **cmd, char **env);
char                    *pre_parsing(char *prompt, int i, int j);
int                     return_chdir(char *dir, char *newpath);
int                     check_dir(t_plist *plist, char *newpath, char *dir);

#endif			/* _42_SH_H_ */
