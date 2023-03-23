#include "monty.h"

/**
 * pstrHandler - handles the pstr opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pstrHandler(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	line_number = line_number;
	for (; p != NULL; p = p->next)
	{
		if (p->n == 0 || p->n > 177 || p->n < 0 ||
				p->n == 128 || p->n == 129)
			break;
		putchar(p->n);
	}
	putchar('\n');
}

/**
 * rotlHandler - handles the rotl opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void rotlHandler(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0;
	stack_t *p = *stack;

	for (; p != NULL; p = p->next)
		length++;
	if (length < 2 || (*stack)->n == 0)
	{
		if (length < 2)
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		else
			fprintf(stderr, "L%d: division by zero\n", line_number);
		free_entire_arr(argv);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	delete_node_at_index(stack, 0);
}


/**
 * rotrHandler - handles the rotr opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void rotrHandler(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0;
	stack_t *p = *stack;

	for (; p != NULL; p = p->next)
		length++;
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_entire_arr(argv);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	delete_node_at_index(stack, 0);
}


/**
 * stackHandler - handles the stack opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void stackHandler(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0;
	stack_t *p = *stack;

	for (; p != NULL; p = p->next)
		length++;
	if (length < 2 || (*stack)->n == 0)
	{
		if (length < 2)
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		else
			fprintf(stderr, "L%d: division by zero\n", line_number);
		free_entire_arr(argv);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	delete_node_at_index(stack, 0);
}


/**
 * queueHandler - handles the queue opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void queueHandler(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0;
	stack_t *p = *stack;

	for (; p != NULL; p = p->next)
		length++;
	if (length == 0 || (*stack)->n > 177 || (*stack)->n < 0 ||
			(*stack)->n == 128 || (*stack)->n == 129)
	{
		if (length == 0)
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		else
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_entire_arr(argv);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
