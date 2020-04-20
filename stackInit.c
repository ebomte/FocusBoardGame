//
// Created by bomte on 03/04/2020.
//

#include "stackInit.h"
#include "startGame.h"
#include "input_output.h"
#include <stdlib.h>
#include <stdio.h>

square moveItemsLeft(square board[BOARD_SIZE][BOARD_SIZE], int userRow, int userColumn, int currentNumberOfPieces)
{
    square num1_pieces = board[userRow][userColumn -
                                        currentNumberOfPieces]; //storing the location of the square we are moving to
    int tempNumPieces = num1_pieces.num_pieces;
    struct piece *top = board[userRow][userColumn].stack; //storing the entire stack of the source square(the colour and *next piece) into a pointer.

    struct piece *curr = top;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    //curr->p_color = curr->next->p_color;
    curr->next = board[userRow][userColumn - currentNumberOfPieces].stack;
    board[userRow][userColumn - currentNumberOfPieces].stack = top;
    board[userRow][userColumn - currentNumberOfPieces].num_pieces = tempNumPieces + currentNumberOfPieces;
    board[userRow][userColumn].num_pieces = 0;
    board[userRow][userColumn].stack = NULL;
}
square moveItemsRight(square board[BOARD_SIZE][BOARD_SIZE], int userRow, int userColumn, int currentNumberOfPieces)
{
    square num1_pieces = board[userRow][userColumn + currentNumberOfPieces]; //storing the location of the square we are moving to
    int tempNumPieces = num1_pieces.num_pieces;
    struct piece *top = board[userRow][userColumn].stack; //storing the entire stack of the source square(the colour and *next piece) into a pointer.

    struct piece *curr = top;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    //curr->p_color = curr->next->p_color;
    curr->next = board[userRow][userColumn + currentNumberOfPieces].stack;
    board[userRow][userColumn + currentNumberOfPieces].stack = top;
    board[userRow][userColumn + currentNumberOfPieces].num_pieces = tempNumPieces + currentNumberOfPieces;
    board[userRow][userColumn].num_pieces = 0;
    board[userRow][userColumn].stack = NULL;
}
square moveItemsUp(square board[BOARD_SIZE][BOARD_SIZE], int userRow, int userColumn, int currentNumberOfPieces)
{
    square num1_pieces = board[userRow - currentNumberOfPieces][userColumn]; //storing the location of the square we are moving to
    int tempNumPieces = num1_pieces.num_pieces;
    struct piece *top = board[userRow][userColumn].stack; //storing the entire stack of the source square(the colour and *next piece) into a pointer.

    struct piece *curr = top;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    //curr->p_color = curr->next->p_color;
    curr->next = board[userRow - currentNumberOfPieces][userColumn].stack;
    board[userRow - currentNumberOfPieces][userColumn].stack = top;
    board[userRow - currentNumberOfPieces][userColumn].num_pieces = tempNumPieces + currentNumberOfPieces;
    board[userRow][userColumn].num_pieces = 0;
    board[userRow][userColumn].stack = NULL;
}
square moveItemsDown(square board[BOARD_SIZE][BOARD_SIZE], int userRow, int userColumn, int currentNumberOfPieces)
{

    square num1_pieces = board[userRow + currentNumberOfPieces][userColumn]; //storing the location of the square we are moving to
    int tempNumPieces = num1_pieces.num_pieces;
    struct piece *top = board[userRow][userColumn].stack; //storing the entire stack of the source square(the colour and *next piece) into a pointer.

    struct piece *curr = top;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    //curr->p_color = curr->next->p_color;
    curr->next = board[userRow + currentNumberOfPieces][userColumn].stack;
    board[userRow + currentNumberOfPieces][userColumn].stack = top;
    board[userRow + currentNumberOfPieces][userColumn].num_pieces = tempNumPieces + currentNumberOfPieces;
    board[userRow][userColumn].num_pieces = 0;
    board[userRow][userColumn].stack = NULL;
}
