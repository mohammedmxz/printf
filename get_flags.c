#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Index of the current character in the format string
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is a flag character */
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				/* Set the corresponding flag bit using bitwise OR */
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		/* If the current character is not a flag character, stop looking for flags */
		if (FLAGS_CH[j] == 0)
			break;
	}

	/* Update the index to skip the processed flag characters */
	*i = curr_i - 1;

	return (flags);
}

