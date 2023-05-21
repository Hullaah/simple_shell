#include "main.h"

fexec_built_ins_t get_ops_built_in(char *s)
{
	int i;
	built_ins_struct_t built_ins[] = {
		{"alias", NULL},
		{"cd", NULL},
		{"exit", NULL},
		{"unsetenv", NULL},
		{"setenv", NULL},
		{"env", NULL},
		{NULL, NULL}
	};

	for (i = 0; i < 6; i++)
	{
		if (!_strcmp(built_ins[i].command, s))
			return (built_ins[i].f);
	}
	return (built_ins[i].f);
}
