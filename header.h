#ifndef HEADER_H 
# define HEADER_H

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

typedef struct s_list
{
	struct s_list	*next;
} t_list;

typedef struct	s_env
{
	char			*env_key;
	char			*env_value;
	struct s_env	*next;
}	t_env;

#endif
