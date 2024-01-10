#include "shell.h"

/**
 * prompt - This function checks whether the shell is in interactive mode by
 * examining the file descriptor's information. If it's in interactive mode
 * (determined by checking if the file is a character special file),
 * it prints the shell prompt.
 * The fd parameter represents the file descriptor associated with the file,
 * and buf is a structure containing information about the file, obtained
 * using the fstat function.
 * if (S_ISCHR(buf.st_mode)): Checks if the file is a character special file
 * (typically a terminal) by using the S_ISCHR macro.
 * @fd: File stream (file descriptor).
 * @buf: Buffer containing information about the file.
 */
void prompt(int fd, struct stat buf)
{
	/* Use the fstat function to get information about the file */
	/*  associated with the file descriptor (fd). */
	fstat(fd, &buf);
	/* Check if the file is a character special file */
	/*  (character device, like a terminal). */
	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT); /* If it's character special file print shell */
}

/**
 * _puts -  function to print the shell prompt (defined elsewhere
 * in the code as PROMPT).
 * Calculates the length of the input string using str_len.
 * Uses the write function to print the string to the standard output.
 * @str: String to print.
 * Return: void
 */
void _puts(char *str)
{
	unsigned int length;
	/* Calculate the length of the input string. */
	length = strlen(str);
	/* Use the write function to print the string to */
	/* the standard output (STDOUT_FILENO). */
	write(STDOUT_FILENO, str, length);
}

#include "shell.h"

/**
 * get_line - This function is responsible for reading line of input from user.
 * It takes a file stream (fp) as an argument, which allows it to read from
 * eitherstdin or a file, depending on usage.
 * line is a pointer that will point to buffer where the user input is stored.
 * read is a variable that holds the number of characters read. It is of
 * type ssize_t, which is a signed size type.
 * len is the length of the buffer. It starts with an initial value of 0.
 * The getline function is used to read a line from the file stream (fp).It
 * dynamically allocates memory for line and updates
 * len with the size of the allocated buffer.
 * If getline encounters an error or reaches the end of the file,
 * it returns -1, and thefunction frees the memory allocated for
 * line and exits the program with a success status.
 * If successful, the function returns the buffer line containing user input.
 * @fp: File stream (stdin or a file, depending on usage).
 * Return: The buffer containing user input.
 */

char *get_line(FILE *fp)
{
	char *line;         /* Pointer to the buffer for user input*/
	ssize_t read;       /* Number of characters read, signed size type */
	size_t len;         /* Length of the buffer */

	line = NULL;  /* Initialize line to NULL to avoid undefined behavior */
	len = 0;            /* Initialize len to 0 */
	/* Read a line of input from the user into the buffer 'line' */
	read = getline(&line, &len, fp);
	/* Check if getline encountered an error or reached the end of file */
	if (read == -1)
	{
		free(line);     /* Free the memory allocated for the buffer */
		exit(EXIT_SUCCESS); /* Exit the program with success status */
	}
	return (line);      /* Return the buffer containing the user input */
}
