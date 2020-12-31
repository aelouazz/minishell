#include "minishell.h"

void		env_list_add(t_key ****env, char *key, char *value)
{
	t_key		*new_node;
	t_key		*last;

	new_node = (t_key *)malloc(sizeof(t_key));
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	last = ***env;
	if (***env == NULL)
	{
		***env = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return ;
}

void		env_list_replace(t_key ****env, char *key, char *value)
{
	t_key		*fresh;

	fresh = ***env;
	while (fresh != NULL)
	{
		if (!ft_strcmp(fresh->key, key))
		{
			free(fresh->value);
			fresh->value = ft_strdup(value);
		}
		fresh = fresh->next;
	}
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
		env_list_add(&env, final[1], final[2]);
	else
		env_list_replace(&env, final[1], final[2]);
}
