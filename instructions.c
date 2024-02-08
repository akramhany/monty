#include "monty.h"


/**
 * check_integer - checks if a given string contain only numbers.
 * @str: the string to check.
 * Return: 1 if it contains only numbers, -1 if it doesn't.
 */
int check_integer(const char *str)
{
	int i = 0;

	if (*str == '\0')
		return (-1);

	if (str[i] == '-')
		i++;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}

	if (str[0] == '-' && i == 1)
		return (-1);

	return (1);
}


/**
 * free_dlistint - frees a dlist.
 * @head: head of the dlist.
 * Return: void.
 */
void free_dlistint(stack_t *head)
{
	stack_t *ptr = head;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}


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
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	if (check_integer(push.opcode) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(newNode);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	newNode->n = atoi(push.opcode);
	if (*stack == NULL)
	{
		*stack = newNode;
		return;
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

	line_number = 0;

	if (line_number != 0)
		return;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}


/**
 * trim_dSign - takes a string and removes the dollar sign from its end.
 * @str: input string.
 * Return: void.
 */
void trim_dSign(char *str)
{
	int i = 0;

	if (*str == '\0')
		return;

	if (str[0] == '$')
	{
		str[1] = '\0';
		return;
	}
	while (str[i] != '\0' && str[i] != '$' && str[i] != '\n')
		i++;

	str[i] = '\0';
}




