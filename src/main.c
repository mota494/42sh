#include "header.h"


/*
 * TODO:change getlogin() for a const value in a struct for user
 *		til has priority for example HOME 1st then getpwnam_r	
 */
char	*get_til(t_env *env_table)
{
	char	*toret;
	t_env	*tmp;
	
	tmp = env_table;
	if (tmp){
		while (tmp){
			if (strncmp(tmp->env_name, "HOME", sizeof("HOME")) == 0){
				toret = strdup(tmp->env_value);
				return toret;
			}
			tmp = tmp->next;
		}
	}
		
	struct passwd pwd;
	struct passwd *result;
	char *buf;
	size_t bufsize;
	int status;
	
	bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
	buf = malloc(bufsize);
	status = getpwnam_r(getlogin(), &pwd, buf, bufsize, &result);
	if (result == NULL){
		if (status != 0)
			errno = status;		
		return NULL;
	}
	toret = strdup(pwd.pw_dir);
	free(buf);
	return (toret);
}

// void	builtin_cd(char *path)
// {
// 	
// }

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
	// print_env(list.env);
	char *home_dir;
	home_dir = get_til(list.env);
	printf("%s\n", home_dir);
	free_env(list.env);
	free(home_dir);
	return (0);
}
