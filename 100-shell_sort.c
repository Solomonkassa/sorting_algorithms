#include "sort.h"

/**
 * shell_sort - Shell sort - Knuth Sequence
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int take = 1, i, j, tmp;

	while (take < ((int)(size)))
		take = (3 * take) + 1;
	for (take = (take - 1) / 3; take > 0; take = (take - 1) / 3)
	{
		for (i = take; i < (int)size; i += 1)
		{
			tmp = array[i];

			for (j = i; j >= take && array[j - take] > tmp; j -= take)
			{
				array[j] = array[j - take];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
