#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "run_game.h"

char array[10000];
int data[50];
int teleport[2];
int scores[2] = {0 ,0};
int seeds[51];

int main(void){

    int eof_count = get_information();
    clock_t now = clock();

    char player1[1000];
    char player2[1000];

    int choice;
    /*TO CHOOSE THE MODE*/
    choice = before_start();
    /*TO GET COMPONENT'S/S' NAME*/
    get_name(player1, player2, choice);
    /*INFORMATION*/
    to_run_game(choice,eof_count);

    if (choice == 1)
        two_components(now, player1, player2);

    else if(choice == 2)
        comp_vs_component(now, player1, player2);

    return 0;

}
