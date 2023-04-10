#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

/**
 * read_textfile - Reads text file & prints to POSIX STDOUT
 * @filename: Filename
 * @Letters: Number of letters to read and print
 * Return: The number of letters it printed, if it fails return 0.
 */
ssize_t read_textfile(const char *filename, size_t Letters)
{
	int fdo, fdr, fdw;
	char *temp;

	if (filename == NULL)
		return (0);

	temp = malloc(sizeof(char) * Letters);
	if (temp == NULL)
		return (0);

	fdo = open(filename, O_RDONLY);
	if (fdo < 0)
	{
		free(temp);
		return (0);
	}

	fdr = read(fdo, temp, Letters);
	if (fdr < 0)
	{
		free(temp);
		return (0);
	}

	fdw = write(STDOUT_FILENO, temp, fdr);
	free(temp);
	close(fdo);

	if (fdw < 0)
		return (0);
	return ((ssize_t)fdw);
}
