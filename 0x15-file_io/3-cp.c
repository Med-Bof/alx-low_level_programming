#include "main.h"

/**
 * print_error_and_exit - Prints an error message and exits.
 * @exit_code: The exit code to use.
 * @msg: The error message to print.
 * @file: The filename related to the error.
 */
void print_error_and_exit(int exit_code, const char *msg, const char *file)
{
	dprintf(STDERR_FILENO, msg, file);
	exit(exit_code);
}

/**
 * close_file_descriptor - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 */
void close_file_descriptor(int fd)
{
	if (close(fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file_content - Copies content from source file to destination file.
 * @source_fd: The file descriptor of the source file.
 * @dest_fd: The file descriptor of the destination file.
 */
void copy_file_content(int source_fd, int dest_fd)
{
	char buffer[BUFSIZ];
	ssize_t read_bytes;

	while ((read_bytes = read(source_fd, buffer, BUFSIZ)) > 0)
	{
		if (write(dest_fd, buffer, read_bytes) != read_bytes)
			print_error_and_exit(99, "Error: Can't write to %s\n", NULL);
	}

	if (read_bytes < 0)
		print_error_and_exit(98, "Error: Can't read from file %s\n", NULL);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd;

	if (argc != 3)
		print_error_and_exit(97, "Usage: cp file_from file_to\n", NULL);

	source_fd = open(argv[1], O_RDONLY);
	if (source_fd < 0)
		print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);

	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (dest_fd < 0)
	{
		close_file_descriptor(source_fd);
		print_error_and_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	copy_file_content(source_fd, dest_fd);

	close_file_descriptor(source_fd);
	close_file_descriptor(dest_fd);

	return (0);
}
