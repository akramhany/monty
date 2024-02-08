#include "monty.h"

instruction_t push;
instruction_t pall;
instruction_t pint;
instruction_t pop;
instruction_t swap;
instruction_t add;

/**
 * handle_commands - extract commands from the file and executes them.
 * @montyFile: the file to extract from.
 * @stack: pointer to the head pointer of the stack.
 * Return: void.
 */
void handle_commands(FILE *montyFile, stack_t **stack)
{
	char buffer[1024];
	char *instruction = NULL;
	int line_number = 1;

	/*Initialize all existing instructions*/
	push.f = add_dnodeint;
	pall.f = printAll;
	pint.f = print_top;
	pop.f = pop_top;
	swap.f = swap_top;
	add.f = add_top;

	while (fgets(buffer, sizeof(buffer), montyFile) != NULL)
	{
		instruction = strtok(buffer, " \t");

		trim_dSign(instruction);

		if (strcmp(instruction, "push") == 0)
		{
			push.opcode = strtok(NULL, " \t");
			trim_dSign(push.opcode);
			push.f(stack, line_number);
		}
		else if (strcmp(instruction, "pall") == 0)
		{
			pall.f(stack, line_number);
		}
		else if (strcmp(instruction, "pint") == 0)
		{
			pint.f(stack, line_number);
		}
		else if (strcmp(instruction, "pop") == 0)
		{
			pop.f(stack, line_number);
		}
		else if (strcmp(instruction, "swap") == 0)
		{
			swap.f(stack, line_number);
		}
		else if (strcmp(instruction, "add") == 0)
		{
			add.f(stack, line_number);
		}
		else if (strcmp(instruction, "$") != 0 && strcmp(instruction, "\0") != 0 && strcmp(instruction, "nop") != 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
			exit(EXIT_FAILURE);
		}

		line_number++;
	}
}
