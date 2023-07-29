#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index of the current character in the format string
 *
 * Return: Size specifier.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	/* Check if the current character is 'l' (long) */
	if (format[curr_i] == 'l')
		size = S_LONG;
	/* Check if the current character is 'h' (short) */
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	/* Update the index to skip the processed size specifier characters */
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

