#include "monty.h"

/**
 * print_stack - prints a doubly linked list
 * @h: the head of the list
 *
 * Return: the number of nodes
 */
size_t print_stack(stack_t *h)
{
	const stack_t *p = h;
	size_t count = 0;

	if (h == NULL)
		return (0);
	for (; p != NULL; p = p->next)
	{
		printf("%d\n", p->n);
		count++;
	}
	return (count);
}

/**
 * free_stack - frees a stack_t list
 * @head: the head of the list
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
		free(head);
	else
	{
		free_stack(head->next);
		free(head);
	}
}

/**
 * delete_node_at_index - deletes the node at index of a stack_t list
 * @head: the head of the stack_t list
 * @index: the index to be deleted
 *
 * Return: 1 if successful, -1 upon failure
 */
int delete_node_at_index(stack_t **head, unsigned int index)
{
	stack_t *p, *prv, *del;
	unsigned int i, count = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	for (p = *head; p != NULL; p = p->next)
		count++;
	if (index >= count)
		return (-1);
	if (index == 0)
	{
		del = *head;
		*head = del->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		p = *head;
		for (i = 0; i + 1 < index; i++) /* go to the node right before index */
			p = p->next;
		prv = p;
		del = p->next;
		prv->next = del->next;
		if (del->next != NULL)
			(del->next)->prev = prv;
	}
	free(del);
	return (1);
}
