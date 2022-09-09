#include "sort.h"

/**
 * swap_array_elements - swaps two elements from an array.
 * @array: A pointer to the first element of the array.
 * @index_1: The position of the first element.
 * @index_2: The position of the second element.
* Return: Nothing
 */

void swap_array_elements(int *array, int index_1, int index_2)
{
	int tmp = 0;

	tmp = array[index_1];
	array[index_1] = array[index_2];
	array[index_2] = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: The array to be sorted.
 * @size: The size of the array.
* Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	int i, j, min = 0, index = 0, flag = 0;

	for (i = 0; i < (int)size - 1; i++)
	{
		flag = 0;
		min = array[i];
		for (j = i + 1; j < (int)size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				index = j;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			swap_array_elements(array, i, index);
			print_array(array, size);
		}
	}
}
