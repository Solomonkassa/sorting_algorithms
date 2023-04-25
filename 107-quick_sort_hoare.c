#include "sort.h"

/**
 * partition_h - array partition
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 * Return: int pivot index
 */
int partition_h(int *array, int first, int last, size_t size)
{
	int pivot = array[last], i = first - 1, j = last + 1, aux;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (j < i)
			return (j);
		if (array[i] > array[j])
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			print_array(array, size);
		}
	}
}

/**
 * qsh - sorts an array of integers recursively
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 */
void qsh(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition_h(array, first, last, size);
		qsh(array, first, pivot, size);
		qsh(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers using the Quick
 * sort hoare algorithm  in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qsh(array, 0, size - 1, size);
}
