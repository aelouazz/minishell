#include "minishell.h"

void		free_list(t_key **env)
{
	t_key		*tmp;

	while ((*env) != NULL)
	{
		tmp = *env;
		(*env) = (*env)->next;
		ft_strdel(&tmp->key);
		ft_strdel(&tmp->value);
		free(tmp);
	}
}

void		ft_exit(char ***final, t_key **env, char **input)
{
	free_2d(final);
	ft_strdel(input);
	free_list(env);
	exit(0);
}

void		ft_print_env(t_key *env)
{
	t_key *tmp;

	tmp = env;
	while (tmp != NULL)
	{
		ft_putstr(tmp->key);
		ft_putstr("=");
		ft_putstr(tmp->value);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}
