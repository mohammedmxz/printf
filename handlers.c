#include "main.h"

/**
 * handle_print_char - Handles the printing of a character.
 *
 * @types: A va_list of arguments.
 * @buffer: The buffer array to handle print.
 * @i: A pointer to the current index in the buffer.
 *
 * Return: Number of characters printed.
 */
int handle_print_char(va_list types, char buffer[], int *i)
{
	char c = va_arg(types, int);
	return (write_char_to_buffer(c, buffer, i));
}

/**
 * handle_print_string - Handles the printing of a string.
 *
 * @types: A va_list of arguments.
 * @buffer: The buffer array to handle print.
 * @i: A pointer to the current index in the buffer.
 *
 * Return: Number of characters printed.
 */
int handle_print_string(va_list types, char buffer[], int *i)
{
	char *str = va_arg(types, char *);
	if (!str)
		str = "(null)";
	return (write_str_to_buffer(str, buffer, i));
}

/**
 * handle_print_percent - Handles the printing of a percent sign.
 *
 * @buffer: The buffer array to handle print.
 * @i: A pointer to the current index in the buffer.
 *
 * Return: Number of characters printed.
 */
int handle_print_percent(char buffer[], int *i)
{
	return (write_char_to_buffer('%', buffer, i));
}

/**
 * handle_print_unknown - Handles the printing of unknown format specifiers.
 *
 * @buffer: The buffer array to handle print.
 * @i: A pointer to the current index in the buffer.
 *
 * Return: Number of characters printed.
 */
int handle_print_unknown(char buffer[], int *i)
{
	*i -= 1; /* Move back to the '%' sign */
	return (write_char_to_buffer('%', buffer, i));
}

