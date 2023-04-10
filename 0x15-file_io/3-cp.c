#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

int safe_close(int);
/**
 * main - Main function to copy files
 * @argc: num of args passed
 * @argv: argument vector
 * file_from: file_from
 * file_to: file_to
 * Return: 1 if succesful and exit if not
 */
int main(int argc, char *argv[])
{
	char buffer[1024];
	int bytes_read = 0, _EOF = 1, from_fd = -1, to_fd = -1, error = 0;

	if (argc != 4)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(96);
	}

	from_fd = open(argv[1], O_RDONLY);
	if (from_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	to_fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (to_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		safe_close(from_fd);
		exit(99);
	}

	while (_EOF)
	{
		_EOF = read(from_fd, buffer, 1024);
		if (_EOF < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			safe_close(from_fd);
			safe_close(to_fd);
			exit(98);
		}
		else if (_EOF == 0)
			break;
		bytes_read += _EOF;
		error = write(to_fd, buffer, _EOF);
		if (error < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			safe_close(from_fd);
			safe_close(to_fd);
			exit(99);
		}
	}
	error = safe_close(to_fd);
	if (error < 0)
	{
		safe_close(from_fd);
		exit(100);
	}
	error = safe_close(from_fd);
	if (error < 0)
		exit(100);
	return (0);
}

/**
 * safe_close - Closes a file and prints error when closed file
 * @descr: Description
 * Return: 1 if succesful and -1 if not
 */
int safe_close(int descr)
{
	int errorMessage;

	errorMessage = close(descr);
	if (errorMessage < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", descr);
	return (errorMessage);
}
