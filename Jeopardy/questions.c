#include <stdio.h>
#include <string.h>
#include "questions.h"


Question questions[MAX_CATEGORIES][MAX_QUESTIONS];

void initialize_game() {
    strcpy(questions[0][0].category, "Anime");
    strcpy(questions[0][0].question, "What is the name of Goku's father?");
    strcpy(questions[0][0].answer, "Bardock");
    questions[0][0].value = 100;
    questions[0][0].answered = false;

    strcpy(questions[0][1].category, "Anime");
    strcpy(questions[0][1].question, "Who is the main protagonist of 'One Piece'?");
    strcpy(questions[0][1].answer, "Luffy");
    questions[0][1].value = 200;
    questions[0][1].answered = false;

    strcpy(questions[0][2].category, "Anime");
    strcpy(questions[0][2].question, "What anime features a notebook that can kill?");
    strcpy(questions[0][2].answer, "Death Note");
    questions[0][2].value = 300;
    questions[0][2].answered = false;

    strcpy(questions[0][3].category, "Anime");
    strcpy(questions[0][3].question, "What anime follows a boy who wants to be Hokage?");
    strcpy(questions[0][3].answer, "Naruto");
    questions[0][3].value = 400;
    questions[0][3].answered = false;

    strcpy(questions[0][4].category, "Anime");
    strcpy(questions[0][4].question, "What anime features a hero who can defeat anyone in one punch?");
    strcpy(questions[0][4].answer, "One Punch Man");
    questions[0][4].value = 500;
    questions[0][4].answered = false;

    strcpy(questions[1][0].category, "Music");
    strcpy(questions[1][0].question, "Who is known as the 'King of Pop'?");
    strcpy(questions[1][0].answer, "Michael Jackson");
    questions[1][0].value = 100;
    questions[1][0].answered = false;

    strcpy(questions[1][1].category, "Music");
    strcpy(questions[1][1].question, "Which band wrote 'Bohemian Rhapsody'?");
    strcpy(questions[1][1].answer, "Queen");
    questions[1][1].value = 200;
    questions[1][1].answered = false;

    strcpy(questions[1][2].category, "Music");
    strcpy(questions[1][2].question, "Which artist is known for the song 'Rolling in the Deep'?");
    strcpy(questions[1][2].answer, "Adele");
    questions[1][2].value = 300;
    questions[1][2].answered = false;

    strcpy(questions[1][3].category, "Music");
    strcpy(questions[1][3].question, "What is the real name of rapper Eminem?");
    strcpy(questions[1][3].answer, "Marshall Mathers");
    questions[1][3].value = 400;
    questions[1][3].answered = false;

    strcpy(questions[1][4].category, "Music");
    strcpy(questions[1][4].question, "Which British band released 'Yellow' in 2000?");
    strcpy(questions[1][4].answer, "Coldplay");
    questions[1][4].value = 500;
    questions[1][4].answered = false;

    strcpy(questions[2][0].category, "Pop Culture");
    strcpy(questions[2][0].question, "Which Marvel movie introduced Black Panther?");
    strcpy(questions[2][0].answer, "Captain America: Civil War");
    questions[2][0].value = 100;
    questions[2][0].answered = false;

    strcpy(questions[2][1].category, "Pop Culture");
    strcpy(questions[2][1].question, "Which movie features the quote 'I am your father'?");
    strcpy(questions[2][1].answer, "Star Wars");
    questions[2][1].value = 200;
    questions[2][1].answered = false;

    strcpy(questions[2][2].category, "Pop Culture");
    strcpy(questions[2][2].question, "Who played the character of Jack in Titanic?");
    strcpy(questions[2][2].answer, "Leonardo DiCaprio");
    questions[2][2].value = 300;
    questions[2][2].answered = false;

    strcpy(questions[2][3].category, "Pop Culture");
    strcpy(questions[2][3].question, "Which popular TV series featured the coffee shop 'Central Perk'?");
    strcpy(questions[2][3].answer, "Friends");
    questions[2][3].value = 400;
    questions[2][3].answered = false;

    strcpy(questions[2][4].category, "Pop Culture");
    strcpy(questions[2][4].question, "Which character snapped their fingers to erase half of the universe?");
    strcpy(questions[2][4].answer, "Thanos");
    questions[2][4].value = 500;
    questions[2][4].answered = false;
}


void display_categories() {
    printf("\nAvailable Categories:\n");
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("%s: ", questions[i][0].category);
        bool has_available = false;
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            if (!questions[i][j].answered) {
                printf("$%d ", questions[i][j].value);
                has_available = true;
            }
        }
        if (!has_available) {
            printf("All questions answered!");
        }
        printf("\n");
    }
}

bool valid_answer(const char *category, int value, const char *answer) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(questions[i][j].category, category) == 0 &&
                questions[i][j].value == value) {
                
                if (strcmp(questions[i][j].answer, answer) == 0) {  
                    questions[i][j].answered = true;
                    return true;
                }
            }
        }
    }
    return false;
}

bool already_answered(const char *category, int value) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(questions[i][j].category, category) == 0 &&
                questions[i][j].value == value) {
                return questions[i][j].answered;
            }
        }
    }
    return false;
}

void display_question(const char *category, int value) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(questions[i][j].category, category) == 0 &&
                questions[i][j].value == value) {
                
                if (questions[i][j].answered) {
                    printf("❌ This question has already been answered.\n");
                    return;
                }

                printf("\n🔹 Question: %s\n", questions[i][j].question);
                return;
            }
        }
    }
    printf("⚠️ Question not found. Check category and value.\n");
}

