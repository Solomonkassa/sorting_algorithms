#include "sort.h"

void swap_nodes(listint_t **head, listint_t **n1, listint_t *n2);

/**
 * insertion_sort_list - A function that sorts a doubly linked
 * list of integers in ascending order
 * @list: A pointer to the head of a doubly-linked list of integers
 * Description: Prints the list after each swap
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prevoius;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		prevoius = current->prev;
		while (prevoius != NULL && current->n < prevoius->n)
		{
			swap_nodes(list, &prevoius, current);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list
 * @head: A pointer to the head of the doubly-linked list
 * @n1: A pointer to the first node to swap
 * @n2: The second node to swap
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
