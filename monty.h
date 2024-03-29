#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void add_dnodeint(stack_t **stack, unsigned int line_number);
void printAll(stack_t **stack, unsigned int line_number);
void free_dlistint(stack_t *head);
int check_integer(const char *str);
void trim_dSign(char *str);
void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void swap_top(stack_t **stack, unsigned int line_number);
void add_top(stack_t **stack, unsigned int line_number);

void handle_commands(FILE *montyFile, stack_t **stack);

extern instruction_t push;
extern instruction_t pall;


#endif
