//
// Created by bomte on 27/03/2020.
//

#include "input_output.h"
#include "stackInit.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "startGame.h"

bool findWinner(square board[BOARD_SIZE][BOARD_SIZE]);
square moveItems(square board[BOARD_SIZE][BOARD_SIZE], int userRow, int userColumn, int currentNumberOfPieces);
/* FUnction to print the board:
* Invalid Squares are printed as | - |
* Valid empty squares are printed as |   |
* Valid squares with a GREEN piece are printed as | G |
* Valid squares with a RED piece are printed as | R | */
//int sizeCountG = 1;
//int sizeCountR = 1;
void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    int countR = 0;

   // printf("0 1 2 3 4 5 6 7 8 9 10");
    printf("****** The Board ******\n");
//    for(int k = 0; k < BOARD_SIZE; k++)
//    {
//
//    }
    printf("\t0   \t1 \t2 \t3  \t4 \t  5 \t6 \t7 \n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        printf("%d ", countR++);
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf(" |   ");
                else{
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| G%d ", board[i][j].num_pieces);
                    else printf("| R%d ", board[i][j].num_pieces);
                }
            }
            else
                printf(" | - ");
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
    int direction, rounds = 200;
    int player = 0;
    /*prompt the user to select co-ordinates of the square` they want to start from \/
     * check the colour of the game pieces belongs to the player.
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
     * ----------already know the no. of pieces
     *          - colour of the top piece
     *          - the position we are moving to and from
     * ---------   +++move the whole stack of the square the user is on (moving from)
     *                     >>moving from square to another square - changes<<
     *                       \\the no. of pieces increases on the new square
     *                       \\the no.of pieces decreases to 0 on the old square
     *                       \\the top piece of the new square is no longer the top pieces of that square
     *                       \\the top piece colour can change
     *
     *             +++ move that whole onto the top piece of the square the user is (moving to)
     *                [[[push the stack on current stack to the stack on square moving to using push operation
     *       #i need a variable to represent the top of the stack
     *           %this top variable will be incremented by the number of pieces moving. eg. if one stack (w/1 piece) is moving top = top + 1,
     *           %if one stack (w/2 pieces) is moving, top = top + 2, etc. (the number of pieces on the square)
     *           %also keep the note of the current colour as the top increases.
     *
     *
     *
     *                    -+- increment the top piece of the stack moving to by the number of pieces on the square moving from
     *                    -+- then set the incremented top piece to equal the top piece of stack the user wants to move
     *                    -+-
     *
     *             +++ get number of pieces on (new square) moved to
     *             +++ check if number piece is greater than 5, if it is, remove the bottom piece of the stack
     *             ++++ then check what colour the bottom piece of the stack is
     *             ++++ if the piece is the players colour, increment "numberOfReservedTokens" by 1, if it is opponent's colour increment "numberOfOpponentsTokensCaptured"
     *             +++ confirm that the square (moved from) is now empty but still val -- no. of pieces = 0;
     *
     *
     * if a stack contains more than 5 pieces, then a piece is removed from the bottom, and kept by the current player as reserved piece.
     * -------------if the colour of the bottom piece belongs to the current player == numberOfReservedTokens (can be used in the game again)
     * --------------if the colour is the opponent's colour = numberOfOpponentsTokensCaptured (can't be used in the game again)
     * keep playing until a player can make no more moves/dominates every stack on the board.
     * ------------- dominates = top piece of each stacks left on the game board is = to the same colour of either p1 or p2.
     * --------------    ++ get the top top piece of each stack on the game boards
     *                   ++ loop through every square of the board
     *                       ++get the number of pieces on the square
     *                       ++if number of pieces is > 0 = stack
     *                       ++then get the colour of top piece of that stack
     *                       ++if its p1 increment p1, if its p2 increment p2.
     *                       ++ once the all the squares have been looped through, check the count of p1 and p2
     *                       ++ check which count is == to the squares with number of pieces > 0
     * (the reserved pieces can be put back in the game if needed) - "not really aiming for a high score, so not needed."
     * */
//    unsigned int lengthOfPlayerArray = *(&players + 1) - players;
//    printf("%u", lengthOfPlayerArray);

    while (findWinner(board) != true) {
        int playerIndex;
        for(playerIndex = 0; playerIndex < PLAYERS_NUM; playerIndex++) {
            printf("%s playing now\n", players[playerIndex].playerName);
            int userRow, userColumn;
            //printf("%s playing now\n", players[p].playerName);
            printf("Enter the row of the square you want to go to.");
            scanf("%d", &userRow);
            printf("Enter the column of the square you want to go to.");
            scanf("%d", &userColumn);

//    if(players[playerIndex].player_color != board[userRow][userColumn].stack->p_color) {
//        break;
//    }

            if(board[userRow][userColumn].stack->p_color == players[playerIndex].player_color) {
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
                                printf("hey\n");
                                //pushItems();
                                moveItems(board,userRow,userColumn,currentSquarePieces);
                                print_board(board);
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
            }
        }
    }
}




bool findWinner(square board[BOARD_SIZE][BOARD_SIZE])
{
    int pl1 = 0, pl2 = 0, square = 0;
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j].type == VALID)
            {
                struct square currentSquare = board[i][j];
                int currentSquarePieces = currentSquare.num_pieces;

                if(currentSquarePieces > 0)
                {
                    square++;
                    if(board[i][j].stack->p_color == RED)
                    {
                        pl1++;
                    }
                    else if(board[i][j].stack->p_color == GREEN)
                    {
                        pl2++;
                    }

                }
            }
        }
    }

    if(square == pl1)
    {
        printf("Player 1 Has Won");
        return true;
    }
    else if(square == pl2)
    {
        printf("Player 2 Has Won");
        return true;
    }
    else
    {
        return false;
    }
}

square moveItems(square board[BOARD_SIZE][BOARD_SIZE], int userRow, int userColumn, int currentNumberOfPieces)
{
    square num1_pieces = board[userRow][userColumn - currentNumberOfPieces];
    int tempNumPieces = num1_pieces.num_pieces;
    struct piece *top = board[userRow][userColumn].stack;

    struct piece *curr = top;
    while(curr->next != NULL) {
        curr = curr->next;
        curr->p_color = curr->next->p_color;
        curr->next = board[userRow][userColumn - currentNumberOfPieces].stack;
    }
    //curr->next = board[userRow][userColumn - currentNumberOfPieces].stack;
    board[userRow][userColumn - currentNumberOfPieces].stack = top;
    board[userRow][userColumn - currentNumberOfPieces].num_pieces = tempNumPieces + currentNumberOfPieces;

    board[userRow][userColumn].num_pieces = 0;
    board[userRow][userColumn].stack = NULL;

//    square num1_pieces = board[userRow][userColumn - currentNumberOfPieces];
//    int tempNumPieces = num1_pieces.num_pieces;
//    int newNumPieces = tempNumPieces + currentNumberOfPieces;
//    board[userRow][userColumn - currentNumberOfPieces].stack = board[userRow][userColumn].stack;
//    board[userRow][userColumn].num_pieces = 0;
}

//void pushItems()
//{
//    struct piece *top = NULL;
//    newPiece = (struct piece*)malloc(sizeof(struct piece));
//
//    if(!newPiece)
//    {
//        perror("Stack is FULL");
//    }
//
//    newPiece->p_color =
//}