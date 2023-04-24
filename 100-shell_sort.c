#include "sort.h"

/**
 * shell_sort - Shell sort algorithm
 * @array: unsorted data
 * @size: large of array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t j, gap, n;

	gap = 1;
	if (!array || size < 2)
		return;
	/* Create Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (j = gap; j < size; j += 1)
		{
			tmp = array[j];
			for (n = j; n >= gap && tmp < array[n - gap]; n -= gap)
				array[n] = array[n - gap];
			array[n] = tmp;
		}
		/* decreasing the interval */
		gap /= 3;
		print_array(array, size);
	}
}
