#ifndef HEADER_H 
# define HEADER_H

# include <assert.h>
# include <sys/stat.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>

typedef enum e_types
{
	string,
	pipes, // |
	command,
	builtin,
	control, // ; && ||
	redirect, // < > << >> >& <& can be precedeed by digits
	file,
	folder,
	error,
}	t_types;

typedef struct s_list
{
	char			*content;
	t_types			type;
	int				pos;
	struct s_list	*next;
} t_list;

typedef struct	s_env
{
	char			*env_key;
	char			*env_value;
	struct s_env	*next;
}	t_env;

typedef struct	s_state
{
	t_list	*tokens;
	t_env	*env_table;
}	t_state;

#endif
