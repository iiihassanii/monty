#include "monty.h"

/**
 * h_pint - Prints the value at the top of the stack
 * @stack: A pointer to the stack
 * @line_number: The line number (unused)
 *
 * Return: void
 */
void h_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		free_all();
	}
	h.head = *stack;

	printf("%d\n", h.head->n);
}

/**
 * h_pop - Removes the top element of the stack
 * @stack: A pointer to the stack
 * @line_number: The line number (unused)
 *
 * Return: void
 */
void h_pop(stack_t **stack, unsigned int line_number)
{

	if (!stack || !(*stack))
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_all();
	}

	h.head = *stack;

	*stack = h.head->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(h.head);
}

/**
 * h_swap - Swaps the top two elements of the stack
 * @stack: A pointer to the stack
 * @line_number: The line number (unused)
 *
 * Return: void
 */
void h_swap(stack_t **stack, unsigned int line_number)
{
	int tmp, len = 0;

	h.head = *stack;

	while (h.head)
	{
		h.head = h.head->next;
		len++;
	}
	if (len < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		free_all();
	}

	h.head = *stack;

	tmp = h.head->n;
	h.head->n = h.head->next->n;
	h.head->next->n = tmp;
}

/**
 * h_add - Adds the top two elements of the stack
 * @stack: A pointer to the stack
 * @line_number: The line number (unused)
 *
 * Return: void
 */
void h_add(stack_t **stack, unsigned int line_number)
{
	int sum = 0, len;

	h.head = *stack;

	while (h.head)
	{
		h.head = h.head->next;
		len++;
	}
	if (len < 2)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		free_all();
	}

	h.head = *stack;

	sum = h.head->next->n + h.head->n;

	h.head->next->n = sum;

	*stack = h.head->next;
}

/**
 * h_nop - Does nothing
 * @stack: A pointer to the stack (unused)
 * @line_number: The line number (unused)
 *
 * Return: void
 */
void h_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

