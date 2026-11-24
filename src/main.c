#include "header.h"

void	initialize(t_list *list)
{
	list->env = NULL;
}

int main(int ac, char **av, char **envp)
{
	(void) av;
	t_list	list;

	if (ac != 1)
	{
		fprintf(stderr, "42sh doesn't take arguments\n");
		return (1);
	}
	initialize(&list);
	start_env(&list.env, envp);
	print_env(list.env);
	free_env(list.env);
	return (0);
}
