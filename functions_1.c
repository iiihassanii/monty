#include "monty.h"
/**
 * h_pall - Prints all elements in the stack
 * @stack: A pointer to the stack
 * @line_number: The line number (unused)
 *
 * Return: void
 */
void h_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	h.head = *stack;
	if (!*stack)
		return;
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	*stack = h.head;
}

/**
 * h_push - Pushes an element onto the stack
 * @stack: A pointer to the stack
 * @line_number: The line number
 *
 * Return: void
 */

void h_push(stack_t **stack, int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		return;
	}

	node->n = line_number;
	node->prev = NULL;
	node->next = *stack;

	if (*stack)
		(*stack)->prev = node;

	*stack = node;
	h.head = node;
}

/**
 * free_stack - Frees the entire stack
 *
 * Return: void
 */
void free_stack(void)
{
	stack_t *next;

	while (h.head)
	{
		next = h.head->next;
		free(h.head);
		h.head = next;
	}
}

