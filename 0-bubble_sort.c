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
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to be sorted.
 * @size: The size of the array.
* Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	int i, flag = 0;

	do {
		flag = 0;
		for (i = 0; i <= (int)size - 2; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_array_elements(array, i, i + 1);
				print_array(array, size);
				flag = 1;
			}
		}
	} while (flag == 1);
}
