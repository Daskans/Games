#include "uno.h"

void error_player(player_t *player) {
    if (!player) {
        fprintf(stderr, "player does not exist");
        exit(EXIT_FAILURE);
    }
}

void error_deck(deck_t **deck) {
    if (!deck) {
        fprintf(stderr, "deck does not exist");
        exit(EXIT_FAILURE);
    }
}

void error_card(card_t *card) {
    if (!card) {
        fprintf(stderr, "card does not exist");
        exit(EXIT_FAILURE);
    }
}