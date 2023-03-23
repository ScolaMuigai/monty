#include "monty.h"

/**
 * free_array - frees all elements of
 * an array before index j
 * @arr: the array
 * @j: the index
 *
 * Return: a void pointer
 */
void *free_array(char **arr, int j)
{
	int i;

	for (i = 0; i < j; i++)
		free(arr[i]);
	free(arr);
	return (NULL);
}

/**
 * free_entire_arr - frees the entire array
 * @arr: the array
 *
 * Return: void
 */
void free_entire_arr(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
