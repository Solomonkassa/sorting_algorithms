#include "sort.h"
/**
  * selection_sort - selection sort algorithm
  * @array: array to sort
  * @size: size of array
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int hold, tmp;

	for (i = 0; i < size - 1; i++)
	{
		tmp = i;
		hold = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[tmp] > array[j])
			{
				tmp = j;
				hold = 1;
			}
		}

		if (hold == 1)
		{
			swap(&array[i], &array[tmp]);
			print_array(array, size);
		}
	}
}
