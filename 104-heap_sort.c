#include "sort.h"

/**
 * heap_sort - sorts array of integers in ascending order
 * using Heap Sort algorithm
 * @array: list of integers
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
    int temp;
    ssize_t i;

    if (!array || size < 2)
        return;

    /* build a max heap */
    for (i = (size / 2) - 1; i >= 0; i--)
        sift_down(array, size, i, size);

    /* extract the elements in descending order */
    for (i = size - 1; i > 0; i--)
    {
        /* swap the root with the last element */
        swap(array, 0, i);
        print_array(array, size);

        /* sift down the new root to maintain the max heap property */
        sift_down(array, i, 0, size);
    }
}

/**
 * sift_down - sifts down a node in a max heap to maintain the max heap property
 * @array: the array that represents the max heap
 * @size: the size of the heap
 * @root: the index of the root of the subtree to sift down
 * @total_size: the total size of the original array
 */

void sift_down(int *array, size_t size, ssize_t root, size_t total_size)
{
    ssize_t max, left, right;
    int temp;

    while ((left = (2 * root) + 1) < size)
    {
        right = left + 1;
        max = (right < size && array[right] > array[left]) ? right : left;
        max = (array[max] > array[root]) ? max : root;

        if (max == root)
            return;

        
        swap(array, root, max);
        print_array(array, total_size);

        root = max;
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
