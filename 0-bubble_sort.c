#include "sort.h"

void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);

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
				swap(array[i], array[i + 1]);
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
/**
 * swap - Swaps the values of two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
