#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index of the current character in the format string
 * @list: List of arguments to be printed
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	/* Check if there is a precision specifier in the format string */
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	/* Parse the precision value from the format string */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is a digit */
		if (is_digit(format[curr_i]))
		{
			/* Calculate the precision by converting digits to an integer */
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*') /* Handle precision as an argument */
		{
			curr_i++; /* Move to the next character after '*' */
			precision = va_arg(list, int); /* Get the precision from the argument list */
			break;
		}
		else
			break; /* Stop parsing if the character is not a digit or '*' */
	}

	/* Update the index to skip the processed precision specifier characters */
	*i = curr_i - 1;

	return (precision);
}

