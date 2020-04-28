//
// Created by bomte on 20/04/2020.
//

#include "StackEnd.h"
#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"
#include "stackInit.h"
#include "startGame.h"
#include "StackEnd.h"

void removeLeft(square board[8][8], int userRow, int userColumn, int currentNumberOfPieces, player players[2], int playerIndex) {
    int counter = 1; //a counter to hold the number of pieces we go through
    struct piece *curr = board[userRow][userColumn - currentNumberOfPieces].stack;//setting curr to equal to the top piece of the square
    //curr = malloc(sizeof(piece));
    struct piece *last = NULL;//
    struct piece *toRemove = NULL;
    int rowMove, columnMove;
    //last = malloc(sizeof(piece));
    while (curr->next != NULL) { //while the next piece of a piece is not NULL, then keep looping, because if the next piece is NULL, we can't get to 5 on the counter, we can't remove a piece.
       // last = curr; //using last to hold curr values
        curr = curr->next; //then setting curr to its next element
        counter++; //incrementing curr by 1 each time the statements above are executed
        if (counter >= 5) { //if counter is 5, it means we need to free something
            break;
        }
    }
    last = curr->next;
    curr->next = NULL;
    board[userRow][userColumn - currentNumberOfPieces].num_pieces = 5;

    /*From line 36, I want to use last to get the colours of the pieces and check whether it is the current player's colour or their opponents, then place my colour on
     * the outside square pieces.
     *    ++ loop through the pieces
     *    ++ check the colour
     *    ++ if it's my colour, then increment "reservedPieces" by 1, if it's opponents colour, increment "opponentsCaptured" by 1
     *    ++ also, if it is my colour, then place that piece on one of the squares outside.
     *    * */


    while(last != NULL)
    {
        if(last->p_color == players[playerIndex].player_color)
        {
            players[playerIndex].numberOfReservedTokens = players[playerIndex].numberOfReservedTokens + 1;
            printf("Enter correct side square to move it into. \n Enter Row & Column respectively\n");
            scanf("%d %d", &rowMove, &columnMove);

            if(board[rowMove][columnMove].type == VALID)
            {
                if(board[rowMove][columnMove].stack == NULL)
                {
                    last->next = board[rowMove][columnMove].stack;
                    board[rowMove][columnMove].num_pieces = board[rowMove][columnMove].num_pieces + 1;
                    board[rowMove][columnMove].stack = last;
                }
            }
        }
        else
        {
            players[playerIndex].numberOfOpponentsTokensCaptured = players[playerIndex].numberOfOpponentsTokensCaptured + 1;
        }
        last = last->next;
    }
//    printf("Number Captured: %d\n", players[playerIndex].numberOfOpponentsTokensCaptured);
//    printf("Reserved: %d\n", players[playerIndex].numberOfReservedTokens);

}

void removeRight(square board[8][8], int userRow, int userColumn, int currentNumberOfPieces, player players[2], int playerIndex) {
    int counter = 1; //a counter to hold the number of pieces we go through
    struct piece *curr = board[userRow][userColumn + currentNumberOfPieces].stack;//setting curr to equal to the top piece of the square
    //curr = malloc(sizeof(piece));
    struct piece *last = NULL;//
    struct piece *toRemove = NULL;
    //last = malloc(sizeof(piece));
    while (curr->next != NULL) { //while the next piece of a piece is not NULL, then keep looping, because if the next piece is NULL, we can't get to 5 on the counter, we can't remove a piece.
        // last = curr; //using last to hold curr values
        curr = curr->next; //then setting curr to its next element
        counter++; //incrementing curr by 1 each time the statements above are executed
        if (counter >= 5) { //if counter is 5, it means we need to free something
            break;
        }
    }
    last = curr->next;
    curr->next = NULL;
    board[userRow][userColumn + currentNumberOfPieces].num_pieces = 5;

    /*From line 36, I want to use last to get the colours of the pieces and check whether it is the current player's colour or their opponents, then place my colour on
     * the outside square pieces.
     *    ++ loop through the pieces
     *    ++ check the colour
     *    ++ if it's my colour, then increment "reservedPieces" by 1, if it's opponents colour, increment "opponentsCaptured" by 1
     *    ++ also, if it is my colour, then place that piece on one of the squares outside.
     *    * */

    int rowMove, columnMove;
    while(last != NULL)
    {
        if(last->p_color == players[playerIndex].player_color)
        {
            players[playerIndex].numberOfReservedTokens = players[playerIndex].numberOfReservedTokens + 1;
            printf("Enter correct side square to move it into. \n Enter Row & Column respectively\n");
            scanf("%d %d", &rowMove, &columnMove);

            if(board[rowMove][columnMove].type == VALID)
            {
                if(board[rowMove][columnMove].stack == NULL)
                {
                    last->next = board[rowMove][columnMove].stack;
                    board[rowMove][columnMove].num_pieces = board[rowMove][columnMove].num_pieces + 1;
                    board[rowMove][columnMove].stack = last;
                }
            }
        }
        else
        {
            players[playerIndex].numberOfOpponentsTokensCaptured = players[playerIndex].numberOfOpponentsTokensCaptured + 1;
        }
        last = last->next;
    }
    printf("Number Captured: %d\n", players[playerIndex].numberOfOpponentsTokensCaptured);
    printf("Reserved: %d\n", players[playerIndex].numberOfReservedTokens);

}

