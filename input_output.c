//
// Created by bomte on 27/03/2020.
//

#include "input_output.h"
#include "stackInit.h"
#include <stdio.h>
#include "startGame.h"

/* FUnction to print the board:
* Invalid Squares are printed as | - |
* Valid empty squares are printed as |   |
* Valid squares with a GREEN piece are printed as | G |
* Valid squares with a RED piece are printed as | R | */
int sizeCountG = 1;
int sizeCountR = 1;
void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    int countR = 0;

   // printf("0 1 2 3 4 5 6 7 8 9 10");
    printf("****** The Board ******\n");
//    for(int k = 0; k < BOARD_SIZE; k++)
//    {
//
//    }
    printf("\t0\t1\t2\t3\t4\t5\t6\t7\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        printf("%d ", countR++);
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("|   ");
                else{
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| G ");
                    else printf("| R ");
                }
            }
            else
                printf("| - ");
        }
        printf("|\n");
    }
}
void print_players(player players[PLAYERS_NUM])
{
    for(int i = 0; i < PLAYERS_NUM; i++)
    {
        printf("Player Name: %s\n", players[i].playerName);
        if(players[i].player_color == RED){
            printf("Player Colour: RED\n");
        }else if(players[i].player_color == GREEN){
            printf("Player Colour: GREEN\n");
        }
        printf("Number Captured: %d\n", players[i].numberOfOpponentsTokensCaptured);
        printf("Reserved: %d\n", players[i].numberOfReservedTokens);
        printf("---------\n");
    }
}

void managePlayers(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE])
{
    int direction, sizeOfStack = 1;
    /*prompt the user to select co-ordinates of the square` they want to start from \/
     * choose the direction(left, right, up, down) \/
     * -------- get the size of the number pieces of the current square.
     * --------
     * -------- confirm you can move to that direction with the size of the stack
                     *                  +++++ what we know by now +++++
                     *                        - we know size of stack.
                     *                        - we know direction
     *            //// we need to know - if the size of the stack is <= to the valid squares in the chosen direction.
     *                 //if up = is i - sizeOfStack == VALID
     *                 //if down = is i + sizeOfStack == VALID
     *                 //if left = is j - sizeOfStack == VALID
     *                 //if right = is j + sizeOfStack == VALID
     *
     * move to that stack based on the amount of pieces in the stack.
     * show that the square  moved from is empty, and the square move to, now has one more piece than it had before.
     * "if a player can only move a stack if it there own colour"
     * if a stack contains more than 5 pieces, then a piece is removed from the bottom, and kept by the current player as reserved piece.
     * keep playing until a player can make no more moves.
     * (the reserved pieces can be put back in the game if needed) - "not really aiming for a high score, so not needed."
     * */

    int userRow, userColumn;
    //printf("%s playing now\n", players[p].playerName);
    printf("Enter the row of the square you want to go to.");
    scanf("%d", &userRow);
    printf("Enter the column of the square you want to go to.");
    scanf("%d", &userColumn);

    printf("What direction do you want to move?\n 1: left\t 2: right\t 3: up\t 4: down\n");
    scanf("%d", &direction);


    square currentSquare = board[userRow][userColumn];
    int currentSquarePieces = currentSquare.num_pieces;

    int valLeft = userColumn - currentSquarePieces;
    int valRight = userColumn + currentSquarePieces;
    int valUp = userRow - currentSquarePieces;
    int valBottom = userRow + currentSquarePieces;

    switch (direction)
    {
        case 1:

            if(valLeft < 0) {
                perror("out of bounds");
            }else{
                if(board[userRow][userColumn - currentSquarePieces].type==VALID) {

                }
            }
            break;
        case 2:
            if(valRight > 7) {
                perror("out of bounds");
            }else{
                if(board[userRow][userColumn + currentSquarePieces].type==VALID) {

                }
            }
            break;
        case 3:
            if(valUp < 0) {
                perror("out of bounds");
            }else{
                if(board[userRow - currentSquarePieces][userColumn].type==VALID) {

                }
            }
            break;
        case 4:
            if(valBottom > 7) {
                perror("out of bounds");
            }else{
                if(board[userRow + currentSquarePieces][userColumn].type==VALID) {

                }
            }
            break;
    }

//    for(int p = 0; p < PLAYERS_NUM; p++)
//    {
//        int userRow, userColumn;
//        printf("%s playing now\n", players[p].playerName);
//        printf("Enter the row of the stack you want to go to.");
//        scanf("%d", &userRow);
//        printf("Enter the column of the stack you want to go to.");
//        scanf("%d", &userColumn);
//
//        for(int i = 0; i < BOARD_SIZE; i++)
//        {
//            for(int j = 0; j < BOARD_SIZE; j++)
//            {
//                if(i == userRow && j == userColumn)
//                {
//                    if(board[i][j].type == VALID)
//                    {
//                            printf("What direction do you want to move?\n 1: left\t 2: right\t 3: up\t 4: down\n");
//                            scanf("%d", &direction);
//
//                            switch(direction)
//                            {
//                                case 1:
//                                    if(board[i][j-1].type == VALID)
//                                    {
//                                        printingDetails(board[i][j].stack->p_color, players, board);
//                                        if(players[p].player_color == RED)
//                                        {
//                                            sizeCountR++;
//                                        }else{
//                                            sizeCountG++;
//                                        }
//                                        sizeOfStack++;
//                                        printf("size of stack is %d: ", sizeOfStack);
//                                        print_board(board);
//                                        //print board here again with changes
//                                    }
//                                    break;
//                            }
//                        }
//                    else
//                    {
//                        printf("It is invalid\n");
//                    }
//                }
//            }
//        }
//    }
}
