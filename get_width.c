#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index of the current character in the format string
 * @list: va_list containing the list of arguments
 *
 * Return: Width specifier.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	/* Loop through the characters in the format string after the current index */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the character is a digit */
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		/* Check if the character is '*' which indicates variable width */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int); /* Get the width from the argument list */
			break;
		}
		else
			break; /* Stop if a non-digit and non-'*' character is encountered */
	}

	/* Update the index to skip the processed width specifier characters */
	*i = curr_i - 1;

	return (width);
}

