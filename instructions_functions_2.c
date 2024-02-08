#include "monty.h"

/**
 * print_top - prints the top of the stack or an error if stack is emtpy.
 * @stack: pointer to the top of the stack.
 * @line_number: the line number which contained the pint instruction.
 * Return: void.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", ptr->n);
}
