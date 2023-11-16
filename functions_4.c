#include "monty.h"
/**
 * h_pchar - prints the char at the top of the stack
 * @stack: A pointer to the stack
 * @line_number: the line number
 *
 * Return: void
 */
void h_pchar(stack_t **stack, unsigned int line_number)
{
	h.head = *stack;

	if (!h.head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		return;
	}
	if (h.head->n > 127 || h.head->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_all();
		return;
	}
	printf("%c\n", h.head->n);
}
/**
 * h_pstr - prints the string
 * @stack: A pointer to the stack
 * @line_number: the number of line
 *
 * Return: void
 */
void h_pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	h.head = *stack;

	while (h.head)
	{
		if (h.head->n > 127 || h.head->n < 1)
			break;
		printf("%c", h.head->n);
		h.head = h.head->next;
	}
	printf("\n");
}
