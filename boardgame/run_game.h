#include <time.h>
#include <windows.h>
#include <conio.h>

void build_board(int width ,int height, int eof_count);
int before_start(void);
int get_num(void);
void to_run_game(int choice, int eof_count);
void print_board(char arr[] ,clock_t time, int delay_time, char player1[], char player2[]);
void make_tel(void);
void make_f(void);
void two_components(clock_t now, char player1[], char player2[]);
clock_t get_move(char moves[],clock_t time);
char process_move(char moves[] ,char array[]);
int find_x(char arr[]);
int find_o(char arr[]);
void make_seed(int place);
void up(char type ,int i);
void down(char type ,int i);
void right(char type ,int i);
void left(char type ,int i);
char process_move_singel_player(char moves[] ,char array[] ,int address);
int calculate_move(void);
char computer_move(int address, int oplace);
char check_move(int address , int oplace);
int get_information(void);
void comp_vs_component(clock_t now, char player1[], char player2[]);
void get_name(char player1[],char player2[],int choice);
void put_information(int scores[], char player1[], char player2[]);
void get_components_competition(char player1[], char player2[]);
int search(char competitions[][100], char player1[], char player2[], int index);
void rewrite_the_file(char competitions[][100], int i, int index);
void process_players_scores(char player1[],char player2[]);
