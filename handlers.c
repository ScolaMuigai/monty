#include "monty.h"

/**
 * pushHandler - handles the push opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pushHandler(stack_t **stack, unsigned int line_number)
{
	if (argv[1] == NULL || is_number(argv[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_entire_arr(argv);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	insert_node_at_index(stack, 0, atoi(argv[1]));
}


/**
 * pallHandler - handles the pall opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pallHandler(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;

	print_stack(*stack);
}


/**
 * pintHandler - handles the pint opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pintHandler(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_entire_arr(argv);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * popHandler - handles the pop opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void popHandler(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_entire_arr(argv);
		exit(EXIT_FAILURE);
	}
	delete_node_at_index(stack, 0);
}

/**
 * swapHandler - handles the swap opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void swapHandler(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0;
	stack_t *p = *stack;
	int top, next;

	for (; p != NULL; p = p->next)
		length++;
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_entire_arr(argv);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	next = (*stack)->next->n;
	(*stack)->n = next;
	(*stack)->next->n = top;
}
