#include "monty.h"

/**
 * subHandler - handles the sub opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void subHandler(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0;
	stack_t *p = *stack;

	for (; p != NULL; p = p->next)
		length++;
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_entire_arr(argv);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	delete_node_at_index(stack, 0);
}

/**
 * divHandler - handles the div opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void divHandler(stack_t **stack, unsigned int line_number)
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
 * mulHandler - handles the mul opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void mulHandler(stack_t **stack, unsigned int line_number)
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
 * modHandler - handles the mod opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void modHandler(stack_t **stack, unsigned int line_number)
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
 * pcharHandler - handles the pchar opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pcharHandler(stack_t **stack, unsigned int line_number)
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
