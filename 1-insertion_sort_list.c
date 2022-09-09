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
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The list to be sorted.
* Return: Nothing.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *tmp = NULL, *tmp_prev = NULL;

	if (list == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		tmp = current;
		tmp_prev = tmp->prev;
		while ((tmp_prev != NULL) && (tmp->n < tmp_prev->n))
		{
			/* swap nodes */
			swap_list_nodes(list, tmp_prev, tmp);
			print_list(*list);
			tmp_prev = tmp->prev;
		}
		current = current->next;
	}
}
