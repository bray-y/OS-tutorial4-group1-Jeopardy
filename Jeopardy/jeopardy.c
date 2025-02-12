#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "questions.h"
#include "players.h"

void tokenize(char *input, char **tokens) {
    tokens[0] = strtok(input, " ");
    tokens[1] = strtok(NULL, " ");
    tokens[2] = strtok(NULL, "\n");
}

int main() {
    srand(time(NULL));
    initialize_players();
    initialize_game();

    char player_name[50];
    char category[50];
    int value;
    char answer[256];

    while (1) {
        display_categories();
        printf("\nEnter player's name to select a question: ");
        scanf("%s", player_name);

        if (!player_exists(player_name)) {
            printf("Invalid player name. Try again.\n");
            continue;
        }

        printf("Enter category and value (e.g., Anime 100): ");
        scanf("%s %d", category, &value);

        if (already_answered(category, value)) {
            printf("This question has already been answered!\n");
            continue;
        }

        display_question(category, value);
        printf("\n%s, enter your answer (start with 'What is' or 'Who is'): ", player_name);
        scanf(" %[^\n]s", answer);

        char *tokens[3] = {NULL, NULL, NULL};
        tokenize(answer, tokens);

        if (valid_answer(category, value, tokens[2])) {
            printf("✅ Correct!\n");
            update_score(player_name, value);
        } else {
            printf("❌ Incorrect!\n");
        }
    }

    show_results();
    return 0;
}

