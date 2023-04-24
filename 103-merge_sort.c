#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);

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
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_subarr - Sort a subarray
 * @subarr: A subarray of an array of integers to sort
 * @buff: A buffer to store the sorted subarray
 * @front: The front index of the array
 * @mid: The middle index of the array
 * @back: The back index of the array
 *
 * Return: Nothing
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

