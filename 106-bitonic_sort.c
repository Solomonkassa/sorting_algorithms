#include "sort.h"

/**
 * swap - swaps 2 int values
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}

/**
 * bitonic_compare - compares bitonically
 * @up: true if UP sorting
 * @array: the array pointer
 * @start: the start index
 * @end: the stop index
 */
void bitonic_compare(int up, int *array, size_t start, size_t end)
{
	size_t half = (end - start + 1) / 2, i;

	for (i = start; i < start + half; i++)
		if ((array[i] > array[i + half]) == up)
			swap(&array[i], &array[i + half]);
}

/**
 * bitonic_merge - merges bitonically
 * @up: true if UP sorting
 * @array: the array pointer
 * @start: the start index
 * @end: the stop index
 */
void bitonic_merge(int up, int *array, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;

	if (end - start < 1)
		return;
	bitonic_compare(up, array, start, end);
	bitonic_merge(up, array, start, mid);
	bitonic_merge(up, array, mid + 1, end);
}

/**
 * _bitonic_sort - sorts bitonically by recursion
 * @up: true if UP sorting
 * @array: the array pointer
 * @size: the length of the array
 * @start: the start index
 * @end: the stop index
 */
void _bitonic_sort(int up, int *array, size_t size, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;

	if (end - start < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
	_bitonic_sort(1, array, size, start, mid);
	_bitonic_sort(0, array, size, mid + 1, end);
	bitonic_merge(up, array, start, end);
	printf("Result [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
}

/**
 * bitonic_sort - sorts bitonically
 * @array: the array pointer
 * @size: the length of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_bitonic_sort(1, array, size, 0, size - 1);
}
