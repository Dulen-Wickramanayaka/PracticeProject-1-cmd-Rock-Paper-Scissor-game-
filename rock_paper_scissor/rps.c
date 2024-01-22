/*
Rock-Paper-Scissors Game
Author: DUlen Wickramanayaka
Date: 1/25/2024
Description: This program allows the user to play Rock-Paper-Scissors against the computer. 
            And this written as an exercise to imrpve my skills
*/

#define _DEFAULT_SOURCE
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char sp[] = {'r','p','s'}; //sample space of events
int max_score = 3;

int iswin(int player, int computer);
void increment_score(int *player, int *computer, char computer_choice, char player_choice);

int main(void)
{
    printf("Usage : r - ROCK, p - PAPER, s _SCISSOR \n");

    int computer_score = 0, player_score = 0; //stroing the score of each player

    srandom(time(NULL));
    int i = 1;
    while (true)
    {
        //getting choice from the computer
        int n = random() % 3; //selecting a random number from 0 to 2(number is used to point to an index in sp array) 
        char computer_choice = sp[n]; //converting that random number to rock paper or scissor

        //getting choice from the player
        char player_choice;
        printf("round %i : ", i);
        scanf(" %c", &player_choice); //getting input
        if(player_choice != 'r' && player_choice != 'p' && player_choice != 's') //check if player inputs character other than r, p and s
        {
            printf("Undefined input\n");
            continue;
        }

        printf("    You - %c Computer - %c\n", player_choice, computer_choice);
        increment_score(&player_score, &computer_score, player_choice, computer_choice);

        if (iswin(player_score, computer_score) == 1) break; //stop iterating if anyone has reached max score
        i++;
    }
    printf("\n"); //going to new line after finishing
}

int iswin(int player, int computer) //cehcks if anyone has reached max score
{
    if (player == max_score) 
    {
        printf("\n\n         YOU WON!!! (your_score is %i  computer_score is %i)", player, computer);
        return 1; 
    }
    else if (computer == max_score)
    {
        printf("\n\n         YOU LOOSE!!! (your_score is %i  computer_score is %i)", player, computer);
        return 1; 
    }
    return 0;
}

void increment_score(int *player, int *computer, char player_choice, char computer_choice) //incrementing score of the winner of round
{
        switch (computer_choice) //iterate through each possible combination
        {
            case 'r' :
                if  (player_choice == 'r')
                {
                    printf("    point goes to nobody");
                }
                else if (player_choice == 'p') 
                {
                    printf("    point goes to you");
                    (*player)++;
                }
                else 
                {
                    printf("    point goes to computer");
                    (*computer)++;
                }
                break;
            case 'p' :
                if  (player_choice == 'r')
                {
                    printf("    point goes to computer");
                    (*computer)++;
                }
                else if (player_choice == 'p') 
                {
                    printf("    point goes to nobody");
                }
                else 
                {
                    printf("    point goes to you");
                    (*player)++;
                }
                break;
            case 's' :
                if  (player_choice == 'r')
                {
                    printf("    point goes to you");
                    (*player)++;
                }
                else if (player_choice == 'p') 
                {
                    printf("    point goes to computer");
                    (*computer)++;
                }
                else 
                {
                    printf("    point goes to nobody");
                }
        }
        printf("\n\n");
}