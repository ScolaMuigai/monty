#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

extern char **argv;

/**
 * struct stack_s - double linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **mkargv(char *str);
void exec_instruction(char *s, stack_t **stack, unsigned int line_number);
void *free_array(char **arr, int j);
void free_entire_arr(char **arr);

stack_t *insert_node_at_index(stack_t **h, unsigned int idx, int n);
size_t print_stack(stack_t *h);
void free_stack(stack_t *head);
int delete_node_at_index(stack_t **head, unsigned int index);

void pushHandler(stack_t **stack, unsigned int line_number);
void pallHandler(stack_t **stack, unsigned int line_number);
void pintHandler(stack_t **stack, unsigned int line_number);
void popHandler(stack_t **stack, unsigned int line_number);
void swapHandler(stack_t **stack, unsigned int line_number);
void addHandler(stack_t **stack, unsigned int line_number);
void nopHandler(stack_t **stack, unsigned int line_number);
void subHandler(stack_t **stack, unsigned int line_number);
void divHandler(stack_t **stack, unsigned int line_number);
void mulHandler(stack_t **stack, unsigned int line_number);
void modHandler(stack_t **stack, unsigned int line_number);
void pcharHandler(stack_t **stack, unsigned int line_number);
void pstrHandler(stack_t **stack, unsigned int line_number);
void rotlHandler(stack_t **stack, unsigned int line_number);
void rotrHandler(stack_t **stack, unsigned int line_number);
void stackHandler(stack_t **stack, unsigned int line_number);
void queueHandler(stack_t **stack, unsigned int line_number);

int is_number(char *s);
char *itoa(int n);

#endif /* MONTY_H */
