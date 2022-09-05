#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The list to be sorted.
* Return: Nothing.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *tmp = NULL, *tmp_prev = NULL;

	current = *list;
	while (current != NULL)
	{
		tmp = current;
		tmp_prev = tmp->prev;
		while ((tmp_prev != NULL) && (tmp->n < tmp_prev->n))
		{
			/* swap nodes */
			tmp_prev->next = tmp->next;
			tmp->prev = tmp_prev->prev;
			tmp_prev->prev = tmp;
			tmp->next = tmp_prev;
			if (tmp->prev != NULL)
			{
				tmp->prev->next = tmp;
			}
			else
				*list = tmp; /* need to change */
						/* the first node of the list */

			if (tmp_prev->next != NULL)
				tmp_prev->next->prev = tmp_prev;

			print_list(*list);
			tmp_prev = tmp->prev;
		}
		current = current->next;
	}
}
