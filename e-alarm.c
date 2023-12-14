#include "yukd_shell.h"

/**
 *_yuputs - prints an input string for purposes
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _yuputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_yuputchar(str[i]);
		i++;
	}
}


/**
 * _yuputfd - writes the character c to givenkkc
 * @kkc: The filedescriptor to write to
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _yuputfd(char c, int kkc)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write (kkc, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}


/**
 *_yuputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _yuputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @kkc: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int kkc)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _yuputfd(*str++,kkc);
	}
	return (i);
}
