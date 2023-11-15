#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <bsd/stdlib.h>

// define MAX and STD
#define MAX_NAME_SIZE 20
#define STD_START_SIZE 7
#define STD_NB_PLUS_4 4
#define STD_NB_JOCKER 4
#define STD_NB_BLACK_CARD (STD_NB_JOCKER + STD_NB_PLUS_4)
#define STD_NB_PLUS_2 8
#define STD_NB_REVERSE 8
#define STD_NB_PASS 8
#define STD_NB_SPECIAL_CARD (STD_NB_PASS + STD_NB_PLUS_2 + STD_NB_REVERSE)
#define STD_NB_NUMBER 72
#define STD_NB_ZERO 4
#define STD_NB_NUMBER_CARD (STD_NB_NUMBER + STD_NB_ZERO)
#define STD_NB_COLOR_CARD (STD_NB_NUMBER_CARD + STD_NB_SPECIAL_CARD)
#define STD_NB_CARD (STD_NB_COLOR_CARD + STD_NB_BLACK_CARD)

// define color
#define COLOR_BLACK -1
#define COLOR_RED -2
#define COLOR_GREEN -3
#define COLOR_BLUE -4
#define COLOR_YELLOW -5

// define special value
#define VALUE_PLUS_2 10
#define VALUE_PASS 11
#define VALUE_REVERSE 12
#define VALUE_PLUS_4 13
#define VALUE_JOCKER 14

// define text colors
#define BOLDRED   "\033[1m\033[31m" 
#define BOLDGREEN  "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE  "\033[1m\033[34m"
#define BOLDWHITE  "\033[1m\033[37m"
#define RESET  "\033[0m"  

typedef int color_t;

typedef struct card {
    color_t color;
    uint value;
} card_t;

typedef struct deck deck_t;

typedef struct deck {
    card_t *card;
    deck_t *next;
} deck_t;

typedef struct player {
    char name[MAX_NAME_SIZE];
    deck_t *deck;
} player_t;

typedef struct list_player {
    player_t *players;
    size_t size;
} list_player_t;

typedef struct game {
    card_t current_card;
    player_t next_player;
 } game_t;

// implement errors
void error_player(player_t *player);
void error_deck(deck_t **deck);
void error_card(card_t *card);

// implement deck actions
void deck_create(player_t *player);
void deck_append(card_t *card, deck_t **deck, player_t *player);
void deck_print(deck_t **deck, player_t *player);

//implement card actions
card_t *card_random_create(void);
uint card_get_random_value(color_t color);
uint card_get_random_value_black(void);
uint card_get_random_value_color(void);
color_t card_get_random_color(void);
void card_print(card_t *card);
char *card_print_value(uint value);
char *card_print_color(color_t color);