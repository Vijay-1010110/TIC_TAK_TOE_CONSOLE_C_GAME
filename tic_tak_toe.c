#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3] = {0}; 
int firstTurn = 1;
char computer = 'O';
char user = 'X';
int uWin = 0 , cWin = 0 ;

void displayBoard();
int genRan(int p1 , int p2);
void draw();
void computerT();
int genRan(int p1 , int p2);
int placeIf2_Oppo();
int placeIf2_com();
void check_u_Win();
void checkWin();


//**************************************************************
//**************************************************************
//**************************************************************

int main(){
    printf("\n**************TIC TAK TOE GAME********************\n\n");
    while(1){
        displayBoard();
        
        
        draw();
        check_u_Win();
        checkWin();
        computerT();
        
        
        checkWin();
        
    }

    return 0;
}

//**************************************************************
//**************************************************************
//**************************************************************

//generate random place
int genRan(int p1 , int p2){
    srand(time(NULL));
    int rNum = rand()%p2 + p1;
    return rNum;
}

//**************************************************************
//**************************************************************
//**************************************************************



void checkWin(){
    if(cWin == 1){
        displayBoard();
        printf("\n************************  Computer has won  ******************\n");
        exit(0);
    }else if(uWin == 1){
        displayBoard();
        printf("\n************************  You won  ******************\n");
        exit(0);
    }
    else{
        //check for match draw
        int c1 = 0;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(board[i][j] == 0){
                    c1++;
                }
            }
        }
        if(c1 == 0 && uWin != 1 && cWin != 1){
            printf("\n************************  Match Draw  ******************\n");
        exit(0);
        }
    }
}

//**************************************************************
//**************************************************************
//**************************************************************

//------------------------------------------
//check if computer have chance to win
int placeIf2_com(){
    int c1 = 0;
    int i1 = 0 , j1 = 0;
    int t1 = 0 ;

    //row check
    for (int i=0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[i][j] == computer){
                c1++;
            }
            if(board[i][j] == 0){
                i1 = i;
                j1 = j;
                t1 = 1;
            }
        }
        if(c1 == 2 && t1 == 1){
            board[i1][j1] = computer;
            return 1;
        }
        c1 = 0;
        t1 = 0;
    }

    //column checks
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[j][i] == computer){
                c1++;
            }
            if(board[j][i] == 0){
                j1 = j;
                i1 = i;
                t1 = 1;
            }
        }
        if(c1 == 2 && t1 == 1){
            board[j1][i1] = computer;
            return 1;
        }
        c1 = 0;
        t1 = 0;
    }


    //check diagonal  0 0 to 2 2
    for(int i = 0 ; i < 3 ; i++){
        if(board[i][i] == computer){
                c1++;
            }
        if(board[i][i] == 0){
                j1 = i;
                i1 = i;
                t1 = 1;
        }
    }
    if(c1 == 2 && t1 == 1){
            board[i1][j1] = computer;
            return 1;
    }
    c1 = 0;
    t1 = 0;

    
    //check diagonal 2 0 to 0 2
    int j = 0;
    for(int i = 2 ; i > -1 ; i--){
        do{
            if(board[i][j] == computer){
                c1++;
            }
            if(board[i][j] == 0){
                i1 = i;
                j1 = j;
                t1 = 1;
            }
            j++;
        }while(0);
    } 
    if(c1 == 2 && t1 == 1){
            board[i1][j1] = computer;
            return 1;
    }

    return 0;
}

//**************************************************************
//**************************************************************
//**************************************************************

