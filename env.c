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

int			env_size(t_key *env)
{
	int		i;
	t_key		*tmp;

	i = 0;
	tmp = env;
	while (tmp != NULL && i++)
		tmp = tmp->next;
	return (i);
}

char		**list_env(t_key *env)
{
	t_key		*new_env;
	char	**tab;
	char	*join;
	char	*join2;
	int		i;

	new_env = env;
	tab = NULL;
	if (!(tab = (char **)malloc(sizeof(char *) * (env_size(env) + 1))))
		return (NULL);
	i = -1;
	while (new_env != NULL)
	{
		join = ft_strjoin(new_env->key, "=");
		join2 = ft_strjoin(join, new_env->value);
		free(join);
		tab[++i] = ft_strdup(join2);
		free(join2);
		new_env = new_env->next;
	}
	tab[env_size(env)] = NULL;
	return (tab);
}
