#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/**
 * main - Handle arguments, monty file and instructions execution.
 * @argc: number of input arguments.
 * @argv: list of input strings.
 * Return: number to indicate if the program failed or succeded.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *montyFile = NULL;

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

	handle_commands(montyFile, &stack);

	fclose(montyFile);
	free_dlistint(stack);

	return (0);
}
