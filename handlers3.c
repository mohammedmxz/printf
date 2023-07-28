#include "main.h"

/**
 * write_integer_to_buffer - Writes an integer to the buffer.
 * @num: The integer to write.
 * @buffer: The buffer to write to.
 * @index: The current index in the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int write_integer_to_buffer(int num, char buffer[], int *index)
{
	int chars_printed = 0;
	int sign = 0;
	unsigned int n;

	if (num < 0)
	{
		sign = 1;
		n = -num;
	}
	else
	{
		n = num;
	}

	chars_printed = write_unsigned_to_buffer(n, buffer, index);

	if (sign)
		chars_printed += write_char_to_buffer('-', buffer, index);

	return (chars_printed);
}

/**
 * write_unsigned_to_buffer - Writes an unsigned integer to the buffer.
 * @num: The unsigned integer to write.
 * @buffer: The buffer to write to.
 * @index: The current index in the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int write_unsigned_to_buffer(unsigned int num, char buffer[], int *index)
{
	int chars_printed = 0;
	char digit;

	if (num == 0)
		chars_printed += write_char_to_buffer('0', buffer, index);

	while (num != 0)
	{
		digit = (num % 10) + '0';
		chars_printed += write_char_to_buffer(digit, buffer, index);
		num /= 10;
	}

	return (chars_printed);
}

/**
 * write_octal_to_buffer - Writes an unsigned integer as octal to the buffer.
 * @num: The unsigned integer to write.
 * @buffer: The buffer to write to.
 * @index: The current index in the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int write_octal_to_buffer(unsigned int num, char buffer[], int *index)
{
	int chars_printed = 0;
	char octal_digit;

	if (num == 0)
		chars_printed += write_char_to_buffer('0', buffer, index);

	while (num != 0)
	{
		octal_digit = (num % 8) + '0';
		chars_printed += write_char_to_buffer(octal_digit, buffer, index);
		num /= 8;
	}

	return (chars_printed);
}

/**
 * write_hex_to_buffer - Writes an unsigned integer as hexadecimal to the buffer.
 * @num: The unsigned integer to write.
 * @uppercase: A flag to specify whether to use uppercase for hexadecimal letters.
 * @buffer: The buffer to write to.
 * @index: The current index in the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int write_hex_to_buffer(unsigned int num, int uppercase, char buffer[], int *index)
{
	int chars_printed = 0;
	char hex_digit;

	if (num == 0)
		chars_printed += write_char_to_buffer('0', buffer, index);

	while (num != 0)
	{
		int remainder = num % 16;
		if (remainder < 10)
			hex_digit = remainder + '0';
		else
			hex_digit = (uppercase ? 'A' : 'a') + (remainder - 10);
		chars_printed += write_char_to_buffer(hex_digit, buffer, index);
		num /= 16;
	}

	return (chars_printed);
}

/**
 * write_pointer_to_buffer - Writes a pointer address to the buffer.
 * @addr: The address to write.
 * @buffer: The buffer to write to.
 * @index: The current index in the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int write_pointer_to_buffer(unsigned long addr, char buffer[], int *index)
{
	int chars_printed = 0;

	chars_printed += write_char_to_buffer('0', buffer, index);
	chars_printed += write_char_to_buffer('x', buffer, index);

	chars_printed += write_hex_to_buffer(addr, 1, buffer, index);

	return (chars_printed);
}

