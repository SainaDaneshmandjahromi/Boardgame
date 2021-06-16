#include <stdio.h>
#include<string.h>
#include "run_game.h"

extern char array[];
extern int data[];
extern int teleport[];
extern int scores[];

void print_board(char arr[] ,clock_t time, int delay_time, char player1[], char player2[]){

    system("cls");
    int deadline = data[2];
    printf("%s", arr);
    printf("\n\n%s's score: %d\n",player1, scores[0]);
    printf("%s's score: %d\n",player2, scores[1]);
    printf("Remaining Time: %.1f\n" ,(float)deadline - ((float)time / 1000) + (float)delay_time/1000);

}

int before_start(void){

    int choice;
    int counter = 0;
    int check = 0;
    do{
        if(counter != 0)
            printf("wrong input\n");

        printf( "1. Player 1 vs Player 2"
                "\n2. Player vs Computer\n"
                "Enter a number: ");

        choice = get_num();
        system("cls");
        if(choice != 1 && choice != 2)
            counter++;
        else
            check = 1;
    }while (check == 0);

    return choice;
}

/*GETS NUMBER FROM INPUT STREAM*/
int get_num(void){

    int c;
    int sum = 0;
    while ( (c = getchar()) != '\n'){
        if ( c >= '0' && c <= '9'){
            sum = sum * 10 + c - '0';
        }
    }
    return sum;
}

void get_2_names(char player1[], char player2[]){

    int index;
    int flag = 1;
    int counter = 0;
    int c;

    do{
        if(counter != 0)
            printf("SAME NAMES ARE NOT ACCEPTABLE...TRY AGAIN!\n");
        index = 0;
        printf(" Enter Player1's name: ");
        while((c = getchar()) != '\n'){
            player1[index] = c;
            index++;
        }
        player1[index] = '\0';
        index = 0;
        printf(" Enter Player2's name: ");
        while((c = getchar()) != '\n'){
            player2[index] = c;
            index++;
        }
        player2[index] = '\0';

        if(strcmp(player1, player2) == 0)
            counter++;

        else if(strcmp(player1, player2) != 0)
            flag = 0;

    }while(flag != 0);

}

void get_the_name_vs_comp(char player1[], char player2[]){

    int index = 0;
    int c;
    printf(" Enter Player's name: ");

    while((c = getchar()) != '\n'){
        player1[index] = c;
        index++;
    }
    player1[index] = '\0';
    strcpy(player2,"computer");

}

void get_name(char player1[], char player2[], int choice){

    if(choice == 1)
        get_2_names(player1, player2);

    else if(choice == 2)
        get_the_name_vs_comp(player1, player2);

    system("cls");
}

void to_run_game(int choice,int eof_count){

    int width = data[1], height = data[0];
    if(choice == 1){
        printf("\n  Player 1.Your keys would be: W to go up.A to go left.S to go down.D to go right.\n");
        printf("\n  Player 2.Your keys would be: I to go up.J to go left.K to go down.L to go right.\n");
        printf("\n  Q to quit.\n");
        printf("\n  Press any Key to continue...");
        getch();
    }
    if(choice == 2){
        printf("\n  Player X.Your keys would be: W to go up.A to go left.S to go down.D to go right.\n");
        printf("\n  Q to quit.\n");
        printf("\n  Press any Key to continue...");
        getch();
    }

    build_board(width ,height,eof_count);

}

void process_players_scores(char player1[],char player2[]){

    printf("%s's score: %d\n%s's score: %d\n",player1,scores[0],player2,scores[1]);
    if (scores[0] > scores[1]){
        printf("%s has won the game!",player1);
        get_components_competition(player1, player2);
    }
    else if (scores[0] == scores[1]){
        printf("You Guys did the same.Well Done!");
        get_components_competition(player1, player2);
    }
    else{
        printf("%s has won the game!",player2);
        get_components_competition(player2, player1);
    }
    printf("PRESS ANY KEY TO CONTINUE...\n");
    getch();
    system("cls");

}

