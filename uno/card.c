#include "uno.h"

void card_play(game_t *game, uint card_index) {
    error_game(game, "card_play");
    card_t *card_played = 
            deck_get_card_from_index(game->player_list[game->current_player],
            card_index);
    if (card_played->color == COLOR_BLACK || 
        card_played->color == game->current_card->color || 
        card_played->value == game->current_card->value) {
        card_print(card_played, stdout);
        printf("\n");
        if (card_played->color == COLOR_BLACK) {
            char c;
            int color;
            printf("Choose a color :\n"
                "yellow = 1\n"
                "blue = 2\n"
                "green = 3\n"
                "red = 4\n"
                "\n> ");
            scanf(" %c", &c);
            color = (int)c - 54;
            card_played->color = color;
        }
        game->current_card = card_played;
        deck_remove(card_index, game->player_list[game->current_player]);
        game_cycle_player(game);
    } else {
        printf("ERROR: cannot place selected card\n");
    }
}

void card_play_effect(game_t *game) {
    card_t *card = game->current_card;
    player_t *next_player = game->player_list[game->current_player];
    switch (card->value)
    {
        case VALUE_PASS:
            game_cycle_player(game);
            break;
        case VALUE_PLUS_2:
            for (uint i = 0; i < 2; i++) {
                deck_append(card_random_create(), next_player);
            }
            game_cycle_player(game);
            break;
        case VALUE_PLUS_4:
            for (uint i = 0; i < 4; i++) {
                deck_append(card_random_create(), next_player);
            }
            game_cycle_player(game);
            break;
        case VALUE_REVERSE:
            game->cycle = !game->cycle;
            break;
    }
}

card_t *card_random_create(void) {
    card_t *new_card = malloc(sizeof(card_t));
    error_card(new_card, "card_random_create");
    new_card->color = card_get_random_color();
    new_card->value = card_get_random_value(new_card->color);
    return new_card;
}

uint card_get_random_value(color_t color) {
    uint value;
    if (color == COLOR_BLACK) {
        value = card_get_random_value_black();
    } else {
        value = card_get_random_value_color();
    }
    return value;
}

uint card_get_random_value_black(void) {
    uint value = rand()%STD_NB_BLACK_CARD;
    if (value < STD_NB_PLUS_4) {
        return VALUE_PLUS_4;
    } else {
        return VALUE_JOCKER;
    }
}

uint card_get_random_value_color(void) {
    uint value = rand()%STD_NB_COLOR_CARD;
    if (value < STD_NB_ZERO) {
        return 0; 
    } else if (value < STD_NB_NUMBER + STD_NB_ZERO) {
        return (rand()%9)+1;
    } else {
        if (value < STD_NB_COLOR_CARD - STD_NB_PLUS_2 - STD_NB_REVERSE) {
            return VALUE_PASS;
        } else if (value < STD_NB_COLOR_CARD - STD_NB_REVERSE) {
            return VALUE_PLUS_2;
        } else {
            return VALUE_REVERSE;
        }
    }
}

color_t card_get_random_color(void) {
    uint randC = rand()%STD_NB_CARD;
    if (randC < STD_NB_BLACK_CARD) {
        return COLOR_BLACK;
    } else {
        uint rand_color = (rand()%4) - 5;
        return rand_color;
    }
}

void card_print(card_t *card, FILE *file) {
    error_card(card, "card_print");
    char *color = card_print_color(card->color);
    if (card->value < 10) {
        fprintf(file, "( %s%d%s )", color, card->value, RESET);
    } else {
        char *value = card_print_value(card->value);
        fprintf(file, "( %s%s%s )", color, value, RESET);
    }
}

char *card_print_value(uint value) {
    switch (value) {
        case VALUE_PLUS_2:
            return "+2";
        case VALUE_PASS:
            return "X";
        case VALUE_REVERSE:
            return "<=>";
        case VALUE_PLUS_4:
            return "+4";
        case VALUE_JOCKER:
            return "RGYB";
    }
}

char *card_print_color(color_t color) {
    switch (color) {
        case COLOR_BLACK:
            return BOLDWHITE;
        case COLOR_RED:
            return BOLDRED;
        case COLOR_GREEN:
            return BOLDGREEN;
        case COLOR_YELLOW:
            return BOLDYELLOW;
        case COLOR_BLUE:
            return BOLDBLUE;
    }
}