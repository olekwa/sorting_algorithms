#include "sort.h"

/**
 * swap_ints - This will interchange the two integers in an array.
 * @a: This is the first swapped integer.
 * @b: This is the second swapped integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - This in an ascending order Sorts the array of integers
 *               using the shell sort algorithm.
 * @array: This is an array of integers.
 * @size: This is the array size.
 *
 * Description: This will use the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
