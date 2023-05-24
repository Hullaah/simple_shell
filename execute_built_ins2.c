#include "main.h"
int execute_built_in(envlist_t **envlist, char **vector)
{
	fexec_built_in_t built_in;
	int ret;

	built_in  = get_ops_built_in(vector[0]);
	if (built_in)
	{
		ret = built_in(vector, envlist);
		if (!_strcmp(vector[0], "exit") || !_strcmp(vector[0], "cd"))
			return (ret);
		return (0);
	}
	return (1);
}