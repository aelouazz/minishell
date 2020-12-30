#include "minishell.h"

void		print_key(t_key *env)
{
	// TODO remove following ////////////////////////////
	while (env->value)
	{
		printf("[+] =>> Key: %s\n", env->key);
		printf("[+] =>> Value: %s\n----\n", env->value);
		if (env->next == NULL) break;
		env= env->next;
	}
	//////////////////////////////////////////////////////
}
