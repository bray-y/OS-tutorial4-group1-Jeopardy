#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "players.h"

Player players[MAX_PLAYERS];

void initialize_players() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

bool player_exists(const char *name) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

void update_score(const char *name, int score) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].score += score;
        }
    }
}

void show_results() {
    printf("Final Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}

