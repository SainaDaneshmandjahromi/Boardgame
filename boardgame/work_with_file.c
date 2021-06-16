#include <stdio.h>
#include "run_game.h"

extern int data[];
extern int scores[];

/*GET GAME DATAS*/
int get_information(void){

    FILE *fp;
    fp = fopen("data.txt", "r");
    int index = 0;
    int file_data;
    int number = 0;
    while((file_data = getc(fp)) != EOF){
        if(file_data != '\n' && file_data != ' ')
            number = number * 10 + file_data - '0';

        else{
           data[index++] = number;
            number = 0;
        }
    }
    data[index++] = number;
    number = 0;
    return index - 1;
}
/*FILE PROCESS AFTER MATCH*/
void get_components_competition(char player1[], char player2[]){

    FILE *fptr;
    fptr = fopen("leaderboard.txt", "r");
    char competitions[100][100];
    int Row = 0, Col = 0;
    char file_data;
    /*TO GET ALL MATCHES*/
    while((file_data = getc(fptr)) != EOF){
        if(file_data != '\n')
            competitions[Row][Col++] = file_data;

        else{
            competitions[Row][Col++] = '\n';
            competitions[Row++][Col] = '\0';
            Col = 0;
        }
    }
    competitions[Row][Col] = '\0';
    int index = search(competitions, player1, player2, Row);

    if(index >= 0)
        rewrite_the_file(competitions, Row, index);

    put_information(scores, player1, player2);

}
/*CHANGE A NUMBER TO A STRING*/
void tostring(char str[], int num){
    int i, rem, len = 0, n;

    if(num == 0){
        str[0] = '0';
        str[1] = '\0';
        return ;
    }
    n = num;
    while (n != 0){
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++){
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

/*MAKE THE STRING TO PUT IN FILE*/
char* make_string(char *DataToAppend, int scores[], char player1[], char player2[]){

    char score[5];

    strcpy(DataToAppend,player2);
    strcat(DataToAppend, " ");
    tostring(score, min(scores[0], scores[1]));
    strcat(DataToAppend, score);
    strcat(DataToAppend, " _ ");
    tostring(score, max(scores[0], scores[1]));
    strcat(DataToAppend, score);
    strcat(DataToAppend, " ");
    strcat(DataToAppend,player1);
    strcat(DataToAppend, "\n");

    return DataToAppend;
}

/*SEARCH IF COMPONENTS HAVE PLAYED BEFORE*/
int search(char competitions[][100], char player1[], char player2[], int index){

    int i;
    for(i = 0; i <= index; i++){
        if(strstr(competitions[i], player1) != NULL && strstr(competitions[i], player2) != NULL)
            return i;
    }
    return -1;
}

/*IT HAPPENS WHEN TWO CURRENT COMPONENTS HAVE HAD A MATCH BEFORE*/
void rewrite_the_file(char competitions[][100], int i, int index){

    FILE *fptr;
    fptr = fopen("leaderboard.txt", "w");
    int j;
    for(j = 0;j <= i;j++)
        if(j != index)
            fprintf(fptr, competitions[j]);

    fclose(fptr);
}


void put_information(int scores[], char player1[], char player2[]){

    FILE *fp;
    fp = fopen("leaderboard.txt", "a");

    int first_ones_len = strlen(player1);
    int second_ones_len = strlen(player2);

    char* DataToAppend = (char*)malloc((11 + first_ones_len + second_ones_len) * sizeof(char));
    DataToAppend = make_string(DataToAppend, scores, player1, player2);

    fputs(DataToAppend, fp);
    fclose(fp);
}
