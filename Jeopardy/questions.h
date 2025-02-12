#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <stdbool.h>

#define MAX_CATEGORIES 3
#define MAX_QUESTIONS 5

typedef struct {
    char category[50];
    char question[256];
    char answer[50];
    int value;
    bool answered;
} Question;

extern Question questions[MAX_CATEGORIES][MAX_QUESTIONS];

void initialize_game();
void display_categories();
void display_question(const char *category, int value);  
bool valid_answer(const char *category, int value, const char *answer);
bool already_answered(const char *category, int value);

#endif

