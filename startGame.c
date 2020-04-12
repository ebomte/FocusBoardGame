//
// Created by bomte on 27/03/2020.
//

#include "startGame.h"
#include "sizes.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>



void initialize_players(player players[PLAYERS_NUM]){

   // struct player recordOfPlayers[2];
   char s[5];

    for(int i = 0; i < PLAYERS_NUM; i++)
    {
        printf("Name: \n");
        scanf("%s", players[i].playerName);


        printf("Colour: R for Red, G for Green \n");
        scanf("%s",s);
        if(strcasecmp(s, "R") == 0)
        {
            players[i].player_color = RED;
        }
        else if(strcasecmp(s, "G") == 0)
        {
            players[i].player_color = GREEN;
        }

        players[i].numberOfOpponentsTokensCaptured = 0;
        players[i].numberOfReservedTokens = 0;
    }

    // implement here the functionality to initialize the players

}

//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s){
    s->type = INVALID;
    s->stack = NULL;
    s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s){
    s->type = VALID;
    s->stack = NULL;
    s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s){
    s->type = VALID;
    s->stack = (piece *) malloc (sizeof(piece));
    s->stack->p_color = GREEN;
    s->stack->next = NULL;
    s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s){
    s->type = VALID;
    s->stack = (piece *) malloc (sizeof(piece));
    s->stack->p_color = RED;
    s->stack->next = NULL;
    s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){
   // printf(" 0\t1\t2\t3\t4\t5\t6\t7\n");
    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }


    }


}

