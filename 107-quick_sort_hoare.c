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
