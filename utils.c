#include "minishell.h"

void		check_file_perm(char *path)
{
	if (check_file(path))
	{
		if (access(path, X_OK))
			mini_printf("%s: Permission Denied.\n", path);
	}
	else
		mini_printf("%s: Command not found.\n", path);
}

int			check_file(char *path)
{
	if (access(path, F_OK) != -1)
		return (1);
	return (0);
}

void		split_them(t_key **fresh, char **env, int index)
{
	char	**temp;

	temp = ft_strsplit(env[index], '=');
	(*fresh)->key = NULL;
	(*fresh)->value = NULL;
	(*fresh)->key = ft_strdup(temp[0]);
	if (temp[1])
		(*fresh)->value = ft_strdup(temp[1]);
	free_2d(&temp);
}
