#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: A pointer to the first element of the array.
 * @size: The size of the array.
* Return: Nothing.
 */

void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0, tmp = 0, gap = 1;

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
				tmp = array[j];
				array[j] = array[j + gap];
				array[j + gap] = tmp;
				j = j - gap;
			}
		}
		if (gap)
			print_array(array, size);
	}
}
