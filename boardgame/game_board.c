#include <stdio.h>
#include "run_game.h"

extern char array[];
extern int data[];
extern int teleport[];
extern int scores[];
extern int seeds[];
/*TO FIND THE PLACE OF A BLOCK IN ARRAY*/
int find_blocks(int a ,int b){

    return ((a * data[1] )+ b);

}
/*CREATE RANDOM NUMBER BETWEEN 0 AND a*/
int find_rand(int a){

    return rand() % a;

}

/*TO FILL THE ARRAY*/
void build_board(int width, int height,int eof_count){

    int brd;
    int i ,j ,k;
    int x ,o;
    int seed_amount = data[3];
    brd = width * height;

    for (i = 0;i < brd;++i)
        array[i] = ' ';
    /*TO PUT THE WALLS*/
    for (i = 0; i < brd ;++i){
        if (i < width || i >= (height -1)*width || i % (width) == 0 || (i + 1)% (width) == 0 || i % width == 1){
            array[i] = '!';
            if (i % (width) == 0)
                array[i] = '\n';

        }
    }
    array[i] = '\0';
    /*TO PUT THE BLOCKS*/
    for (j = 4; j < eof_count; j += 2){
        k = find_blocks(data[j] , data[j + 1]);
        array[k] = 'B';
    }

    srand(time(NULL));
    /*TO PUT THE SEEDS RANDOMLY*/
    for(j = 0; j < seed_amount;){
        k = find_rand(brd);
        if ( array[k] == ' '){
            array[k] = '.';
            seeds[j] = k;
            ++j;
        }
    }

    make_tel();
    make_f();
    /*To PUT X RANDOMLY*/
    for(j = 0;j < 1;){
        x = find_rand(brd);
        if ( array[x] == ' '){
            array[x] = 'X';
            ++j;
        }
    }
    /*TO PUT O RANDOMLY*/
    for(j = 0; j < 1 ;){
        o = find_rand(brd);
        if ( array[o] == ' '){
            array[o] = 'O';
            ++j;
        }
    }

}
/*TO PUT T RANDOMLY*/
void make_tel(void){
    int j ,k ,brd;
    brd = data[0] * data[1];
    for(j = 0; j < 2 ; ){
        k = find_rand(brd);
        if ( array[k] == ' '){
            array[k] = 'T';
            teleport[j] = k;
            ++j;
        }
    }
}
/*TO PUT F RANDOMLY*/
void make_f(void){

    int seeds_amount = data[3];
    int j ,k ,brd;
    int width = data[1], height = data[0];
    brd = width * height;
    for(j = 0;j < 1 ;){
        k = find_rand(brd);
        if ( array[k] == ' '){
            array[k] = 'F';
            ++j;
        }
    }
    seeds[seeds_amount] = k;
}
/*TO MAKE A NEW SEED AND CHANGE THE PREVIOUS PLACE IN SEEDS ARRAY*/
void make_seed(int place){
    srand(time(NULL));
    int j ,k ,brd;
    brd = data[0] * data[1];
    for(j = 0; j < 1 ; ){
        k = find_rand(brd);
        if ( array[k] == ' '){
            array[k] = '.';
            ++j;
        }
    }
    int seeds_amount = data[3];
    for(j = 0 ; j <= seeds_amount+1 ; j+=1){
        if (seeds[j] == place){
            seeds[j] = k;
            break;
        }
    }
}

int find_x(char arr[]){

    int i;
    for(i = 0;arr[i] != '\0' ;++i)
        if (arr[i] == 'X')
            return i;

}

int find_o(char arr[]){

    int i;
    for(i = 0;arr[i] != '\0' ;++i)
        if (arr[i] == 'O')
            return i;

}

