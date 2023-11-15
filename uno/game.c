#include "uno.h"

void game_init(list_player_t *list_players) {

    for (uint i = 0; i < list_players->size; i++) {
        player_t *player = &(list_players->players[i]);
        deck_create(player);
        deck_print(&(player->deck), player);
    }
}

int main(void) {
    player_t *player1 = malloc(sizeof(player_t));
    error_player(player1);
    deck_create(player1);
    deck_print(&(player1->deck), player1);
    return EXIT_SUCCESS;
}