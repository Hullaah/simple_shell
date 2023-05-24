#include "main.h"
int print_string(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		write(STDERR_FILENO, &s[i], 1);
	}
	return (i);
}

/**
 * _printf - works just like the standard library printf
 * @format: format specifier
 * Return: number of bytes written to standard output
*/
int printerr(char *format, ...)
{
	int write_count = 0, i;
        char c;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			c = format[i];
			write(STDERR_FILENO, &c, 1);
			i++;
			write_count++;
		}
		if (format[i] == '\0')
			return (write_count);
		i++;
		if (format[i] == 's')
			write_count += print_string(va_arg(args, char *));
	}
	va_end(args);
	return (write_count);
}
