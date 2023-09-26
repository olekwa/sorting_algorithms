/*
 * File: 106-bitonic_sort.c
 * Auth: John Olekwa 
 */


#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - This will swap the two integers in an array.
 * @a: This is the first integer to swapped.
 * @b: This is the second integer to swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - This will sort a bitonic sequence in an array.
 * @array: This is the array of integers.
 * @size: This is the size of the array.
 * @start: This is the start index of the sequence in the array to be sorted.
 * @seq: This is the sequence size to be sorted.
 * @flow: This the movement the array is to be sorted in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}


/**
 * bitonic_seq - This will convert a bitonic sequence to an array of integers.
 * @array: This is the array of integers.
 * @size: This is the size of the array.
 * @start: This is the start index of the sequence in the array to be sorted.
 * @seq: This is the sequence size to be sorted.
 * @flow: This the movement the array is to be sorted in
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}


/**
 * bitonic_sort - This will in an ascending order sort an array of integers
 *                using the bitonic sort algorithm.
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 *
 * Description: Always Print the array after every swap. This will only works if the
 * size = 2^k where k >= 0
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
