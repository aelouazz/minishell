#ifndef MINISHELL_H

# define MINISHELL_H

# include "./libft/libft.h"
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <signal.h>

// TODO remove following dep:
# include <stdio.h>
////////////////////////////

# define MAX_PATH 1024

typedef	struct		s_key
{
	char			*key;
	char			*value;
	struct s_key	*next;
}					t_key;

char				*search_env(t_key *env, char *to_search);
t_key				*exec_cmd(char *input, t_key *env);
int					check_builtins(char *cmd);
int					check_file(char *path);
char				**list_env(t_key *env);
void				do_builtins(char ***final, t_key **env, char **input);
void				ft_setenv(t_key ***env, char **final);
void				ft_unsetenv(t_key ***env, char **final);
void				ft_print_env(t_key *env);
void				ft_echo(char **str);
void				ft_cd(char **tab, t_key ***env);

// TODO remove dev Tools: ////////
void		print_key(t_key *env);
//////////////////////////////////

#endif
