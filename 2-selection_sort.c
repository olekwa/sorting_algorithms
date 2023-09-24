#include "sort.h"


/**
 * swap_ints - This will swap two integers in an array.
 * @a: This is the first integer to be swapped.
 * @b: This is second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - This will sort an array of integers in an orderly manner
 *                  by using the selection sort algorithm.
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 *
 * Description: After each swap prints the array.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
