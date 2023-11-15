#include "monty.h"

/**
 * read_line - Reads lines from a file
 * @file: Pointer to the file to read from
 *
 * This function reads lines from the provided file and performs
 * the necessary operations on each line.
 */
void read_line(FILE *file)
{
	int num_lines = 1;
	size_t n = 0;
	char *line = NULL;
	stack_t *stack = NULL;

	while (getline(&line, &n, file) != -1)
	{
		h.line = line;
		opcodes(line, num_lines, &stack);
		num_lines++;
	}
	free(line);
}
