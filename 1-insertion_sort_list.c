#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: double pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *sorted = NULL;
listint_t *current = *list;
listint_t *next;

while (current != NULL)
{
next = current->next;
current->next = current->prev = NULL;
sorted = sortedInsert(sorted, current);
current = next;
print_list(*list);
}

*list = sorted;
}

/**
 * sortedInsert - inserts a node in a sorted way
 * in a sorted doubly linked list
 * @head_ref: head of the sorted list
 * @newNode: node to be inserted
 *
 * Return: updated head of the sorted list
 */
listint_t *sortedInsert(listint_t *head_ref, listint_t *newNode)
{
listint_t *current;


if (head_ref == NULL || head_ref->n >= newNode->n)
{
newNode->next = head_ref;
newNode->prev = NULL;
if (head_ref != NULL)
head_ref->prev = newNode;
head_ref = newNode;
}
else
{

current = head_ref;
while (current->next != NULL && current->next->n < newNode->n)
current = current->next;


newNode->next = current->next;
newNode->prev = current;
if (current->next != NULL)
current->next->prev = newNode;
current->next = newNode;
}

return (head_ref);
}
