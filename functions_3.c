#include "monty.h"
/**
 * h_sub - Sub the last two element
 * @stack: A pointer to the stack
 * @line_number: The line number
 *
 * Return: void
 */
void h_sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		h.head = *stack;
		free_all();
		return;
	}
	h.head = *stack;
	sub = h.head->next->n - h.head->n;
	h.head->next->n = sub;

	h_pop(stack, line_number);
}
/**
 * h_div - divide the last two element
 * @stack: A pointer to the stack
 * @line_number: The line number
 *
 * Return: void
 */
void h_div(stack_t **stack, unsigned int line_number)
{
	int res = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		h.head = *stack;
		free_all();
		return;
	}
	h.head = *stack;
	if (h.head->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		return;
	}

	res = h.head->next->n / h.head->n;

	h.head->next->n = res;

	h_pop(stack, line_number);
}
/**
 * h_mul - Multiple last two element
 * @stack: A pointer to the stack
 * @line_number: the line number
 *
 * Return: void
 */
void h_mul(stack_t **stack, unsigned int line_number)
{
	int mul = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		h.head = *stack;
		free_all();
		return;
	}

	h.head = *stack;

	mul = h.head->next->n * h.head->n;

	h.head->next->n = mul;

	h_pop(stack, line_number);
}
/**
 * h_mod - computes the rest of the division
 * @stack: A pointer to the stack
 * @line_number: the line number
 *
 * Return: void
 */
void h_mod(stack_t **stack, unsigned int line_number)
{
	int mul = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		h.head = *stack;
		free_all();
		return;
	}
	h.head = *stack;
	if (h.head->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		return;
	}
	mul = h.head->next->n % h.head->n;

	h.head->next->n = mul;

	h_pop(stack, line_number);
}
