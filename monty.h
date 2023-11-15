#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct h_t - the variable we used
 * @file: file must open
 * @head: first element in stack
 * @line: the input of user
 */
typedef struct h_t
{
	FILE *file;
	stack_t *head;
	char *line;
} h_s;
extern h_s h;

void read_line(FILE *file);
void opcodes(char *line, int num_lines, stack_t **stack);
void handle_push(char *value, stack_t **stack, int line_number);
void h_push(stack_t **stack, int line_number);
void h_pall(stack_t **stack, unsigned int line_number);
void h_pint(stack_t **stack, unsigned int line_number);
void h_pop(stack_t **stack, unsigned int line_number);
void h_swap(stack_t **stack, unsigned int line_number);
void h_add(stack_t **stack, unsigned int line_number);
void h_nop(stack_t **stack, unsigned int line_number);
void free_stack(void);
void free_all(void);
#endif

