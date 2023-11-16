#include "monty.h"

void opcodes(char *line, int num_lines, stack_t **stack);
/**
 * opcodes - Interprets and executes stack-based operations
 * @line: The line of code to interpret
 * @num_lines: The total number of lines
 * @stack: A pointer to the stack
 *
 * Return: void
 */
void opcodes(char *line, int num_lines, stack_t **stack)
{
	unsigned int i = 0, flag = 0;
	char *token = NULL;

	instruction_t op[] = {
		{"pall", h_pall},
		{"pint", h_pint},
		{"pop", h_pop},
		{"swap", h_swap},
		{"add", h_add},
		{"nop", h_nop},
		{"sub", h_sub},
		{"div", h_div},
		{"mul", h_mul},
		{"mod", h_mod},
		{"pchar", h_pchar},
		{"pstr", h_pstr},
		{"rotl", h_rotl},
		{"rotr", h_rotr},
		{NULL, NULL}
	};

	token = strtok(line, " \n\t");
	if (token == NULL)
		return;
	if (token && token[0] == '#')
		return;
	if (strcmp(token, "queue") == 0)
	{
		h.stack = 0;
		return;
	}
	if (strcmp(token, "stack") == 0)
	{
		h.stack = 1;
		return;
	}

	if (strcmp(token, "push") == 0)
	{
		handle_push(strtok(NULL, " \n\t"), stack, num_lines);
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(stack, num_lines);
			flag = 1;
			return;
		}
		i++;
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", num_lines, token);
		free_all();
	}
}
/**
 * handle_push - Handles the push opcode
 * @value: The value to push onto the stack
 * @stack: A pointer to the stack
 * @line_number: the number of line we read
 * Return: void
 */
void handle_push(char *value, stack_t **stack, int line_number)
{
	float floatValue = 0.0;
	int int_value, is_number = 1, i;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all();
		return;
	}
	if (value[0] == '0')
	{
		if (h.stack == 1)
			h_push(stack, 0);
		else
			q_push(stack, 0);
		return;
	}
	for (i = 0; value[i] != '\0'; i++)
	{
		if (!isdigit(value[i]) && value[i] != '-' && value[i] != '.')
		{
			is_number = 0;
			break;
		}
	}

	floatValue = strtof(value, NULL);
	int_value = (int)floatValue;
	if (floatValue != int_value || !is_number)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all();
		return;
	}
	if (h.stack == 1)
		h_push(stack, int_value);
	else
		q_push(stack, int_value);
}

/**
 * free_all - Frees all allocated memory and closes the file
 *
 * Return: void
 */
void free_all(void)
{
	free_stack();
	free(h.line);
	fclose(h.file);
	exit(EXIT_FAILURE);
}
