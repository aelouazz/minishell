#ifndef MINISHELL_H

# define MINISHELL_H

# include "./libft/libft.h"
# include <errno.h>
# include <string.h>
# include <dirent.h>
// TODO remove following dep:
# include <stdio.h>

typedef	struct		s_key
{
	char			*key;
	char			*value;
	struct s_key	*next;
}					t_key;


// TODO remove dev Tools:
void		print_key(t_key *env);


#endif
