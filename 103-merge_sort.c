#include "sort.h"

/**
 * merge_sort - A function that sorts an array of integers in ascending
 * order using the merge sort algorithm
 * @array: An array of integers
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	merge_sort_recursive(array, buff, 0, size);
	free(buff);
}

/**
 * merge_sort_recursive - Merge sort algorithm through recursive
 * @subarr: A subarray of an array of integers to sort
 * @buff: A buffer to store the sorted result
 * @front: The front index of the subarray
 * @back: The back index of the subarray
 *
 * Return: Nothing
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{

