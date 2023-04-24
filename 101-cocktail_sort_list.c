#include "sort.h"

void swap_node_ahead(listint_t **head, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **head, listint_t **tail, listint_t **shaker);

/**
 * cocktail_sort_list - A function that sorts a doubly linked list
 * of integers in ascending order
 * @list: A pointer to the head of a listint_t doubly-linked list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	int flag = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (flag == 0)
	{
		flag = 1;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				flag = 0;
			}
		}
		for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				flag = 0;
			}
		}
	}
}

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list of ahead
 * @head: A pointer to the head of a doubly-linked list of integers
 * @tail: A pointer to the tail of the doubly-linked list
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo
 *
 * Return: Nothing
 */
void swap_node_ahead(listint_t **head, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*head = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked behind
 * @head: A pointer to the head of a doubly-linked list of integers
 * @tail: A pointer to the tail of the doubly-linked list
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo
 *
 * Return: Nothing
 */
void swap_node_behind(listint_t **head, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*head = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}
