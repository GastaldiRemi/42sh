/*
** minishell1.h for minishell1 in /home/roig_a/rendu/getnextline/PSU_2015_minishell1/include
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Mon Jan  4 15:35:12 2016 Antoine Roig
** Last update Sun Apr 10 05:14:33 2016 Antoine Roig
*/

#ifndef MINISHELL1_H_
# define MINISHELL1_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_path
{
  char	**env;
  char	**path;
  int	i;
}		t_path;

typedef struct          s_list
{
  char                  *variablenv;
  char                  *valuenv;
  struct s_list         *next;
  struct s_list         *prev;
}		        t_list;

typedef struct          s_dlist
{
  t_list                *begin;
  t_list                *end;
  int                   size;
}			t_dlist;

typedef struct          s_linenv
{
  char                  *variable;
  char                  *value;
}		       t_linenv;

typedef struct          s_instruct
{
  char                  *cmd;
  char                  **args;
}			t_instruct;

typedef struct		s_inst
{
  t_instruct		*inst;
  struct s_inst         *next;
  struct s_inst         *prev;

}			t_instructions;

typedef struct		s_instructions
{
  t_instructions        *begin;
  t_instructions        *end;
  int                   size;
}			t_dinstructions;

typedef struct  s_var
{
  char          *s_tmp;
  char          *tmp;
  int           i;
  char          *keep;
  char          *buff;
  char          *save_stat;
}               t_var;

typedef struct	s_ret
{
  int	ret;
  int	ex;
}		t_ret;

#define READ_SIZE       1
#define SIZE_PWD        20

char    **init_list_env(t_dlist *list_env, char **env);
void    add_list_end(t_dlist *list, char *variable, char *value);
void    add_list_end_inst(t_dinstructions *list_instruct, t_instruct *instru);
t_list	*pop_list_begin(t_dlist *list);
t_list	*pop_list_end(t_dlist *list);
t_list  *pop_list_somewhere2(t_dlist *list, int pos);
t_list  *pop_list_somewhere(t_dlist *list, int pos);
t_instructions  *pop_list_begin_inst(t_dinstructions *list);
void	*xmalloc(int size);
void	show_list(t_dlist *list);
void    new_list_instruct(t_dinstructions **instruct);
void	new_list(t_dlist **list);
void	clear_list(t_dlist *list);
void	rev_list(t_dlist *list);
char    *my_strdup_o(char *src);
int     my_show_wordtab(char **tab);
char    *my_strcpy(char *dest, char *src);
char    *my_strcat(char *dest, char *src);
int     my_putstr(char *str);
int     my_strcmp(char *s1, char *s2);
int     count_word(char *str);
char    **my_str_to_wordtab_path(char *str);
char    **my_str_to_wordtab(char *str);
int	my_strlen(char *str);
char    **search_path(t_dlist *list);
char	*my_epurstr(char *str);
char    *get_instruct(int fd);
void    prepare_list_instruct(t_dinstructions *list_instruct,
			      char *instruct, int i);
char    *get_next_line(const int fd);
int     search_cmd(t_instruct *, char **path, char **env, t_dlist *list);
void    free_path(char **path);
t_ret	*builtin_exit(t_instruct *line, t_ret *);
int     builtin_setenv(t_instruct *line, t_dlist *list, char **env);
int     builtin_unsetenv(t_instruct *line, t_dlist *list);
int     builtin_env(char **env);
int     builtin_cd(t_instruct *line, t_dlist *list);
char    *get_user(t_dlist *list);
int     change_pwd(t_dlist *list);
int     change_pwd2(char *buff, t_dlist *list);
int     builtin_setenv(t_instruct *line, t_dlist *list, char **env);
int     builtin_unsetenv(t_instruct *line, t_dlist *list);
int     builtin_env(char **env);
int     builtin_cd(t_instruct *line, t_dlist *list);
int     my_getnbr(char *str);
int    end(t_dlist *list);
int     check_variable(char *variable, char *value, t_dlist *list);
t_dlist *unset_env(t_instruct *line, t_dlist *list);
void    cd_error(t_instruct *line);
void    just_cd_error();
int     just_cd(t_dlist *list);
int     go_old(t_dlist *list);
void    go_old_2(t_dlist *list, char *old_pwd);
void    exec_cmd_2(t_instruct *line, int pid, char **env, char **path);
int    exec_cmd_2_unknown(char *cmd);
int	check_redir(t_instruct *line);
int	check_redir2(t_instruct *line);
int	check_redir_g(t_instruct *line);
int	check_redir_dg(t_instruct *line, int i);
int	check_pipe(t_instruct *line,  char **env, char **path);
char	*without_space_pipe(char *str, int, int);
char	*without_space_dredd(char *str, int , int);
char	*without_space_redd(char *str, int, int);
char	*without_space_redg(char *str, int , int);
int	cmd_check(t_instruct *line, pid_t pid, char **env, char **path);
int	init_pid(int fd);
char   **list_to_env(t_dlist *list);
char	**init_env(t_dlist *, char **env, int , char **);
void	init(int ac, char **av);
t_ret	*ride(t_dinstructions *list_instruct, char **my_env,
	      t_dlist *list_env, char**path);
#endif
