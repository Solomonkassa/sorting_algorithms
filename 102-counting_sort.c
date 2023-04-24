#include "sort.h"

void algorithm_counting_sort(int *array, int size, int max);

/**
 * counting_sort - A function that sorts an array of integers
 * in ascending order using Counting sort algorithm
 * @array: An array of integers.
 * @size: The size of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int max, size_int;
	size_t i;

	size_int = (int) size;
	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	algorithm_counting_sort(array, size_int, max);
}

/**
 * algorithm_counting_sort - Afunction that counts sort and arrange in
 * ascending order
 * @array: An array of integers
 * @size: The size of the array
 * @max: Maximum number from the given array
 *
 * Return: Nothing
 */
void algorithm_counting_sort(int *array, int size, int max)
{
	int *sum_count, *sorted_array;
	int number_of_elements = max + 1;
	int i;

	sum_count = malloc(sizeof(int) * number_of_elements);
	if (sum_count == NULL)
	{
		return;
	}
	for (i = 0; i < number_of_elements; i++)
	{
		sum_count[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		sum_count[array[i]] += 1;
	}
	for (i = 0; i < number_of_elements; i++)
	{
		sum_count[i] += sum_count[i - 1];
	}

	print_array(sum_count, number_of_elements);
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(sum_count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		sorted_array[sum_count[array[i]] - 1] = array[i];
		sorted_array[i] -= 1;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = sorted_array[i];
	}
	free(sum_count);
	free(sorted_array);
}
