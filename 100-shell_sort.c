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
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: A pointer to the first element of the array.
 * @size: The size of the array.
* Return: Nothing.
 */

void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0, gap = 1;

	if (!array)
		return;

	while (gap < (int)size)
	{
		gap = gap * 3 + 1;
	}


	while (gap)
	{
		gap /= 3;
		for (i = 0; i < (int)size - gap; i++)
		{
			j = i;
			while (j >= 0 && (array[j] > array[j + gap]))
			{
				swap_array_elements(array, j, j + gap);
				j = j - gap;
			}
		}
		if (gap)
			print_array(array, size);
	}
}
