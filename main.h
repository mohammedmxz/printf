#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1   /* Flag for left-justification */
#define F_PLUS 2    /* Flag for showing a plus sign for positive numbers */
#define F_ZERO 4    /* Flag for zero-padding */
#define F_HASH 8    /* Flag for alternate form (used with o, x, X) */
#define F_SPACE 16  /* Flag for showing a space before positive numbers */

/* SIZES */
#define S_LONG 2    /* Size specifier for long integers */
#define S_SHORT 1   /* Size specifier for short integers */

/**
 * struct fmt - Format specifier and corresponding handler function
 *
 * @fmt: The format specifier character.
 * @fn: The function pointer to the associated handler function.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Typedef for struct fmt
 *
 * @fmt: The format specifier character.
 * @fm_t: The function pointer to the associated handler function.
 */
typedef struct fmt fmt_t;

/* Main function to print formatted output */
int _printf(const char *format, ...);

/* Handler functions for printing characters, strings, and percent sign */
int handle_print_char(va_list types, char buffer[], int *i);
int handle_print_string(va_list types, char buffer[], int *i);
int handle_print_percent(char buffer[], int *i);
int handle_print_unknown(char buffer[], int *i);

/* Helper functions for writing characters and strings to the buffer */
int write_char_to_buffer(char c, char buffer[], int *i);
int write_str_to_buffer(char *str, char buffer[], int *i);
int write_buffer(char buffer[], int *i);

#endif /* MAIN_H */

