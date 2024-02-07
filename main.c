#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

instruction_t push;
instruction_t pall;

/**
 * main - Handle arguments, monty file and instructions execution.
 * @argc: number of input arguments.
 * @argv: list of input strings.
 * Return: number to indicate if the program failed or succeded.
 */
int main(int argc, char *argv[])
{
	stack_t* stack = NULL;
	FILE* montyFile = NULL;
	char buffer[1024];
	char* instruction = NULL;
	int line_number = 1;

	/*If number of passed arguments not equal 2 print an error and exit*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*Open the monty file*/
	montyFile = fopen(argv[1], "r");

	/*If the monty file couldn't be open, print an error message and exit*/
	if (montyFile == NULL)
	{	
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

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
			push.f(&stack, line_number);
		}
		else if (strcmp(instruction, "pall") == 0)
		{
			pall.f(&stack, line_number);
		}
		else if (strcmp(instruction, "$") != 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
		}

		line_number++;
	}

	fclose(montyFile);
	free_dlistint(stack);

	return (0);
}
