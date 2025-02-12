#ifndef PLAYERS_H
#define PLAYERS_H

#include <stdbool.h> 

#define MAX_PLAYERS 4

typedef struct {
    char name[50];
    int score;
} Player;

extern Player players[MAX_PLAYERS];

void initialize_players();
bool player_exists(const char *name);
void update_score(const char *name, int score);
void show_results();

#endif

