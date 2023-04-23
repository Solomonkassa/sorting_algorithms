#include <stdint.h>
#include "sort.h"
#define getParent(i) (((i) - 1) / 2)
#define getLeft(i) (2 * (i) + 1)
#define getRight(i) (2 * (i) + 2)
/**
 * sift_down - sift_down
 * @array: array containing heap
 * @size: total size of array
 * @index: index of index node of heap
 * @nth: index of nth node in heap to examine
 */
void sift_down(int *array, size_t size, size_t index, size_t nth)
{
size_t largest, left, right;
do {
left = getLeft(index);
right = getRight(index);
largest = index;
if (right <= nth && array[right] > array[index])
largest = right;
if (array[left] > array[largest])
largest = left;
if (index == largest)
return;
array[index] ^= array[largest];
array[largest] ^= array[index];
array[index] ^= array[largest];
print_array(array, size);
index = largest;
} while (getLeft(index) <= nth);
}
/**
 * heap_sort - use heap sort
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
size_t node, sorted;
if (array == NULL || size < 2)
return;
for (node = getParent(size - 1); node != SIZE_MAX; node--)
sift_down(array, size, node, size - 1);
for (sorted = size - 1; sorted > 1; sorted--)
{
array[0] ^= array[sorted];
array[sorted] ^= array[0];
array[0] ^= array[sorted];
print_array(array, size);
sift_down(array, size, 0, sorted - 1);
}
array[0] ^= array[1];
array[1] ^= array[0];
array[0] ^= array[1];
print_array(array, size);
}
