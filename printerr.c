#include "main.h"
int print_string(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	write(STDERR_FILENO, s, i);
	return (i);
}

int print_numbers(int k)
{ 
	int kcopy, count = 0, power_10;
	char c;

	kcopy = k;
	for (power_10 = 1; kcopy / 10; kcopy /= 10, power_10 *= 10)
		;
	while (power_10)
	{
		c = ((k / power_10) % 10) + '0';
		write(STDERR_FILENO, &c, 1);
		count++;
		power_10 /= 10;
	}
	return (count);
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
		else if (format[i] == 'd')
			write_count += print_numbers(va_arg(args, int));
	}
	va_end(args);
	return (write_count);
}
