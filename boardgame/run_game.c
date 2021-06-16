#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "run_game.h"

extern char array[];
extern int data[];
extern int scores[];

void two_components(clock_t now,char player1[],char player2[]){

    clock_t begin ,end, time;
    char end_game = ' ';
    char moves[20];
    int seconds = data[2];

    begin = clock();
    end = seconds * 1000 + begin;
    time = begin;
    /*To REACH THE DELAY*/
    clock_t delay = clock();
    int delay_time = (int)(delay - now);
    /* To CHECK THE TIME*/
    while(time <= end && end_game != 'q'){
        print_board(array ,time, delay_time, player1, player2);
        time = get_move(moves,time);
        end_game = process_move(moves ,array);
    }
    system("cls");
    if (end_game != 'q')
        process_players_scores(player1, player2);

    else{
        printf("\nPRESS ANY KEY TO CONTINUE...");
        getch();
        system("cls");
    }
}

void comp_vs_component(clock_t now, char player1[], char player2[]){

    clock_t begin ,end, time;
    char end_game = ' ';
    char moves[20];
    int comp_move;
    int seconds = data[2];

    begin = clock();
    end = seconds * 1000 + begin;
    time = begin;

    clock_t delay = clock();
    int delay_time = delay - now;

    while(time <= end && end_game != 'q'){
        print_board(array,time, delay_time, player1, player2);
        time = get_move(moves,time);
        comp_move = calculate_move();
        end_game = process_move_singel_player(moves ,array ,comp_move);
    }
    system("cls");
    if (end_game != 'q')
        process_players_scores(player1, player2);

    else{
        printf("\nPRESS ANY KEY TO CONTINUE...");
        getch();
        system("cls");
    }
}

