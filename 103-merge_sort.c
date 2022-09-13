#include "sort.h"

/**
 * fill_aux - Fills the auxiliar array in the merge function.
 * @array: The original array.
 * @aux: The auxiliar array.
 * @lo: The lower index
 * @mid_point: The mid_point index
 * @hi: The high index.
* Return: Nothing.
 */

void fill_aux(int *array, int *aux, int lo, int mid_point, int hi)
{
	int k, i, j, n1, n2;

	n1 = mid_point - lo + 1;
	n2 = hi - lo;
	k = lo;
	i = 0;
	j = n1;
	while (i < n1 && j < n2 + 1)
	{
		if (aux[i] <= aux[j])
		{
			array[k] = aux[i];
			i++;
		}
		else
		{
			array[k] = aux[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = aux[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = aux[j];
		j++;
		k++;
	}

}

/**
 * merge - Merges two consecutive ordered arrays.
 * @array: The original array.
 * @lo: The lower index
 * @mid_point: The mid_point index
 * @hi: The high index.
* Return: Nothing.
 */

void merge(int *array, int lo, int mid_point, int hi)
{
	int *aux = NULL, n2 = 0, i = 0;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = lo; i <= mid_point; i++)
	{
		if (i > lo)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");

	printf("[right]: ");
	for (i = mid_point + 1; i <= hi; i++)
	{
		if (i > mid_point + 1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");

	n2 = hi - lo;
	aux = calloc(n2 + 1, sizeof(int));
	if (!aux)
		return;

	for (int i = 0; i < n2 + 1; i++)
		aux[i] = array[lo + i];

	fill_aux(array, aux, lo, mid_point, hi);
	free(aux);

	printf("[Done]: ");
	for (i = lo; i <= hi; i++)
	{
		if (i > lo)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * partition_array - Partition an array into two subarrays
  * @array: The original array.
 * @lo: The lower index
 * @hi: The high index.
* Return: Nothing.
 */

void partition_array(int *array, int lo, int hi)
{
	int mid_point = 0;

	if (lo >= hi)
		return;

	mid_point = (lo + hi) / 2;

	partition_array(array, lo, mid_point);
	partition_array(array, mid_point + 1, hi);
	merge(array, lo, mid_point, hi);
}

/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
* Return: Nothing.
 */

void merge_sort(int *array, size_t size)
{
	partition_array(array, 0, (int)size - 1);
}
