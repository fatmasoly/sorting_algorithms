#ifndef _SORT_H
#define _SORT_H
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_elements(int *n1, int *n2);
void lomuto_sorted(int *array, size_t size, int low, int high);
int lomuto_part(int *array, size_t size, int low, int high);
void shell_sort(int *array, size_t size);


#endif
