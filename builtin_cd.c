#include "minishell.h"

int			check_open_dir(char *path)
{
	DIR		*dir;

	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	else
	{
		if (errno == ENOENT)
		{
			ft_putstr("cd: No such file or directory: ");
			ft_putendl(path);
		}
		else if (errno == EACCES)
		{
			ft_putstr("cd: Permission denied: ");
			ft_putendl(path);
		}
		return (0);
	}
}

void		set_env_var(t_key ***env, char *key, char *value)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("cd");
	tab[1] = ft_strdup(key);
	tab[3] = NULL;
	if (value)
	{
		tab[2] = ft_strdup(value);
		ft_setenv(env, tab);
	}
	else
	{
		tab[2] = NULL;
		ft_unsetenv(env, tab);
	}
	free_2d(&tab);
}

void		ft_cd(char **tab, t_key ***env)
{
	char	buff[PATH_MAX];

	if (!tab[1])
	{
		if (!search_env(**env, "HOME"))
			ft_putendl("cd: HOME not set");
		else
			chdir(search_env(**env, "HOME"));
	}
	else if (tab[1] && tab[1][0] == '-')
		chdir(search_env(**env, "OLDPWD"));
	else
	{
		if (check_open_dir(tab[1]))
			chdir(tab[1]);
		else
			return ;
	}
	set_env_var(env, "TEMP", search_env(**env, "PWD"));
	set_env_var(env, "PWD", getcwd(buff, PATH_MAX));
	set_env_var(env, "OLDPWD", search_env(**env, "TEMP"));
	set_env_var(env, "TEMP", NULL);
}

