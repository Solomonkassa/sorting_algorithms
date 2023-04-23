
#include "sort.h"


/**
 * _partition - array partition
 * @array: array to sort
 * @low: first index
 * @high: last index
 * @size: array size
 * Return: int pivot index
 */
int _partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, tmp, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			if (i < j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - sorts an array of integers recursively
 * @array: array to sort
 * @low: first index
 * @high: last index
 * @size: array size
 */
void qs(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = _partition(array, low, high, size);
		qs(array, low, pivot - 1, size);
		qs(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
