#include "deck.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 s1 and s2 are equal, 1 not equal
 */
int _strcmp(const char *s1, const char *s2)
{
int i = 0, r;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
{
r = s1[i] - s2[i];
break;
}
else
{
r = s1[i] - s2[i];
}
i++;
}
return (r);
}

/**
 * get_card_position - gets the position based on card you put in
 * @node: node struct to the card
 * Return: the card's position
 */
int get_card_position(deck_node_t *node)
{
int value;

value = (*node).card->value[0] - '0';
if (value < 50 || value > 57)
{
if (_strcmp((*node).card->value, "Ace") == 1)
value = 1;
else if (_strcmp((*node).card->value, "10") == 1)
value = 10;
else if (_strcmp((*node).card->value, "Jack") == 1)
value = 11;
else if (_strcmp((*node).card->value, "Queen") == 1)
value = 12;
else if (_strcmp((*node).card->value, "King") == 1)
value = 13;
}
value += (*node).card->kind * 13;
return (value);
}

/**
 *swap_card - swaps a card to its previous one
 *@card: struct node to the card
 *@deck: struct node to the cards deck
 *Return: pointer to the card entered
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
deck_node_t *back = card->prev, *current = card;

back->next = current->next;
if (current->next)
current->next->prev = back;
current->next = back;
current->prev = back->prev;
back->prev = current;
if (current->prev)
current->prev->next = current;
else
*deck = current;
return (current);
}

/**
 * insertion_sort_deck - sorts the doubly linked deck of cards
 * in ascending order using the Insertion sort algorithm
 * @deck: struct node to deck to be sorted
 * Return: void
 */
void insertion_sort_deck(deck_node_t **deck)
{
int value_prev, value_current;
deck_node_t *node;

if (deck == NULL || (*deck)->next == NULL)
return;
node = (*deck)->next;
while (node)
{
if (node->prev)
{
value_prev = get_card_position((node->prev));
value_current = get_card_position(node);
}
while ((node->prev) && (value_prev > value_current))
{
value_prev = get_card_position((node->prev));
value_current = get_card_position(node);
node = swap_card(node, deck);

}
node = node->next;
}
}

/**
 * sort_deck - sorts a deck of cards by Insertion sort
 * algorithm Implementation.
 * @deck: deck to be sorted
 * Return:void
 */
void sort_deck(deck_node_t **deck)
{
insertion_sort_deck(deck);
}
