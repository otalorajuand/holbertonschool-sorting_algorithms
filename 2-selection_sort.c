#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: The array to be sorted.
 * @size: The size of the array.
* Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	int i, j, min = 0, index = 0, tmp = 0, flag = 0;

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
			tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;
			print_array(array, size);
		}
	}
}
