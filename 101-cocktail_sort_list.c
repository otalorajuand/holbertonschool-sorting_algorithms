#include "sort.h"

/**
 * swap_list_nodes - Swaps two nodes from a linked list.
 * @list: A double pointer to the first element of the list.
 * @first_node: A pointer to the first element to swap.
 * @second_node: A pointer to the second element to swap.
* Return: Nothing.
 */

void swap_list_nodes(listint_t **list, listint_t *first_node,
		listint_t *second_node)
{
	/* swap nodes */
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
	second_node->next = first_node;
	if (second_node->prev)
	{
		second_node->prev->next = second_node;
	}
	else
		*list = second_node; /* need to change */
			/* the first node of the list */
	if (first_node->next)
		first_node->next->prev = first_node;
}


/**
 * run_right - Bubble sort from left to right.
 * @list: A double pointer to the first element of the list.
 * @flag: Indicates if there were any swaps.
* Return: Nothing.
 */

void run_right(listint_t **list, int *flag)
{
	listint_t *current = NULL, *current_next = NULL;

	current = *list;
	current_next = current->next;

	while (current_next)
	{
		if (current->n > current_next->n)
		{
			/* swap nodes */
			swap_list_nodes(list, current, current_next);
			print_list(*list);
			*flag = 1;
		}
		else
		{
			current = current->next;
		}
			current_next = current->next;
	}
}

/**
 * run_left - Bubble sort from right to left.
 * @list: A double pointer to the first element of the list.
 * @flag: Indicates if there were any swaps.
* Return: Nothing.
 */

void run_left(listint_t **list, int *flag)
{
	listint_t *current = NULL, *current_prev = NULL;

	current = *list;
	while (current->next)
		current = current->next;

	current_prev = current->prev;

	while (current_prev)
	{
		if (current->n < current_prev->n)
		{
			/* swap nodes */
			swap_list_nodes(list, current_prev, current);
			print_list(*list);
			*flag = 1;
		}
		else
		{
			current = current->prev;
		}
		current_prev = current->prev;
	}
}

/**
 * cocktail_sort_list - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @list: The array to be sorted.
* Return: Nothing.
 */

void cocktail_sort_list(listint_t **list)
{
	int flag = 0, *flag_p = NULL;

	flag_p = &flag;

	do {
		flag = 0;
		run_right(list, flag_p);

		flag = 0;
		run_left(list, flag_p);

	} while (flag == 1);
}
