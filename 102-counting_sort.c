#include "sort.h"

/**
 * array_max - Calculates the maximun element of array
 * @array: A pointer to the first element of the array.
 * @size: The size of the array.
* Return: The maximun element of the array.
 */

int array_max(int *array, size_t size)
{
	int i = 0, max = 0;

	if (!array)
		return (max);

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}

/**
 * fill_count_array - Fills the count array of the counting sort.
 * @array: A pointer to the first element of the input array.
 * @count: A pointer to the first element of the empty count array.
 * @len: The length of the count array.
 * @size: The size of the input array.
* Return: Nothing.
 */

void fill_count_array(int *array, int *count, int len, size_t size)
{
	int i = 0, acum = 0, j = 0;

	for (i = 0; i < len; i++)
	{
		acum = 0;
		for (j = 0; j < (int)size; j++)
		{
			if (array[j] == i)
				acum++;
		}
		count[i] = acum;
	}
}

/**
 * acum_count - Transform the count array into cumulative form.
 * @count: A pointer to the count array.
 * @len: The length of the count array.
* Return: Nothing.
 */

void acum_count(int *count, int len)
{
	int i = 0, acum = 0;

	for (i = 0; i < len; i++)
	{
		acum += count[i];
		count[i] = acum;
	}
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: A pointer to the first element of the array.
 * @size: The size of the array.
* Return: Nothing.
 */

void counting_sort(int *array, size_t size)
{
	int i = 0, max = 0, *count = NULL, *array_copy = NULL;

	if (size <= 1)
		return;

	array_copy = calloc((int)size, sizeof(int));
	if (!array_copy)
		return;

	for (i = 0; i < (int)size; i++)
		array_copy[i] = array[i];

	max = array_max(array, size);

	count = calloc(max + 1, sizeof(int));
	if (!count)
		return;

	fill_count_array(array, count, max + 1, size);
	acum_count(count, max + 1);
	print_array(count, (size_t)max + 1);

	for (i = 0; i < (int)size; i++)
	{
		array[count[array_copy[i]] - 1] = array_copy[i];
		count[array_copy[i]]--;
	}
	free(count);
	free(array_copy);
}
