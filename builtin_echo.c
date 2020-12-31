#include "minishell.h"

void	ft_echo(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		mini_printf("%s", str[i]);
		if (str[i + 1] != NULL)
			mini_printf(" ");
		i++;
	}
	mini_printf("\n");
}
