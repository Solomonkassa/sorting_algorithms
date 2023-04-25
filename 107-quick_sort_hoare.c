#include "sort.h"

/**
 * quick_sort_hoare -  function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

/**
 * hoare_sort - Implement the quick sort algorithm
 * @array: An array of integers to sort
 * @size: The size of the array.
 * @left: The starting index of the array partition
 * @right: The ending index of the array partition
 *
 * Return: Nothing
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 1)
	{
		part = hoare_partition(array, size, left, right);

