#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using
 * the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: No return value (void).
 */
void bubble_sort(int *array, size_t size)
{
size_t i, pass;
if (array == NULL)
return;
for (pass = 1 ; pass < size ; pass++)
{
for (i = 0 ; i < size - 1 ; i++)
{
if (array[i] > array[i + 1])
{
swap_elements(&array[i], &array[i + 1]);
print_array(array, size);
}
}
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
