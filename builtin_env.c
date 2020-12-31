#include "minishell.h"

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
