#include "sort.h"
/**
 * shell_sort - Sorts an array of integers using
 * the Shell Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: No return value (void).
 */
void shell_sort(int *array, size_t size)
{
size_t interval, i, j;
if (array == NULL)
return;
for (interval = 1; interval < (size / 3);)
interval = interval * 3 + 1;
for (; interval >= 1; interval /= 3)
{
for (i = interval; i < size; i++)
{
j = i;
while (j >= interval && array[j - interval] > array[j])
{
swap_elements(array + j, array + (j - interval));
j -= interval;
}
}
print_array(array, size);
}
}

/**
 * swap_elements - Swaps two integer values.
 * @n1: Pointer to the first integer.
 * @n2: Pointer to the second integer.
 *
 * Return: No return value (void).
 */
void swap_elements(int *n1, int *n2)
{
int temp;
temp = *n1;
*n1 = *n2;
*n2 = temp;
}
