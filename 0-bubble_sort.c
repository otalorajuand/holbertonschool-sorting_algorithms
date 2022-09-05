#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to be sorted.
 * @size: The size of the array.
* Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	int i, tmp = 0, flag = 0;

	do {
		flag = 0;
		for (i = 0; i <= (int)size - 2; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
	} while (flag == 1);
}
