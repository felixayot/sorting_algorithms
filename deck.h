#ifndef _DECK_H_
#define _DECK_H_

#include <stddef.h>

/**
 * enum kind_e - card suits
 * @SPADE: Spade card suit
 * @HEART: Heart card suit
 * @CLUB: Club card suit
 * @DIAMOND: Diamond card suit
 */

typedef enum kind_e
{
SPADE = 0,
HEART,
CLUB,
DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
const char *value;
const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
const card_t *card;
struct deck_node_s *prev;
struct deck_node_s *next;
} deck_node_t;

int _strcmp(const char *s1, const char *s2);
int get_card_value(deck_node_t *card);
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck);
void insertion_sort_deck(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

#endif /* _DECK_H_ */
