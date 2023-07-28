#include "main.h"

/**
 * _printf - Produces output according to a format.
 *
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
{
	int i = 0, chars_printed = 0;
	char buffer[BUFF_SIZE];
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			chars_printed += handle_conversion_specifier(format[i], args, buffer, &i);
		}
		else
		{
			chars_printed += write_char_to_buffer(format[i], buffer, &i);
		}
	}

	va_end(args);
	chars_printed += write_buffer(buffer, &i);
	return (chars_printed);
}

