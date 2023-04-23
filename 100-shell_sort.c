#include "sort.h"

/**
 * shell_sort - Shell sort - Knuth Sequence
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int interval = 1, i, j, tmp;

	while (interval < ((int)(size)))
		interval = (3 * interval) + 1;
	for (interval = (interval - 1) / 3; interval > 0; interval = (interval - 1) / 3)
	{
		for (i = interval; i < (int)size; i += 1)
		{
			tmp = array[i];

			for (j = i; j >= interval && array[j - interval] > tmp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
