#include "minishell.h"

void		tilda(char **tab, t_key *env)
{
	char	*home;
	char	*res;

	home = NULL;
	res = NULL;
	home = search_env(env, "HOME");
	res = ft_strjoin(home, &(*tab)[1]);
	free(*tab);
	*tab = ft_strdup(res);
	free(res);
}

int			check_symb(char *str, int index)
{
	while (str[index] && ft_isalnum(str[index]))
		index++;
	return (index);
}

void		dollar(char *tab, t_key *env, char **new_str, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*var;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '$' && tab[i + 1])
		{
			var = ft_strsub(tab, i, check_symb(tab, i + 1) - i);
			if (search_env(env, ft_strchr(var, '$') + 1))
				tmp = ft_strdup(search_env(env, ft_strchr(var, '$') + 1));
			else
				tmp = ft_strdup("");
		}
		else
			tmp = ft_strsub(tab, i, check_symb(tab, i + 1) - i);
		tmp2 = ft_strdup(*new_str);
		ft_strdel(&(*new_str));
		(*new_str) = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		i = check_symb(tab, i + 1);
	}
}

void		expansions(char ***tab, t_key *env)
{
	int		i;
	char	*new_str;

	i = 0;
	while ((*tab)[i] != NULL)
	{
		if ((*tab)[i][0] == '~' && ((*tab)[i][1] == '/' || !(*tab)[i][1]))
		{
			tilda(&(*tab)[i], env);
		}
		else
		{
			new_str = ft_strdup("");
			dollar((*tab)[i], env, &new_str, 0);
			ft_strdel(&(*tab)[i]);
			(*tab)[i] = ft_strdup(new_str);
			ft_strdel(&new_str);
		}
		i++;
	}
}
