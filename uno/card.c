#include "uno.h"

card_t *card_random_create() {
    card_t *new_card = malloc(sizeof(card_t));
    error_card(new_card);
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
    uint value = arc4random_uniform(STD_NB_BLACK_CARD);
    if (value < STD_NB_PLUS_4) {
        return VALUE_PLUS_4;
    } else {
        return VALUE_JOCKER;
    }
}

uint card_get_random_value_color(void) {
    uint value = arc4random_uniform(STD_NB_COLOR_CARD);
    if (value < STD_NB_ZERO) {
        return 0; 
    } else if (value < STD_NB_NUMBER + STD_NB_ZERO) {
        return arc4random_uniform(9)+1;
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
    uint rand = arc4random_uniform(STD_NB_CARD);
    if (rand < STD_NB_BLACK_CARD) {
        return COLOR_BLACK;
    } else {
        uint rand_color = arc4random_uniform(4) - 5;
        return rand_color;
    }
}

void card_print(card_t *card) {
    error_card(card);
    char *color = card_print_color(card->color);
    if (card->value < 10) {
        printf("( %s%d%s )", color, card->value, RESET);
    } else {
        char *value = card_print_value(card->value);
        printf("( %s%s%s )", color, value, RESET);
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