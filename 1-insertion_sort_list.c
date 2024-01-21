#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: double pointer to head of list
 *
 * Description: This function implements the Insertion sort
 * algorithm on a doubly linked list.
 * It iterates over each node in the list starting from the second node.
 * If the current node is smaller than the previous node, it swaps them.
 * After each swap, it prints the list to display the changes.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insert = current->prev;
		while (insert != NULL && current->n < insert->n)
		{
			swap_nodes(list, &insert, current);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @h: double pointer to head of list
 * @n1: double pointer to first node to be swapped
 * @n2: pointer to second node to be swapped
 *
 * Description: This function swaps two nodes
 * in a doubly linked list.
 * It updates the `next` and `prev` pointers of the
 * two nodes and their adjacent nodes.
 *
 * Return: Nothing.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
