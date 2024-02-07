#include "main.h"

instruction_t push;
instruction_t pall;

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

	while (fgets(buffer, sizeof(buffer), montyFile) != NULL)
	{
		instruction = strtok(buffer, " ");

		trim_dSign(instruction);

		if (strcmp(instruction, "push") == 0)
		{
			push.opcode = strtok(NULL, " ");
			trim_dSign(push.opcode);
			push.f(stack, line_number);
		}
		else if (strcmp(instruction, "pall") == 0)
		{
			pall.f(stack, line_number);
		}
		else if (strcmp(instruction, "$") != 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
		}

		line_number++;
	}
}
