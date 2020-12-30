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

char		*search_env(t_key *env, char *to_search);

// TODO remove dev Tools: ////////
void		print_key(t_key *env);
//////////////////////////////////

#endif
