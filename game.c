#include "game.h"
#include <stdio.h>


void game(){
    int board[3][3] = { 0 };
    bool isFirst = true;
    
    while(true){
        int BOARD_SIZE = 3;
        int turn = (int)!isFirst + 1;
        printf("%d P turn\n", turn);  
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < BOARD_SIZE; j++){
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        int inX = 0;
        int inY = 0;
        while(true){
            printf("enter your move:");
            scanf("%d %d", &inX, &inY);
            if(board[inX][inY] == 0) break;
        }

        board[inX][inY] = turn;
        if(isWin(board, inX, inY)){
            printf("%d P Win!\n", turn);
            return;
        }
        isFirst = !isFirst;
    }    
}

bool isWin(int board[][3], int x_, int y_){
    int turn = board[x_][y_];
    int boardForJudge[5][5] = { 0 };
    int x = x_ + 1;
    int y = y_ + 1;

    for (int i = 0; i < 5; i++){
        boardForJudge[i][0] = -1;
        boardForJudge[0][i] = -1;
        boardForJudge[i][4] = -1;
        boardForJudge[4][i] = -1;
    }


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            boardForJudge[i + 1][j + 1] = board[i][j];
        }
    }
    
    if(checkLine(1,  0, x, y, boardForJudge)) return true;
    if(checkLine(0,  1, x, y, boardForJudge)) return true;
    if(checkLine(1,  1, x, y, boardForJudge)) return true;
    if(checkLine(1, -1, x, y, boardForJudge)) return true;

    return false;
}


bool checkLine(int moveX, int moveY, int x, int y, int board[][5]){
    int turn = board[x][y];
    int count = 0;
    for(int i = 0; i < 3; i++){
        if(board[x + (i + 1) * moveX][y + (i + 1) * moveY] != turn) break;
    }
    for(int i = 0; i < 3; i++){
        if(board[x - (i + 1) * moveX][y - (i + 1) * moveY] == turn){
            count++;
        }
        else{
            return false;
        } 
        if(count == 3){
            return true;
        }
    }
    return false;
}

