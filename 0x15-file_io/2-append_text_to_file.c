#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: file to append the text to
 * @text_content: content to append into the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, text_length = 0;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[text_length])
			text_length++;
		write_status = write(file_descriptor, text_content, text_length);
		if (write_status != text_length)
			return (-1);
	}

	close(file_descriptor);

	return (1);
}
