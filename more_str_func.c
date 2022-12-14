#include "nice_header.h"

/**
 * _abs - absolute value of an integer
 *
 * @n: int
 * Return: absolute n
 */
int _abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

/**
 * rev_string - reverse a string in the same memory location
 * @s: string
 * Return: nothing
 */
void rev_string(char *s)
{
		char *t;
		int counter = 0, middle, temp, i, j, last, begin;

		for (t = s; *t != '\0'; t++)
			counter++;

		middle = (counter % 2 == 0) ? (counter / 2) : ((counter - 1) / 2);
		j = counter - 1;
		for (i = 0; i < middle; i++)
		{
			last = s[j];
			begin = s[i];
			temp = last;
			s[j] = begin;
			s[i] = temp;
			j--;
		}
}

/**
 * itoa - converts ints to strings
 * @value: Data to be converted
 * @buffer: store the data
 * @base: base to convert
 *
 * Return: string
 */
char *itoa(int value, char *buffer, int base)
{
	unsigned int n = _abs(value);
	unsigned int i = 0;
	unsigned int r;

	if (base < 2 || base > 32)
		return (buffer);

	while (n)
	{
		r = n % base;
		if (r >= 10)
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;
		n /= base;
	}

	if (i == 0)
		buffer[i++] = '0';

	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0';
	rev_string(buffer);
	return (buffer);
}

