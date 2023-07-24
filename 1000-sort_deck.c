#include "deck.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 s1 and s2 are equal, +ve byte difference(s1 > s2),
 * -ve byte difference(s1 < s2).
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
 * get_card_value - gets the value based on card you put in
 * @card: node struct to the card
 * Return: the card's position
 */
int get_card_value(deck_node_t *card)
{
if (_strcmp(card->card->value, "Ace") == 0)
return (0);
if (_strcmp(card->card->value, "1") == 0)
return (1);
if (_strcmp(card->card->value, "2") == 0)
return (2);
if (_strcmp(card->card->value, "3") == 0)
return (3);
if (_strcmp(card->card->value, "4") == 0)
return (4);
if (_strcmp(card->card->value, "5") == 0)
return (5);
if (_strcmp(card->card->value, "6") == 0)
return (6);
if (_strcmp(card->card->value, "7") == 0)
return (7);
if (_strcmp(card->card->value, "8") == 0)
return (8);
if (_strcmp(card->card->value, "9") == 0)
return (9);
if (_strcmp(card->card->value, "10") == 0)
return (10);
if (_strcmp(card->card->value, "Jack") == 0)
return (11);
if (_strcmp(card->card->value, "Queen") == 0)
return (12);
return (13);
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
value_prev = get_card_value((node->prev));
value_current = get_card_value(node);
}
while ((node->prev) && (value_prev > value_current))
{
value_prev = get_card_value((node->prev));
value_current = get_card_value(node);
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
if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
return;
insertion_sort_deck(deck);
}
