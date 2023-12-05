#include "uno.h"

void game_print_help(void) {
    printf("- press 'p <n>' to play card number <n>\n");
    printf("- press 't' to take from the pile\n");
    printf("- press 'q' to quit\n");
}

bool game_won(game_t *game) {
    error_game(game, "game_won");
    for (uint i = 0; i <= game->nb_player-1; i++) {
        if (game->player_list[i]->nb_card == 0) {
            printf("Player [%s] wins !\n", game->player_list[i]->name);
            return true;
        }
    }
    return false;
}

void game_update(game_t *game) {
    error_game(game, "game_update");
    //FILE *file = fopen("player.txt", "w");
    FILE *file = stdout;
    card_play_effect(game);
    fprintf(file, "current player : ");
    fprintf(file, "%s\n", game->player_list[game->current_player]->name);
    fprintf(file, "current card : ");
    card_print(game->current_card, file);
    fprintf(file, "\n\n");
    deck_print(game->player_list[game->current_player], file);
    //fclose(file);
}

void game_init(game_t *game) {
    error_game(game, "game_init");
    for (uint i = 0; i < game->nb_player; i++) {
        player_t *player = game->player_list[i];
        error_player(player, "game_init");
        deck_create(player);
    }
    game->current_card = card_random_create();
}

int game_play(game_t *game) {
    error_game(game, "game_play");
    printf("starting game !\n");
    while (!game_won(game)) {
        game_update(game);
        player_t *player = game->player_list[game->current_player];
        char c;
        printf("-------------------------------------\n");
        printf("? [h for help]\n");
        scanf(" %c", &c);
        if (c == 'h') {
            printf("> action: help\n");
            game_print_help();
        } else if (c == 'q') {
            printf("> action: quit game\n");
            return EXIT_FAILURE;
        } else if (c == 'p') {
            uint n;
            scanf(" %d", &n);
            if (n <= player->nb_card) {
                printf("> action: play ");
                card_play(game, n-1);
            }
        } else if (c == 't') {
            printf("> action: take from pile\n");
            deck_append(card_random_create(), player);
            game_cycle_player(game);
        }
    }
}

void game_cycle_player(game_t *game) {
    error_game(game, "game_cycle_player");
    if (game->cycle = true) {
        if (game->current_player < game->nb_player-1) {
            printf("test\n");
            game->current_player++;
        } else {
            game->current_player = 0;
        }
    } else {
        if (game->current_player > 0) {
            printf("test\n");
            game->current_player--;
        } else {
            game->current_player = game->nb_player-1;
        }
    }
}

void game_delete(game_t *game) {
    if (game) {
        if (game->player_list) {
            for (uint i = 0; i < game->nb_player; i++) {
                if (game->player_list[i]) {
                    free(game->player_list[i]);
                }
            }
            free(game->player_list);
        }
        free(game);
    }
}

int main(void) {
    srand(time(NULL));
    game_t *game = malloc(sizeof(game_t));
    game->cycle = true;
    game->nb_player = 2;
    player_t *player1 = malloc(sizeof(player_t));
    strcpy(player1->name, "player_1");
    player_t *player2 = malloc(sizeof(player_t));
    strcpy(player2->name, "player_2");
    game->player_list = malloc((game->nb_player) * sizeof(player_t));
    game->player_list[0] = player1;
    game->player_list[1] = player2;
    game_init(game);
    game_play(game);
    fprintf(stdout, "game over\n");
    game_delete(game);
    return EXIT_SUCCESS;
}