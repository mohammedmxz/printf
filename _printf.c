#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: Format string containing the text and format specifiers.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            /* Store the character in the buffer */
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            /* Increment the number of printed characters */
            printed_chars++;
        }
        else
        {
            /* Print the contents of the buffer if it exists */
            print_buffer(buffer, &buff_ind);
            /* Parse the format specifier and get the relevant information */
            flags = get_flags(format, &i);
            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            size = get_size(format, &i);
            ++i; /* Move past the '%' character */

            if (format[i] == 'r') /* Handle custom format specifier %r */
            {
                /* Print a custom message for %r */
                int written = sprintf(buffer, "Custom format specifier %%r handled!\n");
                buff_ind += written;
                continue;
            }

            /* Call the handle_print function to handle the format specifier */
            printed = handle_print(format, &i, list, buffer,
                flags, width, precision, size);
            /* If handle_print returns -1, there was an error */
            if (printed == -1)
                return (-1);
            /* Increment the number of printed characters */
            printed_chars += printed;
        }
    }

    /* Print any remaining characters in the buffer */
    print_buffer(buffer, &buff_ind);

    va_end(list);

    /* Return the total number of characters printed */
    return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters containing the text to be printed.
 * @buff_ind: Pointer to the index at which to add the next character in the buffer.
 *            Also represents the length of the buffer.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        /* Write the contents of the buffer to the standard output */
        write(1, &buffer[0], *buff_ind);
    }

    /* Reset the buffer index to 0 */
    *buff_ind = 0;
}

