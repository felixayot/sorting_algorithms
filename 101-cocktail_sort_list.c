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
/*NULL, 19, 48, 9, 71, 13, NULL*/
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
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm.
 * @list: doubly linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *node;
int swapped = 1;
/*if (*list == '\0' || (*list) == '\0' || (*list)->next == '\0') */
/* return; */
node = *list;
while (swapped)
{
swapped = 0;
while (node->next)
{
if (node->n > node->next->n)
{
node = swap_node(node->next, list);
swapped = 1;
print_list(*list);
}
node = node->next;
}
if (!swapped)
break;
swapped = 0;
while (node->prev)
{
if (node->n < node->prev->n)
{
node = swap_node(node, list);
swapped = 1;
print_list(*list);
}
else
node = node->prev;
}
}
}
