#include "main.h"

/**
 * write_char_to_buffer - Writes a character to the buffer.
 *
 * @c: The character to write.
 * @buffer: The buffer array to handle print.
 * @i: A pointer to the current index in the buffer.
 *
 * Return: Number of characters written.
 */
int write_char_to_buffer(char c, char buffer[], int *i)
{
	buffer[*i] = c;
	*i += 1;
	if (*i >= BUFF_SIZE - 1)
		return (write_buffer(buffer, i));
	return (1);
}

/**
 * write_str_to_buffer - Writes a string to the buffer.
 *
 * @str: The string to write.
 * @buffer: The buffer array to handle print.
 * @i: A pointer to the current index in the buffer.
 *
 * Return: Number of characters written.
 */
int write_str_to_buffer(char *str, char buffer[], int *i)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
	{
		buffer[*i] = str[j];
		*i += 1;
		if (*i >= BUFF_SIZE - 1)
			return (write_buffer(buffer, i));
	}
	return (j);
}

/**
 * write_buffer - Writes the buffer to the standard output.
 *
 * @buffer: The buffer array to handle print.
 * @i: A pointer to the current index in the buffer.
 *
 * Return: Number of characters written.
 */
int write_buffer(char buffer[], int *i)
{
	int chars_written = 0;

	if (*i > 0)
	{
		buffer[*i] = '\0';
		chars_written = write(1, buffer, *i);
		*i = 0;
	}
	return (chars_written);
}

