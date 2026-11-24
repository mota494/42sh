#include "header.h"

void	free_env(t_env *env_table)
{
	t_env *tmp;

	while (env_table)
	{
		tmp = env_table;
		env_table = env_table->next;
		free(tmp->env_name);
		free(tmp->env_value);
		free(tmp);
	}

	free(env_table);
}

void	print_env(t_env *env_table)
{
	t_env	*to_print;

	to_print = env_table;

	while(to_print)
	{
		printf("%s=%s\n", to_print->env_name, to_print->env_value);
		to_print = to_print->next;
	}
}

t_env	*create_newenv(void *name, void *value)
{
	t_env	*new_node;
	
	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return NULL;
	new_node->env_name = strdup(name);
	if (!value)
		new_node->env_value = strdup("\0");
	else
		new_node->env_value = strdup(value);
	new_node->next = NULL;

	return new_node;
}

t_env	*find_envtail(t_env *env_table)
{
	if (env_table)
	{
		while (env_table->next != NULL)
			env_table = env_table->next;
		return env_table;
	}
	return NULL;
}

void	addenv_back(t_env **head, t_env *newenv)
{
	t_env	*tail;

	if (!newenv)
		return;
	if (!*head)
	{
		*head = newenv;
		return ;
	}

	tail = find_envtail(*head);
	tail->next = newenv;
}

void	start_env(t_env **env_table, char **envp)
{
	char	buf[PATH_MAX];
	char	*name;
	char	*value;
	t_env	*newenv;
	int		i = 0;
	int		len = 0;

	if (!*envp){
		getcwd(buf, sizeof(buf));
		name = malloc(sizeof("PWD") + 1);
		strcpy(name, "PWD");
		newenv = create_newenv(name, buf);
		addenv_back(env_table, newenv);
		return ;
	}
	while (envp[i])
	{
		if ((len = strchr(envp[i], '=') - envp[i]))
		{
			name = malloc(len + 1);
			memcpy(name, envp[i], len);
			name[len] = '\0';
			
			value = malloc(strlen(strchr(envp[i], '=')));
			memcpy(value, envp[i] + len + 1, strlen(strchr(envp[i], '=')));

			newenv = create_newenv(name, value);
			addenv_back(env_table, newenv);
			free(name);
			free(value);
		}
		i++;
	}
}
