#include "minishell.h"

int		check_builtins(char *cmd)
{
	return (!(ft_strcmp(cmd, "cd") || ft_strcmp(cmd, "setenv") ||
		ft_strcmp(cmd, "unsetenv") || ft_strcmp(cmd, "env") ||
		ft_strcmp(cmd, "echo") || ft_strcmp(cmd, "exit")) ? 1 : 0);
}

void		ft_setenv(t_key ***env, char **final)
{
	int		i;

	i = 1;
	while (final[i])
		i++;
	if ((i - 1) != 2)
	{
		ft_putendl("Too few, many arguments.");
		return ;
	}
	if (!search_env(**env, final[1]))
		ft_lsta(&env, final[1], final[2]);
	else
		ft_lstreplace(&env, final[1], final[2]);
}

void	do_builtins(char ***final, t_key **env, char **input)
{
	if (!ft_strcmp((*final)[0], "setenv"))
		ft_setenv(&env, *final);
	if (!ft_strcmp((*final)[0], "unsetenv"))
		ft_unsetenv(&env, *final);
	if (!ft_strcmp((*final)[0], "env"))
		ft_env(*env);
	if (!ft_strcmp((*final)[0], "echo"))
		ft_echo(*final);
	if (!ft_strcmp((*final)[0], "cd"))
		ft_cd(*final, &env);
	if (!ft_strcmp((*final)[0], "exit"))
		ft_exit(final, env, input);
}
