#include "main.h"


/**
 * add_dnodeint - adds a node to a dlistint.
 * @stack: pointer to the stack head.
 * @line_number: value stored in the node.
 * Return: void.
 */
void add_dnodeint(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = atoi(opcode);
	if (*stack == NULL)
	{
		*stack = newNode;
		return (newNode);
	}

	newNode->next = *stack;
	(*stack)->prev = newNode;
	*stack = newNode;
}

/**
 * printAll - pops all nodes from a stack.
 * @stack: pointer to the head of the stack.
 * @line_number: value stored in the node.
 * Return: void
 */
void printAll(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	while (ptr)
	{
		printf("%s\n", ptr->n);
		ptr = ptr->next;
	}
}
