#include "sort.h"

/**
 * bubble_sort - sort list with bubble
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = size;
	int tmp, sorted;

	if (array == NULL)
		return;
	for (j = size; j > 0; j--)
	{
		sorted = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				sorted = 1;
			}
		}
		if (sorted == 0)
		{
			break;
		}
	}
}
