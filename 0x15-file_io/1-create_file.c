#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file
 * @filename: Filename
 * @text_content: String in the file
 * Return: 1 if successful, else -1
 */
int create_file(const char *filename, char *text_content)
{
	int fd, rwr, len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);

	while (text_content && *(text_content + len))
		len++;

	rwr = write(fd, text_content, len);
	close(fd);
	if (rwr < 0)
		return (-1);
	return (1);
}
