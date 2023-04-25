#include "sort.h"

/**
 * heap_sort - sorts array of integers in ascending order
 * using Heap Sort algorithm
 * @array: list of integers
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
    int i, tmp;
    
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
    
    for (i = size - 1; i >= 0; i--)
    {
        swap(array, 0, i);
        heapify(array, i, 0);
    }
}

/**
 * heapify - turns array into heap
 * @array: list of integers
 * @size: size of array
 */
void heapify(int *array, size_t size, int i)
{
    int tmp, large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < size && array[l] > array[large])
    {
        large = l;
    }
    
     if (r < size && array[r] > array[large])
    {
        large = r;
    }
    
    if (large != i)
    {
        swap(array, i, large);
        heapify(array, size, large);    
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
