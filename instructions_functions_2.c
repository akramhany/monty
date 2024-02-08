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



/**
 * pop_top - removes the top element of the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: the line number which contained the pint instruction.
 * Return: void.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = ptr->next;
	ptr->next = NULL;
	
	if (*stack)
		(*stack)->prev = NULL;

	free(ptr);
}



/**
 * swap_top - swaps the top 2 elements in the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: the line number which contained the pint instruction.
 * Return: void.
 */
void swap_top(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!ptr || !ptr->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = ptr->next;

	(*stack)->next = ptr->next;
	ptr->prev = NULL;
	ptr->next = *stack;
	(*stack)->prev = ptr;

	if ((*stack)->next)
		(*stack)->next->prev = *stack;

	(*stack) = ptr;
}
