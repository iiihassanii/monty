#include "monty.h"

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
