#include "sort.h"

/**
 * partition_array - rearrange so the pivot gets it the middle
 * and all the elements righ to the pivot are greater than the pivot
 * and all the elements left to it are lower.
 * @array: The array to be rearranged
 * @size: The size of the array
 * @lo: the lower index of the array.
 * @hi: the higher index of the array.
* Return: Nothing
 */

void partition_array(int *array, size_t size, int lo, int hi)
{
	int i, j, pivot = 0, tmp = 0, pivot_index = hi;

	if (hi <= lo)
		return;

	pivot = array[hi];

	for (i = lo; i < hi; i++)
	{
		if (array[i] > pivot)
		{
			for (j = i + 1; j <= hi; j++)
			{
				if (array[j] <= pivot)
				{
					tmp = array[j];
					array[j] = array[i];
					array[i] = tmp;
					pivot_index = i;
					print_array(array, size);
					break;
				}
			}
		}
	}
	partition_array(array, size, lo, pivot_index - 1);
	partition_array(array, size, pivot_index + 1, hi);
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
* Return: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	partition_array(array, size, 0, (int)size - 1);
}
