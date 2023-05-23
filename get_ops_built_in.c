#include "main.h"
/**
 * get_ops_built_in - checks if a command is a built in and gets the function
 * to be executed for the command
 * @s: command
 * Return: function to be executed for command or null
*/
fexec_built_in_t get_ops_built_in(char *s)
{
	int i;
	built_ins_struct_t built_ins[] = {
		{"alias", NULL},
		{"cd", execute_cd},
		{"exit", execute_exit},
		{"unsetenv", execute_unsetenv},
		{"setenv", execute_setenv},
		{"env", execute_env},
		{NULL, NULL}
	};

	for (i = 0; i < 6; i++)
	{
		if (!_strcmp(built_ins[i].command, s))
			return (built_ins[i].f);
	}
	return (built_ins[i].f);
}