void removeUp(square board[8][8], int userRow, int userColumn, int currentNumberOfPieces, player players[2], int playerIndex) {
    int counter = 1; //a counter to hold the number of pieces we go through
    struct piece *curr = board[userRow - currentNumberOfPieces][userColumn].stack;//setting curr to equal to the top piece of the square
    //curr = malloc(sizeof(piece));
    struct piece *last = NULL;//
    struct piece *toRemove = NULL;
    //last = malloc(sizeof(piece));
    while (curr->next != NULL) { //while the next piece of a piece is not NULL, then keep looping, because if the next piece is NULL, we can't get to 5 on the counter, we can't remove a piece.
        // last = curr; //using last to hold curr values
        curr = curr->next; //then setting curr to its next element
        counter++; //incrementing curr by 1 each time the statements above are executed
        if (counter >= 5) { //if counter is 5, it means we need to free something
            break;
        }
    }
    last = curr->next;
    curr->next = NULL;
    board[userRow - currentNumberOfPieces][userColumn].num_pieces = 5;

    /*From line 36, I want to use last to get the colours of the pieces and check whether it is the current player's colour or their opponents, then place my colour on
     * the outside square pieces.
     *    ++ loop through the pieces
     *    ++ check the colour
     *    ++ if it's my colour, then increment "reservedPieces" by 1, if it's opponents colour, increment "opponentsCaptured" by 1
     *    ++ also, if it is my colour, then place that piece on one of the squares outside.
     *    * */

    int rowMove, columnMove;
    while(last != NULL)
    {
        if(last->p_color == players[playerIndex].player_color)
        {
            players[playerIndex].numberOfReservedTokens = players[playerIndex].numberOfReservedTokens + 1;
            printf("Enter correct side square to move it into. \n Enter Row & Column respectively\n");
            scanf("%d %d", &rowMove, &columnMove);

            if(board[rowMove][columnMove].type == VALID)
            {
                if(board[rowMove][columnMove].stack == NULL)
                {
                    last->next = board[rowMove][columnMove].stack;
                    board[rowMove][columnMove].num_pieces = board[rowMove][columnMove].num_pieces + 1;
                    board[rowMove][columnMove].stack = last;
                }
            }
        }
        else
        {
            players[playerIndex].numberOfOpponentsTokensCaptured = players[playerIndex].numberOfOpponentsTokensCaptured + 1;
        }
        last = last->next;
    }
    printf("Number Captured: %d\n", players[playerIndex].numberOfOpponentsTokensCaptured);
    printf("Reserved: %d\n", players[playerIndex].numberOfReservedTokens);

}

void removeDown(square board[8][8], int userRow, int userColumn, int currentNumberOfPieces, player players[2], int playerIndex) {
    int counter = 1; //a counter to hold the number of pieces we go through
    struct piece *curr = board[userRow + currentNumberOfPieces][userColumn].stack;//setting curr to equal to the top piece of the square
    //curr = malloc(sizeof(piece));
    struct piece *last = NULL;//
    struct piece *toRemove = NULL;
    //last = malloc(sizeof(piece));
    while (curr->next != NULL) { //while the next piece of a piece is not NULL, then keep looping, because if the next piece is NULL, we can't get to 5 on the counter, we can't remove a piece.
        // last = curr; //using last to hold curr values
        curr = curr->next; //then setting curr to its next element
        counter++; //incrementing curr by 1 each time the statements above are executed
        if (counter >= 5) { //if counter is 5, it means we need to free something
            break;
        }
    }
    last = curr->next;
    curr->next = NULL;
    board[userRow + currentNumberOfPieces][userColumn].num_pieces = 5;

    /*From line 36, I want to use last to get the colours of the pieces and check whether it is the current player's colour or their opponents, then place my colour on
     * the outside square pieces.
     *    ++ loop through the pieces
     *    ++ check the colour
     *    ++ if it's my colour, then increment "reservedPieces" by 1, if it's opponents colour, increment "opponentsCaptured" by 1
     *    ++ also, if it is my colour, then place that piece on one of the squares outside.
     *    * */

    int rowMove, columnMove;
    while(last != NULL)
    {
        if(last->p_color == players[playerIndex].player_color)
        {
            players[playerIndex].numberOfReservedTokens = players[playerIndex].numberOfReservedTokens + 1;
            printf("Enter correct side square to move it into. \n Enter Row & Column respectively\n");
            scanf("%d %d", &rowMove, &columnMove);

            if(board[rowMove][columnMove].type == VALID)
            {
                if(board[rowMove][columnMove].stack == NULL)
                {
                    last->next = board[rowMove][columnMove].stack;
                    board[rowMove][columnMove].num_pieces = board[rowMove][columnMove].num_pieces + 1;
                    board[rowMove][columnMove].stack = last;
                }
            }
        }else
        {
            players[playerIndex].numberOfOpponentsTokensCaptured = players[playerIndex].numberOfOpponentsTokensCaptured + 1;
        }
        last = last->next;
    }
    printf("Number Captured: %d\n", players[playerIndex].numberOfOpponentsTokensCaptured);
    printf("Reserved: %d\n", players[playerIndex].numberOfReservedTokens);

}