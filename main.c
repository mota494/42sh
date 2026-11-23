#include "header.h"

void	initialize(t_list *tokens, char **envp)
{
	int i = 0;
	tokens = NULL;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

int main(int ac, char **av, char **envp)
{
	(void) av;
	t_list	*tokens;

	if (ac != 1)
	{
		fprintf(stderr, "42sh doesn't take arguments\n");
		return (1);
	}
	initialize(tokens, envp);
}
