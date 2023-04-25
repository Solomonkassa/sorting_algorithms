#include "sort.h"

/**
 * heap_sort - sorts array of integers in ascending order
 * using Heap Sort algorithm
 * @array: list of integers
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int high;

	heapify(array, size);
	high = size - 1;

	while (high > 0)
	{
		swap(array, array[high], array[0]);
		print_array(array, size);
		high = size - 1;
		printf("BEFORE INITIAL SIFT_DOWN\n");
		sift_down(array, 0, high, size);
	}
}

/**
 * heapify - turns array into heap
 * @array: list of integers
 * @size: size of array
 */
void heapify(int *array, size_t size)
{
	int low;

	low = (size - 2) / 2;

	while (low >= 0)
	{
		printf("BEFORE HEAPIFY SIFT_DOWN\n");
		sift_down(array, low, size - 1, size);
		low = low - 1;
	}
}

/**
 * sift_down - sorts heap so parent values are larger than child values
 * @array: list of integers
 * @low: start of array
 * @high: end of array
 */
void sift_down(int *array, int low, int high, size_t size)
{
	int root;
	int child;

	root = low;

	while (root * 2 + 1 <= high)
	{
		child = root * 2 + 1;
		if (child + 1 <= high && array[child] < array[child + 1])
			child = child + 1;
		if (array[root] < array[child])
		{
			printf("BEFORE SIFT_DOWN SWAP\n");
			swap(array, array[root], array[child]);
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * swap - swaps two values in array
 * @array: list of integers
 * @i: index position of first value
 * @j; index position of second value
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
