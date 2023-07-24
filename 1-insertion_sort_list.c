#include "sort.h"
/**
 * swap_node - swaps current node to previous one
 * @node: current node to be swapped
 * @list: doubly linked list
 * Return: a pointer to the current node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
listint_t *back = node->prev, *current = node;
back->next = current->next;
if (current->next)
current->next->prev = back;
current->next = back;
current->prev = back->prev;
back->prev = current;
if (current->prev)
current->prev->next = current;
else
*list = current;
return (current);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: doubly linked list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
