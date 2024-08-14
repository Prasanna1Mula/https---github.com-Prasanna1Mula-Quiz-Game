#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 5

typedef struct {
    char question[50];
    char options[4][64];
    int correct_option;
}Question;

void displayQuestion (Question q)
{
    printf("%s\n", q.question);
    for (int i=0;i<4;i++)
        printf("%d.%s\n", i+1, q.options[i]);
}

int checkAnswer(Question q, int user_answer)
{
    return(user_answer == q.correct_option);
}

int main()
{
    srand(time(NULL));

    Question original_questions[MAX_QUESTIONS] = {
        {"Who was the first Indian female astronaut?",

        {"Kalpana Chawala", "Sunita Williams", "Sirisha Bandla", "Sangeetha Suresh"},
        1 },

        {"What is name of this element Pt?",

        {"Palladium", "Praseodymium", "Platinum", "Promethium" },
        3},

        {"Which city is called city of Destiny?",

        {"Mumbai", "Allahabad", "Delhi", "Visakhaptnam" },
        4},

        {"Which islands in India is dedicated to Birds?",

        {"Minie Coy", "Havlock", "Neil", "Sunderbans" },
        1},


        {"How many states are there in India?",

        {"23","28","29","30" },
        2 }

     };

     Question questions[MAX_QUESTIONS];
     memcpy(questions, original_questions, sizeof(original_questions));

     int num_questions = MAX_QUESTIONS;

     int score = 0;

     printf("Hey there! Here is your queizzz Game\n");

     for (int i =0; i< MAX_QUESTIONS; i++) {
        int random_index = rand() % num_questions;
        Question current_question = questions[random_index];
        displayQuestion(current_question);

        int user_answer;
        printf("Enter your answer(1-4): ");
        scanf("%d", &user_answer);

        if (user_answer >= 1 && user_answer <= 4) {
            if(checkAnswer(current_question, user_answer)) {
                printf("Correct Hurraayyy!\n");
                score++;
            }
            else {
                printf("Incorrect. The answer is " "%d.%s\n",
                       current_question.correct_option,current_question.options[current_question.correct_option- 1]);
            }
        }
        else {
            printf("Invalid choice dear player. Please enter proper number" "between 1 & 4.\n");
        }

        questions[random_index] = questions[num_questions -1];
        num_questions--;
     }
     printf("Well done dear user !!! Quiz is completed!! Your score: %d/%d\n",score, MAX_QUESTIONS);

     return 0;

    }





