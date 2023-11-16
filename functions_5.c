#include "monty.h"

/**
 * h_rotl - Performs a left rotation on a stack.
 * @stack: Double pointer to a stack.
 * @line_number: Line number (unused).
 */
void h_rotl(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *node = h.head;
	(void)line_number;

	h.head = *stack;
	if (h.head == NULL)
		return;

	tmp = h.head->n;

	while (h.head->next)
	{
		h.head->n = h.head->next->n;
		h.head = h.head->next;
	}
	h.head->n = tmp;
	h.head = node;
}

/**
 * h_rotr - Performs a right rotation on a stack.
 * @stack: Double pointer to a stack.
 * @line_number: Line number (unused).
 */

void h_rotr(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *node = h.head;
	(void)line_number;

	h.head = *stack;
	if (h.head == NULL)
		return;

	while (h.head->next)
	{
		h.head = h.head->next;
	}
	tmp = h.head->n;

	while (h.head->prev)
	{
		h.head->n = h.head->prev->n;
		h.head = h.head->prev;
	}
	h.head = node;
	h.head->n = tmp;
}

/**
 * q_push - Adds a new node to the end of a queue.
 * @queue: Double pointer to a stack.
 * @n: Value to be assigned to the new node.
 */
void q_push(stack_t **queue, int n)
{
	stack_t *new, *tmp;

	/*first - ceate the node*/
	/* malloc and check */
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		return;
	}

	new->n = n;
	new->next = NULL;

	/*now add the node to the list*/
	/*check if there is head*/
	if (*queue == NULL)
	{
		*queue = new;
		new->prev = NULL;
		h.head = new;
		return;
	}

	tmp = *queue;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	h.head = new;
}
