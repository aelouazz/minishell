#include "minishell.h"

t_key			*exec_cmd(char *input, t_key *env)
{
	char	**final;
	char	**envi;
	char	*path;

	final = NULL;
	path = NULL;
	if (!(final = ft_strsplitstr(input, " \t\n\r\a\"")))
		return (env);
	expansions(&final, env);
}
