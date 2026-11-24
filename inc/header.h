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
# include <unistd.h>


/**
 * @brief Represents the enviromental variables
 *
 * Environment variable names used by the utilities in the Shell and Utilities volume of
 * POSIX.1-2017 consist solely of uppercase letters, digits, and the <underscore> ( '_' )
 * from the characters defined in Portable Character Set and do not begin with a digit 
 */
typedef struct	s_env
{
	char			*env_name;
	char			*env_value;
	struct s_env	*next;
}	t_env;

typedef struct s_list
{
	struct s_list	*next;
	t_env			*env;
} t_list;

#endif
