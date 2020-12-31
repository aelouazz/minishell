#include "minishell.h"

char		*find_binary(char *cmd, char *path_env)
{
	char	**tab;
	char	*tmp;
	char	*tmp2;
	int		i;

	if (!(tab = ft_strsplit(path_env, ':')))
		return (NULL);
	i = -1;
	tmp = NULL;
	tmp2 = NULL;
	while (tab[++i])
	{
		tmp = ft_strjoin(tab[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (check_file(tmp2) && free_2d(&tab))
			return (tmp2);
		free(tmp2);
	}
	free_2d(&tab);
	return (NULL);
}

void		execute(char **final, char *cmd, char **a_env)
{
	int		pid;

	if ((pid = fork()))
		wait(0);
	else
	{
		if (execve(cmd, final, a_env) == -1)
		{
			check_file_perm(final[0]);
			exit(0);
		}
	}
}

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
	if (!check_builtins(final[0]))
	{
		if (!(check_file(final[0])) && !(final[0][0] == '.'))
			path = find_binary(final[0], search_env(env, "PATH"));
		else
			path = ft_strdup(final[0]);
		envi = list_env(env);
		execute(final, path, envi);
		free(path);
		free_2d(&envi);
	}
	else
		do_builtins(&final, &env, &input);
	free_2d(&final);
	return (env);
}
