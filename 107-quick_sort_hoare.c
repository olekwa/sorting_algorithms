#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);


/**
 * swap_ints - This will swap two integers in an array.
 * @a: This is the initial integer to be swapped.
 * @b: This is the second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * hoare_partition - This will put a subset in an order in an array of integers
 *                   using the hoare partition mechanism.
 * @array: This is the array of integers.
 * @size: This is the size of the array.
 * @left: This is the initial index of the subset to be ordered.
 * @right: This is the last index of the subset to be ordered.
 *
 * Return: Display the final partition index result.
 *
 * Description: The last element of the partition is be used as the pivot.
 * Allow to print the array after every swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}


/**
 * hoare_sort - Initiate the quicksort algorithm using the recursion.
 * @array: This is the array of integers.
 * @size: This is the size of the array.
 * @left: This is the initial index of the subset to be ordered.
 * @right: This is the last index of the subset to be ordered.
 *
 * Description: This will implement using the Hoare partition mechanism.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}


/**
 * quick_sort_hoare - This will in an ascending order sort an array of integers
 *                    using the quicksort algorithm.
 * @array: This is the array of integers.
 * @size: This is the size of the array.
 *
 * Description: utilize the Hoare partition mechanism. Prints
 * each array after every swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
