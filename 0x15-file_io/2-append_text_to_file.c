#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * append_text_to_file - Appends text at the end to the  file
 * @filename: Filename
 * @text_content: NULL terminated string to add
 * Return: 1 if its succesful and -1 if not.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, rwr, len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	while (*(text_content + len))
		len++;

	rwr = write(fd, text_content, len);
	close(fd);
	if (rwr < 0)
		return (-1);

	return (1);
}