//------------------------------------------------------
//check if opponant going to be win if any possible combination 
//that will going to be compilete
int placeIf2_Oppo(){
    int c1 = 0;
    int i1 = 0 , j1 = 0;
    int t1 = 0 ;

    //row check
    for (int i=0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[i][j] == user){
                c1++;
            }
            if(board[i][j] == 0){
                i1 = i;
                j1 = j;
                t1 = 1;
            }
        }
        if(c1 == 2 && t1 == 1){
            board[i1][j1] = computer;
            return 1;
        }
        c1 = 0;
        t1 = 0;
    }

    //column checks
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[j][i] == user){
                c1++;
            }
            if(board[j][i] == 0){
                j1 = j;
                i1 = i;
                t1 = 1;
            }
        }
        if(c1 == 2 && t1 == 1){
            board[j1][i1] = computer;
            return 1;
        }
        c1 = 0;
        t1 = 0;
    }


    //check diagonal  0 0 to 2 2
    for(int i = 0 ; i < 3 ; i++){
        if(board[i][i] == user){
                c1++;
            }
        if(board[i][i] == 0){
                j1 = i;
                i1 = i;
                t1 = 1;
        }
    }
    if(c1 == 2 && t1 == 1){
            board[i1][j1] = computer;
            return 1;
    }
    c1 = 0;
    t1 = 0;

    
    //check diagonal 2 0 to 0 2
    int j = 0;
    for(int i = 2 ; i > -1 ; i--){
        do{
            if(board[i][j] == user){
                c1++;
            }
            if(board[i][j] == 0){
                i1 = i;
                j1 = j;
                t1 = 1;
            }
            j++;
        }while(0);
    } 
    if(c1 == 2 && t1 == 1){
            board[i1][j1] = computer;
            return 1;
    }

    return 0;
}

//**************************************************************
//**************************************************************
//**************************************************************

void draw(){
    int i1,i2;

    while(1){
        printf("Enter the position ( x y ) ");
        scanf("%d %d", &i1 , &i2);
        i1--;
        i2--;
        if((i1 > -1 && i1 < 3) && (i2 > -1 && i2 < 3)){
            if(board[i1][i2] == 0){
                board[i1][i2] = 'X'; 
                break;
            }
            else{
                printf("\npostion already occupied...Enter different position\n");
            }
        }
        else{
            printf("\nInvalid position!...Try again\n");
        }
    }
}

//**************************************************************
//**************************************************************
//**************************************************************

void computerT(){
    //if computer has first turn
    if(firstTurn){
        int p1 = genRan(1,3);
        int p2 = genRan(1,3);

        board[p1][p2] = computer ;
        firstTurn = 0 ;
    }else{
        if(placeIf2_com()){
            displayBoard();
            cWin = 1;
            return;
        }
        else if(placeIf2_Oppo()){
            displayBoard();
            return;
        }
        else{
            while(1){
                int p1 = genRan(1,3);
                int p2 = genRan(1,3);
                if(board[p1][p2] == 0){
                    board[p1][p2] = computer;
                    return;
                }
            }
        }
    }
    
}

//**************************************************************
//**************************************************************
//**************************************************************

void check_u_Win(){
    int c1 = 0;
    //row checks
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[i][j] == user){
                c1++;
            }
            else{
                break;
            }
        }
        if(c1 == 3){
            uWin = 1;
            return;
        }
        c1 = 0;
    }

    //column checks
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[j][i] == user){
                c1++;
            }
            else{
                break;
            }
        }
        if(c1 == 3){
            uWin = 1;
            return;
        }
        c1 = 0;
    }

    //check diagonal 0 0 to 2 2
    for(int i = 0 ; i < 3 ; i++){
        if(board[i][i] == user){
            c1++;
        }
        else{
            break;
        }
    }
    if(c1 == 3){
        uWin = 1;
        return;
    }
    c1 = 0;

    //check diagonal  2 0 to 0 2 
    int j = 0;
    for(int i = 2 ; i > -1 ; i--){
        do{
            if(board[i][j] == user){
                c1++;
            }            
            j++;
        }while(0);
    } 
    if(c1 == 3){
        uWin = 1;
        return;
    }



}


//**************************************************************
//**************************************************************
//**************************************************************


void displayBoard(){
    printf("\n\n");
    printf("+---------------+");
    printf("---------------+");
    printf("---------------+");

    for(int i = 0 ; i < 3 ; i++){
        printf("\n");
        printf("|");

        for(int a = 0 ; a < 3 ; a++){
            printf("\t\t|");
        }

        printf("\n");
        printf("|");

        for(int j = 0 ; j < 3 ; j++){
            if(board[i][j] == 0)
            printf("\t%c\t|", 32);
            else
            printf("\t%c\t|", board[i][j]);
        }

        printf("\n");
        printf("|");

        for(int a = 0 ; a < 3 ; a++){
            printf("\t\t|");
        }

        printf("\n");
        printf("+---------------+");
        printf("---------------+");
        printf("---------------+");
    }
            printf("\n\n");
}