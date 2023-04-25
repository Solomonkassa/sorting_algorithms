#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * quick_sort - sorts an array of integers in ascending order.
 * @array: the array to be sorted.
 * @size: the size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_extra_hoare(array, 0, (int)size - 1, size);
}

/**
 * quick_sort_extra - sorts an array of integers in asceding order.
 * @array: the array to be sorted.
 * @lo: the beginning of the array
 * @hi: the end of the array
 * @size: the size of the original array
 */
void quick_sort_extra_hoare(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition_hoare(array, lo, hi, size);
		quick_sort_extra_hoare(array, lo, pivot, size);
		quick_sort_extra_hoare(array, pivot + 1, hi, size);
	}
}

/**
 * partition - partitions an array of integers in asceding order.
 * @array: the array to be sorted.
 * @lo: the beginning of the array
 * @hi: the end of the array
 * @size: the size of the original array
 * Return: the index of the last swap
 */
int partition_hoare(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int temp;
	int i = lo - 1;
	int j = hi + 1;
	
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
		{
			return (j);
		}
		else
		{		
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
