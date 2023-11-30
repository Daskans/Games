#include "uno.h"

void error_game(game_t *game, char *function) {
    if (!game) {
        fprintf(stderr, "game does not exist at %s\n", function);
        exit(EXIT_FAILURE);
    }
}

void error_player(player_t *player, char *function) {
    if (!player) {
        fprintf(stderr, "player does not exist at %s\n", function);
        exit(EXIT_FAILURE);
    }
}

void error_deck(deck_t *deck, char *function) {
    if (!deck) {
        fprintf(stderr, "deck does not exist at %s\n", function);
        exit(EXIT_FAILURE);
    }
}

void error_card(card_t *card, char *function) {
    if (!card) {
        fprintf(stderr, "card does not exist at %s\n", function);
        exit(EXIT_FAILURE);
    }
}