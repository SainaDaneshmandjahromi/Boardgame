#include <stdio.h>
#include "run_game.h"

extern char array[];
extern int data[];
extern int teleport[];
extern int scores[];
char last_move[2];
extern int seeds[];
/*CHANGES THE SCORE*/
void get_score(char type ,int score){

    if (type == 'X')
        scores[0] += score;

    if ( type == 'O')
        scores[1] += score;

}

/*TO MAKE THAT type OF PLAYER GO UP*/
void up(char type ,int i){

    int width = data[1];
    /*IF THERE IS SEED IN THE UP THE SCORE CHANGES AND make_seed IS CALLED*/
    if( array[i - width] == '.'){
        array[i - width] = array[i];
        array[i] = ' ';
        get_score(type ,1);
        make_seed(i - width);
        i -= width;
    }
    /*IF THERE IS F IN THE UP THE SCORE CHANGES AND make_f IS CALLED*/
    else if (array[i - width] == 'F'){
        array[i - width] = array[i];
        array[i] = ' ';
        get_score(type ,5);
        make_f();
        i -= width;
    }
   /*IF THERE IS T IN THE UP IT GOES TO THE OTHER T AND make_tel IS CALLED*/
    else if ( array[i - width] == 'T'){
        if ((i - width) == teleport[0]){
            array[teleport[1]] = array[i];
            array[i] = ' ';
            i = teleport[1];
            array[teleport[0]] = ' ';
            make_tel();
        }
        else if ((i - width) == teleport[1]){
            array[teleport[0]] = array[i];
            array[i] = ' ';
            i = teleport[0];
            array[teleport[1]] = ' ';
            make_tel();
        }
    }
    /*IF THERE IS NOTHING IN THE UP IT JUST GOES UP*/
    else if (array[i - width] == ' '){
        array[i - width] = array[i];
        array[i] = ' ';
        i -= width;
    }
    /*IF THERE IS B IN THE UP NOTHING CHANGES*/
    if (array[i - width] != 'B' && array[i - width] != '!')
        array[i] = type;

}
/*SAME AS UP*/
void down(char type ,int i){

    int width = data[1];
    if( array[i + width] == '.'){
        array[i + width] = array[i];
        array[i] = ' ';
        get_score(type ,1);
        make_seed(i+data[1]);
        i += width;
    }
    else if (array[i + width] == 'F'){
        array[i + width] = array[i];
        array[i] = ' ';
        get_score(type ,5);
        make_f();
        i += width;
    }
    else if ( array[i + width] == 'T'){
        if ((i + width) == teleport[0]){
            array[teleport[1]] = array[i];
            array[i] = ' ';
            i = teleport[1];
            array[teleport[0]] = ' ';
            make_tel();
        }
        else if ((i + width) == teleport[1]){
            array[teleport[0]] = array[i];
            array[i] = ' ';
            i = teleport[0];
            array[teleport[1]] = ' ';
            make_tel();
        }
    }
    else if (array[i + width] == ' '){
        array[i + width] = array[i];
        array[i] = ' ';
        i += width;
    }
    if ( array[i + width] != 'B' && array[i + width] != '!')
        array[i] = type;

}
/*SAME AS UP*/
void right(char type ,int i){

    if( array[i + 1] == '.'){
        array[i + 1] = array[i];
        array[i] = ' ';
        get_score(type ,1);
        make_seed( i+1 );
        i += 1;
    }
    else if (array[i + 1] == 'F'){
        array[i + 1] = array[i];
        array[i] = ' ';
        get_score(type ,5);
        make_f();
        i += 1;
    }
    else if ( array[i + 1] == 'T'){
        if ((i + 1) == teleport[0]){
            array[teleport[1]] = array[i];
            array[i] = ' ';
            i = teleport[1];
            array[teleport[0]] = ' ';
            make_tel();
        }
        else if ((i + 1) == teleport[1]){
            array[teleport[0]] = array[i];
            array[i] = ' ';
            i = teleport[0];
            array[teleport[1]] = ' ';
            make_tel();
        }
    }
    else if (array[i + 1] == ' '){
        array[i + 1] = array[i];
        array[i] = ' ';
        i += 1;
    }
    if ( array[i + 1] != 'B' && array[i + 1] != '!')
        array[i] = type;

}
/*SAME AS UP*/
void left(char type ,int i){

    if( array[i - 1] == '.'){
        array[i - 1] = array[i];
        array[i] = ' ';
        get_score(type ,1);
        make_seed(i-1);
        i -= 1;
    }
    else if (array[i - 1] == 'F'){
        array[i - 1] = array[i];
        array[i] = ' ';
        get_score(type ,5);
        make_f();
        i -= 1;
    }
    else if ( array[i - 1] == 'T'){
        if ((i - 1) == teleport[0]){
            array[teleport[1]] = array[i];
            array[i] = ' ';
            i = teleport[1];
            array[teleport[0]] = ' ';
            make_tel();
        }
        else if ((i - 1) == teleport[1]){
            array[teleport[0]] = array[i];
            array[i] = ' ';
            i = teleport[0];
            array[teleport[1]] = ' ';
            make_tel();
        }
    }
    else if (array[i - 1] == ' '){
        array[i - 1] = array[i];
        array[i] = ' ';
        i -= 1;
    }
    if ( array[i - 1] != 'B' && array[i - 1] != '!')
        array[i] = type;

}
/*TO CHECK WHAT IS PRESSED AT LAST OF THAT 0.2 SECONDS AND PROCESS IT*/
char process_move(char moves[] ,char array[]){

    int i;
    for (i = 0; moves[i] != '\0'; ++i){
        if (moves[i] == 'w' || moves[i] == 'a' || moves[i] == 's' || moves[i] == 'd')
            last_move[0] = moves[i];

        if (moves[i] == 'i'|| moves[i] == 'j' || moves[i] == 'k' || moves[i] == 'l')
            last_move[1] = moves[i];

        if (moves[i] == 'q')
            return moves[i];

    }
    switch (last_move[0]){

    case 'w':
        i = find_x(array);
        up('X' ,i);
        break;
    case 'a':
        i = find_x(array);
        left('X' ,i);
        break;
    case 's':
        i = find_x(array);
        down('X' ,i);
        break;
    case 'd':
        i = find_x(array);
        right('X' ,i);
        break;
    default:
        break;
    }
    switch (last_move[1]){

    case 'i':
        i = find_o(array);
        up('O' ,i);
        break;
    case 'j':
        i = find_o(array);
        left('O' ,i);
        break;
    case 'k':
        i = find_o(array);
        down('O' ,i);
        break;
    case 'l':
        i = find_o(array);
        right('O' ,i);
        break;
    default:
        break;
    }
}
/*TO PUT WHAT IS PRESSED IN moves ARRAY IN EVERY 0.2 SECONDS*/
clock_t get_move(char moves[],clock_t time){

    int i = 0;
    int kb;
    clock_t end = time + 200;
    while (time < end){
        if (kbhit()){
            kb = getch();
            moves[i++] = kb;
        }
        time = clock();
    }
    moves[i] = '\0';
    return end;
}
/*WORKS LIKE process_move BUT JUST FOR ONE PLAYER*/
char process_move_singel_player(char moves[] ,char array[] ,int move){

    int i;
    for (i = 0; moves[i] != '\0'; ++i){
        if (moves[i] == 'w' || moves[i] == 'a' || moves[i] == 's' || moves[i] == 'd')
            last_move[0] = moves[i];

        if (moves[i] == 'q')
            return moves[i];

    }

    switch (last_move[0]){

    case 'w':
        i = find_x(array);
        up('X' ,i);
        break;
    case 'a':
        i = find_x(array);
        left('X' ,i);
        break;
    case 's':
        i = find_x(array);
        down('X' ,i);
        break;
    case 'd':
        i = find_x(array);
        right('X' ,i);
        break;
    default:
        break;
    }
    i = find_o(array);
    last_move[1] = check_move(move ,i);
    switch (last_move[1]){

    case 'i':
        i = find_o(array);
        up('O' ,i);
        break;
    case 'j':
        i = find_o(array);
        left('O' ,i);
        break;
    case 'k':
        i = find_o(array);
        down('O' ,i);
        break;
    case 'l':
        i = find_o(array);
        right('O' ,i);
        break;
    default:
        break;
    }
}

