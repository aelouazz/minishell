#include "minishell.h"

char		*search_env(t_key *env, char *to_search)
{
	t_key		*new;

	new = env;
	while (new != NULL)
	{
		if (!(ft_strcmp(new->key, to_search)))
			return (new->value);
		new = new->next;
	}
	return (NULL);
}

