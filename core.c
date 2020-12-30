#include "minishell.h"

void		split_env(t_key **new, char **env, int i)
{
	char **tmp;

	(*new)->key = NULL;
	(*new)->value = NULL;
	tmp = ft_strsplit(env[i], '=');
	if (tmp[0])
		(*new)->key = ft_strdup(tmp[0]);
	if (tmp[1])
		(*new)->value = ft_strdup(tmp[1]);
	// TODO free tmp
}

t_key		*get_env(char **env)
{
	int		i;
	t_key	*cur_env;
	t_key	*tmp_env;

	tmp_env = NULL;
	cur_env = NULL;
	if(!(cur_env = (t_key *)malloc(sizeof(t_key))) || env[0] == NULL)
		return (NULL);
	cur_env->next = NULL;
	tmp_env = cur_env;
	i = -1;
	while (env[++i])
	{
		split_env(&tmp_env, env, i);
		if (env[i + 1] == NULL)
			break;
		if (!(tmp_env->next = (t_key *)malloc(sizeof(t_key))))
			return (NULL);
		tmp_env = tmp_env->next;
	}
	tmp_env = NULL;
	return (cur_env);
}



int			main(int argc, char **argv, char **env)
{
	// char	*input;
	t_key	*env_head;

	// input = NULL;
	env_head = NULL;
	(void)argc;
	(void)argv;

	env_head = get_env(env);
	print_key(env_head);

	return (0);
}