int calculate_move(void){

    int i, j, k, temp;
    int seeds_amount = data[3];
    int x_o ,y_o;
    int x_seed ,y_seed;
    int address_value = 0;
    float value[seeds_amount + 1];
    i = find_o(array);
    x_o = i % data[1];
    y_o = i / data[1];
    /*CALCULATES OS DISTANCE TO EACH SEED AND PUTS THE AMOUNT OF EACH VALUE IN value ARRAY*/
    for (j = 0;j <= seeds_amount;++j){
        temp = seeds[j];
        x_seed = temp % data[1];
        y_seed = temp / data[1];
        k = abs(x_seed - x_o) + abs(y_seed - y_o);
        value[j] = 1.0 / k;
    }
    value[--j] *= 5;
    /*TO FIND THE MAX VALUE*/
    for (j = 0;j <= seeds_amount ;++j){
        if (value[j] >= address_value){
            address_value = value[j];
            temp = j;
        }
    }
    int address = seeds[temp];
    return address;
}
/*REGARDING THE ADDRESS REACHED FROM calculate_move DECIDES WHERE TO GO*/
char computer_move(int address, int oplace){

    int x_address ,y_address;
    int x_oplace ,y_oplace;
    int x_distance ,y_distance;

    int width = data[1];

    x_address = address % width;
    y_address = address / width;
    x_oplace = oplace % width;
    y_oplace = oplace / width;

    x_distance = x_oplace - x_address;
    y_distance = y_oplace - y_address;


   if ( x_distance >= 0 && y_distance >= 0){
        if ( x_distance >= y_distance)
            return 'j';

        else
            return 'i';

    }
    else if ( x_distance >= 0 && y_distance <= 0){
        if ( x_distance >= abs(y_distance))
            return 'j';

        else
            return 'k';

    }
    else if ( x_distance <= 0 && y_distance >= 0){
        if ( abs(x_distance) >= y_distance)
            return 'l';

        else
            return 'i';

    }
    else if ( x_distance <= 0 && y_distance <= 0){
        if ( abs(x_distance) >= abs(y_distance))
            return 'l';

        else
            return 'k';

    }
}
/*HANDLES WHILE THE MOVE REACHED FROM computer_move MAKES THE COMPUTER TO GO TO BLOCK OR !*/
char check_move(int address , int oplace){
    char move;
    int width = data[1];
    move=computer_move(address , oplace);
    char up_array[3] = {'j','k','l'};
    char left_array[3] = {'i','k','l'};
    char right_array[3] = {'k','j','i'};
    char down_array[3] = {'i','j','l'};
    switch (move){
    case 'i':
        if (array[oplace - width]=='B' || array[oplace - width]=='!')
            return up_array[rand() % 3];

        else
            return 'i';

        break;
    case 'j':
        if (array[oplace - 1]=='B' || array[oplace - 1]=='!')
            return left_array[rand() % 3];

        else
            return 'j';

        break;
    case 'k':
         if (array[oplace + width]=='B' || array[oplace + width]=='!')
            return down_array[rand() % 3];

        else
            return 'k';

        break;
    case 'l':
        if (array[oplace + 1]=='B' || array[oplace + 1]=='!')
            return right_array[rand() % 3];

        else
            return 'l';

        break;
    default:
        break;
    }
}

