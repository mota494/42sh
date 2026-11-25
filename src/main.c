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

t_list	*new_token(char	*content)
{
	t_list	*toret;

	toret = (t_list	*)calloc(1, sizeof(t_list));
	toret->content = strdup(content);
	toret->next = NULL;
	return (toret);
}

void	parse_dq(char *line, int *i, t_list *tokens)
{
	int	count;

	count = *i;
	while (line[count] != 34 && line[count])
		count++;
}

void	parser(t_state *private, char *line)
{
	int	i = 0;

	while (line[i])
	{
		if (line[i] == 34)
			parse_dq(line, &i, private->tokens);
		i++;
	}
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
			parser(private, line);
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
