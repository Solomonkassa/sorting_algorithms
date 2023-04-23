#include "sort.h"

/**
 * qs - sorts an array of integers recursively
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 */
void qs(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		qs(array, first, pivot - 1, size);
		qs(array, pivot + 1, last, size);
	}
}
