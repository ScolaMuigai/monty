#include "monty.h"

/**
 * get_opcodeHandler - finds the opcode handler
 * @s: the name of the opcode
 *
 * Return: a pointer to the handler function
 */
void (*get_opcodeHandler(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", pushHandler},
		{"pall", pallHandler},
		{"pint", pintHandler},
		{"pop", popHandler},
		{"swap", swapHandler},
		{"add", addHandler},
		{"nop", nopHandler},
		{"sub", subHandler},
		{"div", divHandler},
		{"mul", mulHandler},
		{"mod", modHandler},
		{"pchar", pcharHandler},
		{"pstr", pstrHandler},
		{"rotl", rotlHandler},
		{"rotr", rotrHandler},
		{"stack", stackHandler},
		{"queue", queueHandler},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(s, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}

/**
 * exec_instruction - gets and executes the instruction
 * @s: the name of the instruction
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void exec_instruction(char *s, stack_t **stack, unsigned int line_number)
{
	void (*f)(stack_t **, unsigned int) = get_opcodeHandler(s);

	if (f)
		f(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, s);
		free_entire_arr(argv);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

