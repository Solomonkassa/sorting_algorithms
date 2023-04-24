#include "sort.h"

void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * radix_sort - A function that sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, i, sig, *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	for (max = array[0], i = 0; i < size; i++)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}
	free(buff);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 * @sig: The significant digit to sort on
 * @buff: A buffer to store the sorted array
 *
 * Return: Nothing
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}
