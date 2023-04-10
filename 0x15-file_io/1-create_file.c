#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_file - Creates a file
 * @filename: Filename
 * @text_content: String to write to the file
 * Return: 1 if it is a success and -1 if it fails
 */
int create_file(const char *filename, char *text_content)
{
	int fdo,
	int fdw,
	int len = 0

	if (filename == NULL)
		return (-1);

	fdo = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fdo < 0)
		return (-1);

	while (text_content && *(text_content + len))
		len++;

	fdw = write(fdo, text_content, len);
	close(fdo);
	if (fdw < 0)
		return (-1);
	return (1);
}
