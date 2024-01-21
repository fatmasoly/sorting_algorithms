#include "sort.h"
/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Description: This function implements the Selection
 * sort algorithm on an array of integers.
 * It iterates over each element in the array, finds the
 * smallest element, and swaps it with the first unsorted element.
 * After each swap, it prints the array to display the changes.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
size_t i, j;
int *min_idx;
if (array == NULL || size < 2)
return;
for (i = 0; i < size - 1; i++)
{
min_idx = array + i;
for (j = i + 1; j < size; j++)
min_idx = (array[j] < *min_idx) ? (array + j) : min_idx;
if ((array + i) != min_idx)
{
swap_elements(array + i, min_idx);
print_array(array, size);
}
}
}
