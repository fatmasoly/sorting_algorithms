#include "sort.h"
/**
 * quick_sort - Sorts an array of integers
 * using the Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: No return value (void).
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	lomuto_sorted(array, size, 0, size - 1);
}

/**
 * lomuto_part - Implements the Lomuto partition
 * scheme for Quick Sort.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: Index of the pivot element after partitioning.
 */
int lomuto_part(int *array, size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap_elements(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap_elements(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * lomuto_sorted - Recursively sorts the array
 * using Lomuto partitioning.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: No return value (void).
 */
void lomuto_sorted(int *array, size_t size, int low, int high)
{
	int sorted;

	if (high - low > 0)
	{
		sorted = lomuto_part(array, size, low, high);
		lomuto_sorted(array, size, low, sorted - 1);
		lomuto_sorted(array, size, sorted + 1, high);
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
