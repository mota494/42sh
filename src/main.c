#include "../inc/header.h"

int exit_code;

void	initialize(t_state *private, char **envp)
{
	(void) envp;

	private->env_table = NULL;
	private->tokens = NULL;
	srand(time(NULL));
}

void	to_history(char *line)
{
	FILE	*hist_file;

	hist_file = fopen(".42sh_hist", "w+");
	fprintf(hist_file, "%s", line);
}

void	main_loop(t_state *private)
{
	char	*line;

	while (1)
	{
		line = readline("42sh> ");
		if (line && strlen(line) > 0)
		{
			to_history(line);
		}
	}
}

int main(int ac, char **av, char **envp)
{
	(void) av;
	t_state	private;

	if (ac != 1)
	{
		fprintf(stderr, "42sh doesn't take arguments\n");
		return (1);
	}
	initialize(&private, envp);
	main_loop(&private);
	return (exit_code);
}
