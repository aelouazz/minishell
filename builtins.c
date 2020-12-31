#include "minishell.h"

int		check_builtins(char *cmd)
{
	return (!(ft_strcmp(cmd, "cd") || ft_strcmp(cmd, "setenv") ||
		ft_strcmp(cmd, "unsetenv") || ft_strcmp(cmd, "env") ||
		ft_strcmp(cmd, "echo") || ft_strcmp(cmd, "exit")) ? 1 : 0);
}

void	do_builtins(char ***final, t_key **env, char **input)
{
	if (!ft_strcmp((*final)[0], "setenv"))
		ft_setenv(&env, *final);
	if (!ft_strcmp((*final)[0], "unsetenv"))
		ft_unsetenv(&env, *final);
	if (!ft_strcmp((*final)[0], "env"))
		ft_print_env(*env);
	if (!ft_strcmp((*final)[0], "echo"))
		ft_echo(*final);
	if (!ft_strcmp((*final)[0], "cd"))
		ft_cd(*final, &env);
	if (!ft_strcmp((*final)[0], "exit"))
		ft_exit(final, env, input);
}
