# Sorting algorithms & Big O

## Description

This repository contains programs written in C language that implement different sorting algorithms and analyze their time and space complexities.

The implemented sorting algorithms are:

- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort
- Shell Sort
- Cocktail Sort
- Counting Sort
- Merge Sort
- radix_sort
- bitonic sort
- quick sort hoare

## Files

The repository contains the following files:

| File | Description |
|------|-------------|
| `sort.h` | Header file with function prototypes |
| `print_array.c` | Function that prints an array |
| `swap.c` | Function that swaps the values of two integers |
| `0-bubble_sort.c` | Function that implements the bubble sort algorithm |
| `0-O` | Text file with the big O notation of the bubble sort algorithm |
| `1-insertion_sort_list.c` | Function that implements the insertion sort algorithm |
| `1-O` | Text file with the big O notation of the insertion sort algorithm |
| `2-selection_sort.c` | Function that implements the selection sort algorithm |
| `2-O` | Text file with the big O notation of the selection sort algorithm |
| `3-quick_sort.c` | Function that implements the quick sort algorithm |
| `3-O` | Text file with the big O notation of the quick sort algorithm |
| `100-shell_sort.c` | Function that implements the shell sort algorithm |
| `100-O` | Text file with the big O notation of the shell sort algorithm |
| `101-cocktail_sort_list.c` | Function that implements the cocktail sort algorithm |
| `101-O` | Text file with the big O notation of the cocktail sort algorithm |
| `102-counting_sort.c` | Function that implements the counting sort algorithm |
| `102-O` | Text file with the big O notation of the counting sort algorithm |
| `103-merge_sort.c` | Function that implements the merge sort algorithm |
| `103-O` | Text file with the big O notation of the merge sort algorithm |
| `sort-main.c` | Main function to test the sorting algorithms |

## Requirements

The programs were written in C language and compiled using the `gcc` compiler with the flags `-Wall`, `-Werror`, `-Wextra`, and `-pedantic`.

The header file `sort.h` contains the following function prototypes:

```c
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
listint_t *swap_node(listint_t *node, listint_t **list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
````
# Usage

To test the sorting algorithms, compile the files using gcc and execute the resulting binary:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o sort
$ ./sort
```
You can also include the sort.h header file in your own programs and use the sorting functions as needed.

# Author

This project was implemented by:

 * [Solomon Kassa](https://github.com/Solomonkassa)
 * [Adissu Mulat](https://github.com/Adika1630)

