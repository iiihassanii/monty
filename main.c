#include "monty.h"
h_s h = {NULL, NULL, NULL};
/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, non-zero on failure
 */

int main(int argc, char *argv[])
{
	FILE *file;
	/*check If the user does not give any file*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r"); /*open the file*/
	if (!file || !argv[1]) /*check If, it’s not possible to open the file*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	h.file = file;
	read_line(file);/*start reading*/
	free_stack();
	fclose(file);
	return (0);
}
