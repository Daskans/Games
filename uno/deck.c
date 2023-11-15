#include "uno.h"

void deck_create(player_t *player) {
    error_player(player);
    card_t *new_card = card_random_create();
    deck_append(new_card, NULL, player);
    deck_t *deck = player->deck;
    for (uint i = 0; i < STD_START_SIZE-1; i++) {
        card_t *new_card = card_random_create();
        deck_append(new_card, &(player->deck), player);
    }
}

void deck_append(card_t *card, deck_t **deck, player_t *player) {
    error_player(player);
    error_card(card);
    deck_t *new_deck = malloc(sizeof(deck_t));
    error_deck(&new_deck);
    new_deck->card = card;
    new_deck->next = NULL;
    if (!deck) {
        fprintf(stdout, "no deck given, new deck was created\n");
        player->deck = new_deck;
    } else {
        deck_t *temp_deck = *deck;
        while (temp_deck->next) {
            temp_deck = temp_deck->next;
        }
        temp_deck->next = new_deck;
        player->deck = *deck;
    }  
}

void deck_print(deck_t **deck, player_t *player) {
    error_player(player);
    error_deck(deck);
    deck_t *temp_deck = *deck;
    printf("[ ");
    while (temp_deck) {
        card_print(temp_deck->card);
        printf(" ");
        temp_deck = temp_deck->next;
    }
    printf("]\n");
}