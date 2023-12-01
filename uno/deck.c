#include "uno.h"

void deck_create(player_t *player) {
    error_player(player, "deck_create");
    card_t *new_card = card_random_create();
    player->deck = NULL;
    deck_append(new_card, player);
    for (uint i = 0; i < STD_START_SIZE-1; i++) {
        card_t *new_card = card_random_create();
        deck_append(new_card, player);
    }
}

void deck_append(card_t *card, player_t *player) {
    error_player(player, "deck_append");
    error_card(card, "deck_append");
    deck_t *new_deck = malloc(sizeof(deck_t));
    error_deck(new_deck, "deck_append");
    new_deck->card = card;
    new_deck->next = NULL;
    if (!player->deck) {
        fprintf(stdout, "no deck given, new deck was created\n");
        player->deck = new_deck;
    } else {
        deck_t *temp_deck = player->deck;
        while (temp_deck->next) {
            temp_deck = temp_deck->next;
        }
        temp_deck->next = new_deck;
    }
    player->nb_card++;
}

void deck_remove(uint card_index, player_t *player) {
    error_player(player, "deck_remove");
    error_index(player, card_index, "deck_remove");
    if (card_index == 0) player->deck = player->deck->next;
    else {
        deck_t *temp_deck = player->deck;
        for (uint i = 0; i < card_index-1; i++) {
            temp_deck = temp_deck->next;
        }
        temp_deck->next = temp_deck->next->next;
    }
    player->nb_card--;
}

void deck_print(player_t *player, FILE *file) {
    error_player(player, "deck_print");
    error_deck(player->deck, "deck_print");
    deck_t *temp_deck = player->deck;
    fprintf(file, "[ ");
    while (temp_deck) {
        card_print(temp_deck->card, file);
        fprintf(file, " ");
        temp_deck = temp_deck->next;
    }
    fprintf(file, "]\n");
}

card_t *deck_get_card_from_index(player_t *player, uint index) {
    error_player(player, "deck_get_card_from_index");
    error_index(player, index, "deck_get_card_from_index");
    deck_t *temp_deck = player->deck;
    for (uint i = 0; i < index; i++) {
        temp_deck = temp_deck->next;
    }
    return temp_deck->card;
}