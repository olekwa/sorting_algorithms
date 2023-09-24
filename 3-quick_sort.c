#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);


/**
 * swap_ints - This will swap two integers in an array.
 * @a: This is first integer to swapped.
 * @b: This is second integer to swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * lomuto_partition - This orders a subset of an array of integers using
 * the lomuto partition methodology (last element as pivot).
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 * @left: This is the initial index of the subset to order.
 * @right: This is the last index of the subset to order.
 * Return: The total index  partition.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}


/**
 * lomuto_sort - The recursion is used for a quicksort algorithm.
 * @array: This is the array of integers to be sorted.
 * @size: This is the size of the array.
 * @left: This is the initial index array partition to order.
 * @right: This is the ending index array partition to order.
 * Description: Use the Lomuto partition methodology.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}


/**
 * quick_sort - In ascending sort an array of integers order
 * by using the quicksort algorithm.
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 * Description: Prints an array after each swap of two elements.
 * Using the Lomuto partition methodology.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
