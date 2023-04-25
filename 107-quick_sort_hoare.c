#include "sort.h"

<<<<<<< HEAD
/**
 * partition_h - array partition
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 * Return: int pivot index
 */
int partition_h(int *array, int first, int last, size_t size)
{
	int pivot = array[last], i = first - 1, j = last + 1, aux;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (j < i)
			return (j);
		if (array[i] > array[j])
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			print_array(array, size);
		}
=======
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
>>>>>>> 0e2d65b1d3eb55ed3ded9107bf54d1b6f1eb1003
	}
}

/**
<<<<<<< HEAD
 * qsh - sorts an array of integers recursively
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 */
void qsh(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition_h(array, first, last, size);
		qsh(array, first, pivot, size);
		qsh(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers using the Quick
 * sort hoare algorithm  in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qsh(array, 0, size - 1, size);
}
=======
 * hoare_partition - Order a subset of an array to the
 * hoare partition scheme
 * @array: The array of integers
 * @size: The size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
 *
 * Return: The final partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

>>>>>>> 0e2d65b1d3eb55ed3ded9107bf54d1b6f1eb1003
