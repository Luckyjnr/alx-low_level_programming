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
	int fdo;
	int fdw;
	int len;

	if (filename == NULL)
		return (-1);

	fdo = open(filename, O_CREAT | O_CREAT | O_TRUNC, 0600);
	if (fdo == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (fdw = 0; text_content[fdw]; fdw++)
		;
	len = write(fdo, text_content, fdw);
	if (len == -1)
		return (-1);
	close(fdo);

	return (1);
}
