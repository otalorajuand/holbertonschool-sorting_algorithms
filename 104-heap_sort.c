#include "sort.h"

/**
 * swap_array_elements - swaps two elements from an array.
 * @array: a pointer to the first element of the array.
 * @index_1: the position of the first element.
 * @index_2: the position of the second element.
* return: nothing
 */

void swap_array_elements(int *array, int index_1, int index_2)
{
	int tmp = 0;

	tmp = array[index_1];
	array[index_1] = array[index_2];
	array[index_2] = tmp;
}

/**
 * heapify - converts an array into an array representation of a max heap.
 * @array: a pointer to the first element of the array.
 * @n: The size of the partial array.
 * @i: the index of the root node to check
 * @size: The size of the original array.
* Return: Nothing.
 */

void heapify(int *array, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_array_elements(array, i, largest);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: A pointer to the first element of the array.
 * @size: The size of the array.
* Return: Nothing.
 */

void heap_sort(int *array, size_t size)
{
	int i = 0;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = (int)size - 1; i > 0; i--)
	{
		swap_array_elements(array, 0, i);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
