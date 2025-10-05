/* 
Description: This program is a jeopardy game
Programmed by : Jediaelle Denise De Castro | S21B
Last Modified: Nov. 26, 2023
Version: final

This is to certify that this project is my own work, based on my personal efforts in studying and
applying the concepts learned. I have constructed the functions and their respective algorithms and
corresponding code all by myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise plagiarized the work of other
students and/or persons.

*/

#include <stdio.h>
#include "Machine_func.c"

int main(){
    //main menu
    int nMenu=0;
    int nNumplay;
    int nEnd;
    int nEndR2;

    //categories
    char cCategory;
    int nValue;
    int nWager = 0;

    //scores of players
    int nPlayer1 = 0;
    int nPlayer2 = 0;

    int Player_toAns;

    char cAnswer;
    bool bCorrect;

    //game board
    int nBoard;
    //updates game board
    int s100 = 100;
    int s500 = 500;
    int s1000 = 1000;
    int s5000 = 5000;
    int s10000 = 10000;
    int tv100 = 100;
    int tv500 = 500;
    int tv1000 = 1000;
    int tv5000 = 5000;
    int tv10000 = 10000;
    int m100 = 100;
    int m500 = 500;
    int m1000 = 1000;
    int m5000 = 5000;
    int m10000 = 10000;
    int g100 = 100;
    int g500 = 500;
    int g1000 = 1000;
    int g5000 = 5000;
    int g10000 = 10000;
    
    //attempts per round
    int nAttempts = 0;
    int nAttemptsR2 = 0;

    //MAIN MENU
    while(nMenu != 3){
        printf("\n\n****** Jeopardy Game ******");
        printf("\n1. PLAY\n2. HOW TO PLAY\n3. QUIT\nYour Choice: ");
        scanf("%d", &nMenu);

        // 1. PLAY
        if(nMenu == 1){
            nMenu=3;

            srand(time(NULL));
            nBoard = (rand() % 4)+1;

            // NUMBER OF PLAYERS TO PLAY
            printf("\nHow many players? [1-2]");
            scanf("%d", &nNumplay);
            if (nNumplay == 1){
                printf("\nJeopardy Round\n");

                if (nBoard == 1){
                    gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                    while (nAttempts <=3){
                        cCategory = getCategory_gameboard1();
                        nValue = getValue();
                        displayQuestion_gameboard1(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);

                        //to determine if answered question is correct or not
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }                     
                        }
                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);        
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }                    
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }                 
                        }
                        
                        //will computer for the player's score
                        player1Score(&nPlayer1, nValue, bCorrect); 
                        nAttempts++;
                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                    
                    }       
                
                    printf("\nEND ROUND? (Continue[1], End[2])");
                    printf("\nYour Choice: ");
                    scanf("%d", &nEnd);
                    if (nEnd == 1){
                        printf("\nDouble Round\n");
                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                        while (nAttemptsR2 <=1){
                        cCategory = getCategory_gameboard1();
                        nValue = getValue();
                        displayQuestion_gameboard1(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);                     
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }
                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Music_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;    
                            } 
                        }
                        player1Score_Double(&nPlayer1, nValue, bCorrect); 
                        nAttemptsR2++;
                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                        }              
                    
                        printf("\nEND ROUND? (Continue[1], End[2])");
                        printf("\nYour Choice: ");
                        scanf("%d", &nEndR2);
                    }
                    else if (nEnd == 2){
                        nEndR2 = 2;
                    }
                   
                    if (nEndR2 == 1){
                        printf("\nFinal Round\n");
                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);               
                        cCategory = getCategory_gameboard1();
                        nValue = getValue();
                        printf("\nCurrent Score: %d", nPlayer1);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer1){
                            printf("\nCurrent Score: %d", nPlayer1);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard1(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }                     
                        }

                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);   
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }                   
                        }

                        else if (cCategory == 'C'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }                    
                        }
                        final1Player(&nPlayer1, nWager, bCorrect); 
                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                        printf("\nFinal Score: %d", nPlayer1);
                        printf("\nThank you for playing!");                       
                    }

                    else if (nEndR2 == 2){
                        printf("\nFinal Score: %d", nPlayer1);
                        printf("\nThank you for playing!");
                    }
                }

                else if (nBoard == 2){
                    gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                    while (nAttempts <=3){
                        cCategory = getCategory_gameboard2();
                        nValue = getValue();
                        displayQuestion_gameboard2(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = TV_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }

                        }
                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer);                    
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        player1Score(&nPlayer1, nValue, bCorrect); 
                        nAttempts++;
                        gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                        }
                        printf("\nEND ROUND? (Continue[1], End[2])");
                        printf("\nYour Choice: ");
                        scanf("%d", &nEnd);

                        if (nEnd == 1){
                            printf("\nDouble Round\n");
                            gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                            while (nAttemptsR2 <=1){
                                cCategory = getCategory_gameboard2();
                                nValue = getValue();
                                displayQuestion_gameboard2(cCategory, nValue);
                                printf("\nType your answer: ");
                                scanf(" %c", &cAnswer);
                                if (cCategory == 'A'){
                                    bCorrect = TV_answerKey(nValue, cAnswer);   
                                    switch (nValue){
                                        case 100: tv100 = 0;
                                            break;
                                        case 500: tv500 = 0;    
                                            break;
                                        case 1000: tv1000 = 0;     
                                            break;
                                        case 5000: tv5000 = 0;     
                                            break;
                                        case 10000: tv10000 = 0;     
                                    }
                                }

                                else if (cCategory == 'B'){
                                    bCorrect = Music_answerKey(nValue, cAnswer);
                                    switch (nValue){
                                        case 100: m100 = 0;
                                            break;
                                        case 500: m500 = 0;    
                                            break;
                                        case 1000: m1000 = 0;     
                                            break;
                                        case 5000: m5000 = 0;     
                                            break;
                                        case 10000: m10000 = 0;     
                                    }
                                }

                                else if (cCategory == 'C'){
                                    bCorrect = Geography_answerKey(nValue, cAnswer);
                                    switch (nValue){
                                        case 100: g100 = 0;
                                            break;
                                        case 500: g500 = 0;    
                                            break;
                                        case 1000: g1000 = 0;     
                                            break;
                                        case 5000: g5000 = 0;     
                                            break;
                                        case 10000: g10000 = 0;     
                                    }
                                }
                                player1Score_Double(&nPlayer1, nValue, bCorrect); 
                                nAttemptsR2++;
                                gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                            }
                            
                            printf("\nEND ROUND? (Continue[1], End[2])");
                            printf("\nYour Choice: ");
                            scanf("%d", &nEndR2);
                        }
                        else if (nEnd == 2){
                            nEndR2 = 2;
                        }
                        if (nEndR2 == 1){
                            printf("\nFinal Round\n");
                            gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                            cCategory = getCategory_gameboard2();
                            nValue = getValue();
                            printf("\nCurrent Score: %d", nPlayer1);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                            while (nWager > nPlayer1){
                                printf("\nCurrent Score: %d", nPlayer1);
                                printf("\nPick any amount to wager from your current score: ");
                                scanf("%d", &nWager);
                            }
                            printf("\nHere is your question:");
                            displayQuestion_gameboard2(cCategory, nValue);
                            printf("\nType your answer: ");
                            scanf(" %c", &cAnswer);
                            if (cCategory == 'A'){
                                bCorrect = TV_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: tv100 = 0;
                                        break;
                                    case 500: tv500 = 0;    
                                        break;
                                    case 1000: tv1000 = 0;     
                                        break;
                                    case 5000: tv5000 = 0;     
                                        break;
                                    case 10000: tv10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = Music_answerKey(nValue, cAnswer);                               
                                switch (nValue){
                                    case 100: m100 = 0;
                                        break;
                                    case 500: m500 = 0;    
                                        break;
                                    case 1000: m1000 = 0;     
                                        break;
                                    case 5000: m5000 = 0;     
                                        break;
                                    case 10000: m10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                            final1Player(&nPlayer1, nWager, bCorrect);                  
                            gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                            printf("\nFinal Score: %d", nPlayer1);
                            printf("\nThank you for playing!");
                            }

                        else if (nEndR2 == 2){
                            printf("\nFinal Score: %d", nPlayer1);
                            printf("\nThank you for playing!");
                        }              
                }

                else if (nBoard == 3){
                    gameboard3(s100, s500, s1000 ,s5000 ,s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                    while (nAttempts <=3){
                        cCategory = getCategory_gameboard3();
                        nValue = getValue();
                        displayQuestion_gameboard3(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        player1Score(&nPlayer1, nValue, bCorrect);
                        nAttempts++;
                        gameboard3(s100, s500, s1000 ,s5000 ,s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);    
                    }
                    
                    printf("\nEND ROUND? (Continue[1], End[2])");
                    printf("\nYour Choice: ");
                    scanf("%d", &nEnd);

                    if (nEnd == 1){
                    printf("\nDouble Round\n");
                    gameboard3(s100, s500, s1000 ,s5000 ,s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);    
                    while (nAttemptsR2 <=1){
                        cCategory = getCategory_gameboard3();
                        nValue = getValue();
                        displayQuestion_gameboard3(cCategory, nValue);      
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);          
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer);                
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);                
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        player1Score_Double(&nPlayer1, nValue, bCorrect);
                        nAttemptsR2++;
                        gameboard3(s100, s500, s1000 ,s5000 ,s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);    
                    }

                    printf("\nEND ROUND? (Continue[1], End[2])");
                    printf("\nYour Choice: ");
                    scanf("%d", &nEndR2);
                    }

                    else if (nEnd == 2){
                            nEndR2 = 2;
                    }
                    if (nEndR2 == 1){
                        printf("\nFinal Round\n");
                        gameboard3(s100, s500, s1000 ,s5000 ,s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                        cCategory = getCategory_gameboard3();
                        nValue = getValue();
                        printf("\nCurrent Score: %d", nPlayer1);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer1){
                            printf("\nCurrent Score: %d", nPlayer1);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard3(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);  
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);                        
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer);                        
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);                        
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        final1Player(&nPlayer1, nWager, bCorrect);
                        gameboard3(s100, s500, s1000 ,s5000 ,s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                        printf("\nFinal Score: %d", nPlayer1);
                        printf("\nThank you for playing!");
                        }

                    else if (nEndR2 == 2){
                        printf("\nFinal Score: %d", nPlayer1);
                        printf("\nThank you for playing!");
                    }                 
                }

                else if (nBoard == 4){
                    gameboard4(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                    while (nAttempts <=3){
                        cCategory = getCategory_gameboard4();
                        nValue = getValue();
                        displayQuestion_gameboard4(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);       
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        player1Score(&nPlayer1, nValue, bCorrect);
                        nAttempts++;
                        gameboard4(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                    }

                    printf("\nEND ROUND? (Continue[1], End[2])");
                    printf("\nYour Choice: ");
                    scanf("%d", &nEnd);

                    if (nEnd == 1){
                    printf("\nDouble Round\n");
                    gameboard4(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                    while (nAttemptsR2 <=1){
                        cCategory = getCategory_gameboard4();
                        nValue = getValue();
                        displayQuestion_gameboard4(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);

                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);   
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);  
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        player1Score_Double(&nPlayer1, nValue, bCorrect);
                        nAttemptsR2++;
                        gameboard4(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                    } 
                    
                    printf("\nEND ROUND? (Continue[1], End[2])");
                    printf("\nYour Choice: ");
                    scanf("%d", &nEndR2);
                    }

                    else if (nEnd == 2){
                        nEndR2 = 2;
                    }

                    if (nEndR2 == 1){
                        printf("\nFinal Round\n");
                        gameboard4(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                        cCategory = getCategory_gameboard3();
                        nValue = getValue();
                        printf("\nCurrent Score: %d", nPlayer1);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer1){
                            printf("\nCurrent Score: %d", nPlayer1);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard4(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);                        
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);                        
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);                        
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        final1Player(&nPlayer1, nWager, bCorrect);
                        gameboard4(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                        printf("\nFinal Score: %d", nPlayer1);
                        printf("\nThank you for playing!");
                        }

                    else if (nEndR2 == 2){
                        printf("\nFinal Score: %d", nPlayer1);
                        printf("\nThank you for playing!");
                    }              
                
                }
            
            }//numplay 1

            else if (nNumplay == 2){
                printf("player 2\n");

                if (nBoard == 1){
                    Player_toAns=1; //player 1 will answer first
                    gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);

                    while (nAttempts<=7){ 
                        if (Player_toAns==1){
                            printf("\nPlayer 1: ");
                            cCategory = getCategory_gameboard1();
                            nValue = getValue();
                            displayQuestion_gameboard1(cCategory, nValue);
                            printf("\nType your answer: ");
                            scanf(" %c", &cAnswer);
                            if (cCategory == 'A'){
                                bCorrect = Sports_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: s100 = 0;
                                        break;
                                    case 500: s500 = 0;    
                                        break;
                                    case 1000: s1000 = 0;     
                                        break;
                                    case 5000: s5000 = 0;     
                                        break;
                                    case 10000: s10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = TV_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: tv100 = 0;
                                        break;
                                    case 500: tv500 = 0;    
                                        break;
                                    case 1000: tv1000 = 0;     
                                        break;
                                    case 5000: tv5000 = 0;     
                                        break;
                                    case 10000: tv10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Music_answerKey(nValue, cAnswer);                         
                                switch (nValue){
                                    case 100: m100 = 0;
                                        break;
                                    case 500: m500 = 0;    
                                        break;
                                    case 1000: m1000 = 0;     
                                        break;
                                    case 5000: m5000 = 0;     
                                        break;
                                    case 10000: m10000 = 0;     
                                }
                            }
                            

                            if (bCorrect == 0){
                                nPlayer1 = nPlayer1 + nValue;
                                printf("\nPlayer 1 Score: %d", nPlayer1); 
                                printf("\nPlayer 2 Score: %d", nPlayer2); 
                                nAttempts = nAttempts + 1;
                                Player_toAns=2;
                            }
                            else if (bCorrect == 1){
                                printf("\nPlayer 2: ");
                                displayQuestion_gameboard1(cCategory, nValue);
                                printf("\nType your answer: ");
                                scanf(" %c", &cAnswer);
                                if (cCategory == 'A'){
                                    bCorrect = Sports_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'B'){
                                    bCorrect = TV_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'C'){
                                    bCorrect = Music_answerKey(nValue, cAnswer);                         
                                }
                            
                                if (bCorrect == 0){
                                    nPlayer2 = nPlayer2 + nValue;
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;    
                                    Player_toAns=2;
                                }
                                else if (bCorrect == 1){
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;
                                    Player_toAns=1;
                                }
                            }                       
                        
                            gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                        }

                        else if (Player_toAns==2){
                            printf("\nPlayer 2: ");
                            cCategory = getCategory_gameboard1();
                            nValue = getValue();
                            displayQuestion_gameboard1(cCategory, nValue);
                            printf("\nType your answer: ");
                            scanf(" %c", &cAnswer);
                            if (cCategory == 'A'){
                                bCorrect = Sports_answerKey(nValue, cAnswer);                         
                                switch (nValue){
                                    case 100: s100 = 0;
                                        break;
                                    case 500: s500 = 0;    
                                        break;
                                    case 1000: s1000 = 0;     
                                        break;
                                    case 5000: s5000 = 0;     
                                        break;
                                    case 10000: s10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = TV_answerKey(nValue, cAnswer);                                
                                switch (nValue){
                                    case 100: tv100 = 0;
                                        break;
                                    case 500: tv500 = 0;    
                                        break;
                                    case 1000: tv1000 = 0;     
                                        break;
                                    case 5000: tv5000 = 0;     
                                        break;
                                    case 10000: tv10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Music_answerKey(nValue, cAnswer);                         
                                switch (nValue){
                                    case 100: m100 = 0;
                                        break;
                                    case 500: m500 = 0;    
                                        break;
                                    case 1000: m1000 = 0;     
                                        break;
                                    case 5000: m5000 = 0;     
                                        break;
                                    case 10000: m10000 = 0;     
                                }
                            }
                                        
                            if (bCorrect == 0){
                                nPlayer2 = nPlayer2 + nValue;
                                printf("\nPlayer 1 Score: %d", nPlayer1); 
                                printf("\nPlayer 2 Score: %d", nPlayer2); 
                                nAttempts = nAttempts + 1;
                                Player_toAns=1;
                            }
                            else if (bCorrect == 1){
                                printf("\nPlayer 1: ");
                                displayQuestion_gameboard1(cCategory, nValue);
                                printf("\nType your answer: ");
                                scanf(" %c", &cAnswer);
                                if (cCategory == 'A'){
                                    bCorrect = Sports_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'B'){
                                    bCorrect = TV_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'C'){
                                    bCorrect = Music_answerKey(nValue, cAnswer);                         
                                }
                            
                                if (bCorrect == 0){
                                    nPlayer1 = nPlayer1 + nValue;
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;    
                                    Player_toAns=1;
                                }
                                else if (bCorrect == 1){
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;
                                    Player_toAns=2;
                                }
                            }
                                
                            gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);                           
                        }
                    }   

                    printf("\nEND ROUND? (Continue[1], End[2])");
                    printf("\nYour Choice: ");
                    scanf("%d", &nEnd);

                    if (nEnd == 1){
                        printf("\nDouble Round\n");
                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                        
                        while (nAttemptsR2 <2){
                        printf("\nPlayer 1: ");
                        printf("\nCurrent Score: %d", nPlayer1);
                        cCategory = getCategory_gameboard1();
                        nValue = getValue();
                        displayQuestion_gameboard1(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }                    
                        Score_Double_2P(&nPlayer1, nValue, bCorrect);   
                        printf("\nPlayer 1 Score: %d", nPlayer1);
                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                    
                        printf("\nPlayer 2: ");
                        printf("\nCurrent Score: %d", nPlayer2);
                        cCategory = getCategory_gameboard1();
                        nValue = getValue();
                        displayQuestion_gameboard1(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }                             
                        Score_Double_2P(&nPlayer2, nValue, bCorrect);
                        printf("\nPlayer 2 Score: %d", nPlayer2);                       
                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                        nAttemptsR2++;
                        }
                        printf("\nPlayer 1 Score: %d", nPlayer1); 
                        printf("\nPlayer 2 Score: %d", nPlayer2); 

                        printf("\n\nEND ROUND? (Continue[1], End[2])");
                        printf("\nYour Choice: ");
                        scanf("%d", &nEndR2);
                    }

                    else if (nEnd == 2){
                        nEndR2 = 2;
                    }

                    if (nEndR2 == 1){
                        printf("\nFinal Round\n");

                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);                                       
                        printf("\nPlayer 1: ");
                        cCategory = getCategory_gameboard1();
                        nValue = getValue();
                        printf("\nPlayer 1 Current Score: %d", nPlayer1);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer1){
                            printf("\nPlayer 1 Current Score: %d", nPlayer1);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard1(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }                     
                        }
                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);                             
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }                   
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Music_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }                    
                        }      
                        final1Player(&nPlayer1, nWager, bCorrect);
                        printf("\nPlayer 1 Final Score: %d", nPlayer1);

                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);               
                        printf("\n\nPlayer 2: ");
                        cCategory = getCategory_gameboard1();
                        nValue = getValue();
                        printf("\nPlayer 2 Current Score: %d", nPlayer2);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer2){
                            printf("\n Player 2 Current Score: %d", nPlayer2);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard1(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }                     
                        }
                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);                             
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }                   
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Music_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }                    
                        }                        
                        final1Player(&nPlayer2, nWager, bCorrect);
                        printf("\nPlayer 2 Final Score: %d", nPlayer2);

                        gameboard1(s100, s500, s1000 ,s5000 ,s10000, tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000);
                        winnerWho(&nPlayer1, &nPlayer2);
                        printf("\nThank you for playing!");
                    }

                    else if (nEndR2 == 2){
                        winnerWho(&nPlayer1, &nPlayer2);
                        printf("\nThank you for playing!");
                    }

                }
        
                else if (nBoard == 2){
                    Player_toAns=1; 
                    gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                
                    while (nAttempts<=7){
                        if (Player_toAns==1){
                            printf("\nPlayer 1: ");
                            cCategory = getCategory_gameboard2();
                            nValue = getValue();
                            displayQuestion_gameboard2(cCategory, nValue);
                            printf("\nType your answer: ");
                            scanf(" %c", &cAnswer);

                            if (cCategory == 'A'){
                                bCorrect = TV_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: tv100 = 0;
                                        break;
                                    case 500: tv500 = 0;    
                                        break;
                                    case 1000: tv1000 = 0;     
                                        break;
                                    case 5000: tv5000 = 0;     
                                        break;
                                    case 10000: tv10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = Music_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: m100 = 0;
                                        break;
                                    case 500: m500 = 0;    
                                        break;
                                    case 1000: m1000 = 0;     
                                        break;
                                    case 5000: m5000 = 0;     
                                        break;
                                    case 10000: m10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){                          
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                            
                            if (bCorrect == 0){
                                nPlayer1 = nPlayer1 + nValue;
                                printf("\nPlayer 1 Score: %d", nPlayer1); 
                                printf("\nPlayer 2 Score: %d", nPlayer2); 
                                nAttempts = nAttempts + 1;
                                Player_toAns=2;
                            }
                            else if (bCorrect == 1){
                                printf("\nPlayer 2: ");
                                displayQuestion_gameboard2(cCategory, nValue);
                                printf("\nType your answer: ");
                                scanf(" %c", &cAnswer);
                                if (cCategory == 'A'){
                                    bCorrect = TV_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'B'){
                                    bCorrect = Music_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'C'){
                                    bCorrect = Geography_answerKey(nValue, cAnswer);                         
                                }
                            
                                if (bCorrect == 0){
                                    nPlayer2 = nPlayer2 + nValue;
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;    
                                    Player_toAns=2;
                                }
                                else if (bCorrect == 1){
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;
                                    Player_toAns=1;
                                }
                            }                       
                        
                        gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                
                        }
              
                        else if (Player_toAns==2){
                            printf("\nPlayer 2: ");
                            cCategory = getCategory_gameboard2();
                            nValue = getValue();
                            displayQuestion_gameboard2(cCategory, nValue);
                            printf("\nType your answer: ");
                            scanf(" %c", &cAnswer);

                            if (cCategory == 'A'){
                                bCorrect = TV_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: tv100 = 0;
                                        break;
                                    case 500: tv500 = 0;    
                                        break;
                                    case 1000: tv1000 = 0;     
                                        break;
                                    case 5000: tv5000 = 0;     
                                        break;
                                    case 10000: tv10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = Music_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: m100 = 0;
                                        break;
                                    case 500: m500 = 0;    
                                        break;
                                    case 1000: m1000 = 0;     
                                        break;
                                    case 5000: m5000 = 0;     
                                        break;
                                    case 10000: m10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }

                            }
                                        
                            if (bCorrect == 0){
                                nPlayer2 = nPlayer2 + nValue;
                                printf("\nPlayer 1 Score: %d", nPlayer1); 
                                printf("\nPlayer 2 Score: %d", nPlayer2); 
                                nAttempts = nAttempts + 1;
                                Player_toAns=1;
                            }
                            else if (bCorrect == 1){
                                printf("\nPlayer 1: ");
                                displayQuestion_gameboard2(cCategory, nValue);
                                printf("\nType your answer: ");
                                scanf(" %c", &cAnswer);
                                if (cCategory == 'A'){
                                    bCorrect = TV_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'B'){
                                    bCorrect = Music_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'C'){
                                    bCorrect = Geography_answerKey(nValue, cAnswer);                         
                                }
                            
                                if (bCorrect == 0){
                                    nPlayer1 = nPlayer1 + nValue;
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;    
                                    Player_toAns=1;
                                }
                                else if (bCorrect == 1){
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;
                                    Player_toAns=2;
                                }
                            }
                              
                              gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                
                        }

                    }

                    printf("\nEND ROUND? (Continue[1], End[2])");
                    printf("\nYour Choice: ");
                    scanf("%d", &nEnd);

                    if (nEnd == 1){
                        printf("\nDouble Round\n");
                        gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                                          
                        while (nAttemptsR2 <2){
                        printf("\nPlayer 1: ");
                        printf("\nCurrent Score: %d", nPlayer1);
                        cCategory = getCategory_gameboard2();
                        nValue = getValue();
                        displayQuestion_gameboard2(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        
                            if (cCategory == 'A'){
                                bCorrect = TV_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: tv100 = 0;
                                        break;
                                    case 500: tv500 = 0;    
                                        break;
                                    case 1000: tv1000 = 0;     
                                        break;
                                    case 5000: tv5000 = 0;     
                                        break;
                                    case 10000: tv10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = Music_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: m100 = 0;
                                        break;
                                    case 500: m500 = 0;    
                                        break;
                                    case 1000: m1000 = 0;     
                                        break;
                                    case 5000: m5000 = 0;     
                                        break;
                                    case 10000: m10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                            
                        Score_Double_2P(&nPlayer1, nValue, bCorrect);
                        printf("\nPlayer 1 Score: %d", nPlayer1);
                        gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                
                        printf("\nPlayer 2: ");
                        printf("\nCurrent Score: %d", nPlayer2);
                        cCategory = getCategory_gameboard2();
                        nValue = getValue();
                        displayQuestion_gameboard2(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                    
                        if (cCategory == 'A'){
                            bCorrect = TV_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                        
                        Score_Double_2P(&nPlayer2, nValue, bCorrect);
                        printf("\nPlayer 2 Score: %d", nPlayer2);                       
                        gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                        nAttemptsR2++;
                        }

                        printf("\nPlayer 1 Score: %d", nPlayer1); 
                        printf("\nPlayer 2 Score: %d", nPlayer2); 

                        printf("\n\nEND ROUND? (Continue[1], End[2])");
                        printf("\nYour Choice: ");
                        scanf("%d", &nEndR2);
                    }

                    else if (nEnd == 2){
                        nEndR2 = 2;
                    }

                    if (nEndR2 == 1){
                        printf("\nFinal Round\n");

                        gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                        printf("\nPlayer 1: ");
                        cCategory = getCategory_gameboard2();
                        nValue = getValue();
                        printf("\nPlayer 1 Current Score: %d", nPlayer1);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer1){
                            printf("\nPlayer 1 Current Score: %d", nPlayer1);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard2(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = TV_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }
                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        final1Player(&nPlayer1, nWager, bCorrect); 
                        printf("\nPlayer 1 Final Score: %d", nPlayer1);

                        gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);               
                        printf("\n\nPlayer 2: ");
                        cCategory = getCategory_gameboard2();
                        nValue = getValue();
                        printf("\nPlayer 2 Current Score: %d", nPlayer2);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer2){
                            printf("\n Player 2 Current Score: %d", nPlayer2);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard2(cCategory, nValue);        
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);                
                        if (cCategory == 'A'){
                            bCorrect = TV_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }
                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }    
                        final1Player(&nPlayer2, nWager, bCorrect); 
                        printf("\nPlayer 2 Final Score: %d", nPlayer2);

                        gameboard2(tv100, tv500, tv1000, tv5000, tv10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);               
                        winnerWho(&nPlayer1, &nPlayer2);
                        printf("\nThank you for playing!");
                    }

                    else if (nEndR2 == 2){
                        winnerWho(&nPlayer1, &nPlayer2);
                        printf("\nThank you for playing!");
                    }
                
                }

                else if (nBoard == 3){
                    Player_toAns=1; 
                    gameboard3(s100, s500, s1000, s5000, s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                
                    while (nAttempts<=7){
                        if (Player_toAns==1){
                            printf("\nPlayer 1: ");
                            cCategory = getCategory_gameboard3();
                            nValue = getValue();
                            displayQuestion_gameboard3(cCategory, nValue);
                            printf("\nType your answer: ");
                            scanf(" %c", &cAnswer);

                            if (cCategory == 'A'){
                                bCorrect = Sports_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: s100 = 0;
                                        break;
                                    case 500: s500 = 0;    
                                        break;
                                    case 1000: s1000 = 0;     
                                        break;
                                    case 5000: s5000 = 0;     
                                        break;
                                    case 10000: s10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = Music_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: m100 = 0;
                                        break;
                                    case 500: m500 = 0;    
                                        break;
                                    case 1000: m1000 = 0;     
                                        break;
                                    case 5000: m5000 = 0;     
                                        break;
                                    case 10000: m10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                            
                            if (bCorrect == 0){
                                nPlayer1 = nPlayer1 + nValue;
                                printf("\nPlayer 1 Score: %d", nPlayer1); 
                                printf("\nPlayer 2 Score: %d", nPlayer2); 
                                nAttempts = nAttempts + 1;
                                Player_toAns=2;
                            }
                            else if (bCorrect == 1){
                                printf("\nPlayer 2: ");
                                displayQuestion_gameboard3(cCategory, nValue);
                                printf("\nType your answer: ");
                                scanf(" %c", &cAnswer);
                                if (cCategory == 'A'){
                                    bCorrect = Sports_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'B'){
                                    bCorrect = Music_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'C'){
                                    bCorrect = Geography_answerKey(nValue, cAnswer);                         
                                }
                            
                                if (bCorrect == 0){
                                    nPlayer2 = nPlayer2 + nValue;
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;    
                                    Player_toAns=2;
                                }
                                else if (bCorrect == 1){
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;
                                    Player_toAns=1;
                                }
                            }                       
                        
                        gameboard3(s100, s500, s1000, s5000, s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                
                        }
           
                        else if (Player_toAns==2){
                            printf("\nPlayer 2: ");
                            cCategory = getCategory_gameboard3();
                            nValue = getValue();
                            displayQuestion_gameboard3(cCategory, nValue);
                            printf("\nType your answer: ");
                            scanf(" %c", &cAnswer);
                                
                            if (cCategory == 'A'){
                                bCorrect = Sports_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: s100 = 0;
                                        break;
                                    case 500: s500 = 0;    
                                        break;
                                    case 1000: s1000 = 0;     
                                        break;
                                    case 5000: s5000 = 0;     
                                        break;
                                    case 10000: s10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = Music_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: m100 = 0;
                                        break;
                                    case 500: m500 = 0;    
                                        break;
                                    case 1000: m1000 = 0;     
                                        break;
                                    case 5000: m5000 = 0;     
                                        break;
                                    case 10000: m10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                                                            
                            if (bCorrect == 0){
                                nPlayer2 = nPlayer2 + nValue;
                                printf("\nPlayer 1 Score: %d", nPlayer1); 
                                printf("\nPlayer 2 Score: %d", nPlayer2); 
                                nAttempts = nAttempts + 1;
                                Player_toAns=1;
                            }
                            else if (bCorrect == 1){
                                printf("\nPlayer 1: ");
                                displayQuestion_gameboard3(cCategory, nValue);
                                printf("\nType your answer: ");
                                scanf(" %c", &cAnswer);
                                if (cCategory == 'A'){
                                    bCorrect = Sports_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'B'){
                                    bCorrect = Music_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'C'){
                                    bCorrect = Geography_answerKey(nValue, cAnswer);                         
                                }
                            
                                if (bCorrect == 0){
                                    nPlayer1 = nPlayer1 + nValue;
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;    
                                    Player_toAns=1;
                                }
                                else if (bCorrect == 1){
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;
                                    Player_toAns=2;
                                }
                            }
                              
                            gameboard3(s100, s500, s1000, s5000, s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                
                        }

                    }

                    printf("\nEND ROUND? (Continue[1], End[2])");
                    printf("\nYour Choice: ");
                    scanf("%d", &nEnd);

                    if (nEnd == 1){
                        printf("\nDouble Round\n");
                        gameboard3(s100, s500, s1000, s5000, s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                                  
                        while (nAttemptsR2 <2){
                        printf("\nPlayer 1: ");
                        printf("\nCurrent Score: %d", nPlayer1);
                        cCategory = getCategory_gameboard3();
                        nValue = getValue();
                        displayQuestion_gameboard3(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        
                            if (cCategory == 'A'){
                                bCorrect = Sports_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: s100 = 0;
                                        break;
                                    case 500: s500 = 0;    
                                        break;
                                    case 1000: s1000 = 0;     
                                        break;
                                    case 5000: s5000 = 0;     
                                        break;
                                    case 10000: s10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = Music_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: m100 = 0;
                                        break;
                                    case 500: m500 = 0;    
                                        break;
                                    case 1000: m1000 = 0;     
                                        break;
                                    case 5000: m5000 = 0;     
                                        break;
                                    case 10000: m10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                            
                        Score_Double_2P(&nPlayer1, nValue, bCorrect);  
                        printf("\nPlayer 1 Score: %d", nPlayer1);
                        gameboard3(s100, s500, s1000, s5000, s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                
                        printf("\nPlayer 2: ");
                        printf("\nCurrent Score: %d", nPlayer2);
                        cCategory = getCategory_gameboard3();
                        nValue = getValue();
                        displayQuestion_gameboard3(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                    
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                        Score_Double_2P(&nPlayer2, nValue, bCorrect);                   
                        printf("\nPlayer 2 Score: %d", nPlayer2);                       
                        gameboard3(s100, s500, s1000, s5000, s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                        nAttemptsR2++;
                        }

                        printf("\nPlayer 1 Score: %d", nPlayer1); 
                        printf("\nPlayer 2 Score: %d", nPlayer2); 

                        printf("\n\nEND ROUND? (Continue[1], End[2])");
                        printf("\nYour Choice: ");
                        scanf("%d", &nEndR2);
                    }

                    else if (nEnd == 2){
                        nEndR2 = 2;
                    }

                    if (nEndR2 == 1){
                        printf("\nFinal Round\n");

                        gameboard3(s100, s500, s1000, s5000, s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                        printf("\nPlayer 1: ");
                        cCategory = getCategory_gameboard3();
                        nValue = getValue();
                        printf("\nPlayer 1 Current Score: %d", nPlayer1);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer1){
                            printf("\nPlayer 1 Current Score: %d", nPlayer1);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard3(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
      
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }
                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        
                        final1Player(&nPlayer1, nWager, bCorrect); 
                        printf("\nPlayer 1 Final Score: %d", nPlayer1);

                        gameboard3(s100, s500, s1000, s5000, s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                        printf("\n\nPlayer 2: ");
                        cCategory = getCategory_gameboard3();
                        nValue = getValue();
                        printf("\nPlayer 2 Current Score: %d", nPlayer2);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer2){
                            printf("\n Player 2 Current Score: %d", nPlayer2);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard3(cCategory, nValue);   
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);                     
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer); 
                
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }
                        else if (cCategory == 'B'){
                            bCorrect = Music_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: m100 = 0;
                                    break;
                                case 500: m500 = 0;    
                                    break;
                                case 1000: m1000 = 0;     
                                    break;
                                case 5000: m5000 = 0;     
                                    break;
                                case 10000: m10000 = 0;     
                            }
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }    
                        final1Player(&nPlayer2, nWager, bCorrect);
                        printf("\nPlayer 2 Final Score: %d", nPlayer2);

                        gameboard3(s100, s500, s1000, s5000, s10000, m100, m500, m1000, m5000, m10000, g100, g500, g1000, g5000, g10000);
                        winnerWho(&nPlayer1, &nPlayer2);
                        printf("\nThank you for playing!");
                    }

                    else if (nEndR2 == 2){
                        winnerWho(&nPlayer1, &nPlayer2);
                        printf("\nThank you for playing!");
                    }
                
                


                }

                else if (nBoard == 4){
                    Player_toAns=1; 
                    gameboard4(s100, s500, s1000, s5000, s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                
                    while (nAttempts<=7){
                        if (Player_toAns==1){
                            printf("\nPlayer 1: ");
                            cCategory = getCategory_gameboard4();
                            nValue = getValue();
                            displayQuestion_gameboard4(cCategory, nValue);
                            printf("\nType your answer: ");
                            scanf(" %c", &cAnswer);
                                
                            if (cCategory == 'A'){
                                bCorrect = Sports_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: s100 = 0;
                                        break;
                                    case 500: s500 = 0;    
                                        break;
                                    case 1000: s1000 = 0;     
                                        break;
                                    case 5000: s5000 = 0;     
                                        break;
                                    case 10000: s10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = TV_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: tv100 = 0;
                                        break;
                                    case 500: tv500 = 0;    
                                        break;
                                    case 1000: tv1000 = 0;     
                                        break;
                                    case 5000: tv5000 = 0;     
                                        break;
                                    case 10000: tv10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                            
                            if (bCorrect == 0){
                                nPlayer1 = nPlayer1 + nValue;
                                printf("\nPlayer 1 Score: %d", nPlayer1); 
                                printf("\nPlayer 2 Score: %d", nPlayer2); 
                                nAttempts = nAttempts + 1;
                                Player_toAns=2;
                            }
                            else if (bCorrect == 1){
                                printf("\nPlayer 2: ");
                                displayQuestion_gameboard4(cCategory, nValue);
                                printf("\nType your answer: ");
                                scanf(" %c", &cAnswer);
                                
                                if (cCategory == 'A'){
                                    bCorrect = Sports_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'B'){
                                    bCorrect = TV_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'C'){
                                    bCorrect = Geography_answerKey(nValue, cAnswer);                         
                                }
                            
                                if (bCorrect == 0){
                                    nPlayer2 = nPlayer2 + nValue;
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;    
                                    Player_toAns=2;
                                }
                                else if (bCorrect == 1){
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;
                                    Player_toAns=1;
                                }
                            }                       
                        
                        gameboard4(s100, s500, s1000, s5000, s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                
                        }
           
                        else if (Player_toAns==2){
                            printf("\nPlayer 2: ");
                            cCategory = getCategory_gameboard4();
                            nValue = getValue();
                            displayQuestion_gameboard4(cCategory, nValue);
                            printf("\nType your answer: ");
                            scanf(" %c", &cAnswer);

                            if (cCategory == 'A'){
                                bCorrect = Sports_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: s100 = 0;
                                        break;
                                    case 500: s500 = 0;    
                                        break;
                                    case 1000: s1000 = 0;     
                                        break;
                                    case 5000: s5000 = 0;     
                                        break;
                                    case 10000: s10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = TV_answerKey(nValue, cAnswer);
                                
                                switch (nValue){
                                    case 100: tv100 = 0;
                                        break;
                                    case 500: tv500 = 0;    
                                        break;
                                    case 1000: tv1000 = 0;     
                                        break;
                                    case 5000: tv5000 = 0;     
                                        break;
                                    case 10000: tv10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                                           
                            if (bCorrect == 0){
                                nPlayer2 = nPlayer2 + nValue;
                                printf("\nPlayer 1 Score: %d", nPlayer1); 
                                printf("\nPlayer 2 Score: %d", nPlayer2); 
                                nAttempts = nAttempts + 1;
                                Player_toAns=1;
                            }
                            else if (bCorrect == 1){
                                printf("\nPlayer 1: ");
                                displayQuestion_gameboard4(cCategory, nValue);
                                printf("\nType your answer: ");
                                scanf(" %c", &cAnswer);
                                
                                if (cCategory == 'A'){
                                    bCorrect = Sports_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'B'){
                                    bCorrect = TV_answerKey(nValue, cAnswer);
                                }

                                else if (cCategory == 'C'){
                                    bCorrect = Geography_answerKey(nValue, cAnswer);                         
                                }
                            
                                if (bCorrect == 0){
                                    nPlayer1 = nPlayer1 + nValue;
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;    
                                    Player_toAns=1;
                                }
                                else if (bCorrect == 1){
                                    printf("\nPlayer 1 Score: %d", nPlayer1); 
                                    printf("\nPlayer 2 Score: %d", nPlayer2); 
                                    nAttempts = nAttempts + 1;
                                    Player_toAns=2;
                                }
                            }
                              
                            gameboard4(s100, s500, s1000, s5000, s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                
                        }

                    }

                    printf("\nEND ROUND? (Continue[1], End[2])");
                    printf("\nYour Choice: ");
                    scanf("%d", &nEnd);

                    if (nEnd == 1){
                        printf("\nDouble Round\n");
                        gameboard4(s100, s500, s1000, s5000, s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                          
                        while (nAttemptsR2 <2){
                        printf("\nPlayer 1: ");
                        printf("\nCurrent Score: %d", nPlayer1);
                        cCategory = getCategory_gameboard4();
                        nValue = getValue();
                        displayQuestion_gameboard4(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        
                            if (cCategory == 'A'){
                                bCorrect = Sports_answerKey(nValue, cAnswer);                   
                                switch (nValue){
                                    case 100: s100 = 0;
                                        break;
                                    case 500: s500 = 0;    
                                        break;
                                    case 1000: s1000 = 0;     
                                        break;
                                    case 5000: s5000 = 0;     
                                        break;
                                    case 10000: s10000 = 0;     
                                }
                            }

                            else if (cCategory == 'B'){
                                bCorrect = TV_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: tv100 = 0;
                                        break;
                                    case 500: tv500 = 0;    
                                        break;
                                    case 1000: tv1000 = 0;     
                                        break;
                                    case 5000: tv5000 = 0;     
                                        break;
                                    case 10000: tv10000 = 0;     
                                }
                            }

                            else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                            
                            Score_Double_2P(&nPlayer1, nValue, bCorrect);
                        printf("\nPlayer 1 Score: %d", nPlayer1);
                        gameboard4(s100, s500, s1000, s5000, s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                
                        printf("\nPlayer 2: ");
                        printf("\nCurrent Score: %d", nPlayer2);
                        cCategory = getCategory_gameboard4();
                        nValue = getValue();
                        displayQuestion_gameboard4(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                    
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);                   
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }

                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }

                        else if (cCategory == 'C'){
                                bCorrect = Geography_answerKey(nValue, cAnswer);
                                switch (nValue){
                                    case 100: g100 = 0;
                                        break;
                                    case 500: g500 = 0;    
                                        break;
                                    case 1000: g1000 = 0;     
                                        break;
                                    case 5000: g5000 = 0;     
                                        break;
                                    case 10000: g10000 = 0;     
                                }
                            }
                        Score_Double_2P(&nPlayer2, nValue, bCorrect);
                        printf("\nPlayer 2 Score: %d", nPlayer2);                       
                        gameboard4(s100, s500, s1000, s5000, s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                        nAttemptsR2++;
                        }

                        printf("\nPlayer 1 Score: %d", nPlayer1); 
                        printf("\nPlayer 2 Score: %d", nPlayer2); 

                        printf("\n\nEND ROUND? (Continue[1], End[2])");
                        printf("\nYour Choice: ");
                        scanf("%d", &nEndR2);
                    }

                    else if (nEnd == 2){
                        nEndR2 = 2;
                    }

                    if (nEndR2 == 1){
                        printf("\nFinal Round\n");

                        gameboard4(s100, s500, s1000, s5000, s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                        printf("\nPlayer 1: ");
                        cCategory = getCategory_gameboard4();
                        nValue = getValue();
                        printf("\nPlayer 1 Current Score: %d", nPlayer1);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer1){
                            printf("\nPlayer 1 Current Score: %d", nPlayer1);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard4(cCategory, nValue);
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }
                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer); 
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }
                        final1Player(&nPlayer1, nWager, bCorrect);
                        printf("\nPlayer 1 Final Score: %d", nPlayer1);

                        gameboard4(s100, s500, s1000, s5000, s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                        printf("\n\nPlayer 2: ");
                        cCategory = getCategory_gameboard4();
                        nValue = getValue();
                        printf("\nPlayer 2 Current Score: %d", nPlayer2);
                        printf("\nPick any amount to wager from your current score: ");
                        scanf("%d", &nWager);
                        while (nWager > nPlayer2){
                            printf("\n Player 2 Current Score: %d", nPlayer2);
                            printf("\nPick any amount to wager from your current score: ");
                            scanf("%d", &nWager);
                        }
                        printf("\nHere is your question:");
                        displayQuestion_gameboard4(cCategory, nValue);         
                        printf("\nType your answer: ");
                        scanf(" %c", &cAnswer);               
                        if (cCategory == 'A'){
                            bCorrect = Sports_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: s100 = 0;
                                    break;
                                case 500: s500 = 0;    
                                    break;
                                case 1000: s1000 = 0;     
                                    break;
                                case 5000: s5000 = 0;     
                                    break;
                                case 10000: s10000 = 0;     
                            }
                        }
                        else if (cCategory == 'B'){
                            bCorrect = TV_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: tv100 = 0;
                                    break;
                                case 500: tv500 = 0;    
                                    break;
                                case 1000: tv1000 = 0;     
                                    break;
                                case 5000: tv5000 = 0;     
                                    break;
                                case 10000: tv10000 = 0;     
                            }
                        }
                        else if (cCategory == 'C'){
                            bCorrect = Geography_answerKey(nValue, cAnswer);
                            switch (nValue){
                                case 100: g100 = 0;
                                    break;
                                case 500: g500 = 0;    
                                    break;
                                case 1000: g1000 = 0;     
                                    break;
                                case 5000: g5000 = 0;     
                                    break;
                                case 10000: g10000 = 0;     
                            }
                        }    
                        final1Player(&nPlayer2, nWager, bCorrect); 
                        printf("\nPlayer 2 Final Score: %d", nPlayer2);

                        gameboard4(s100, s500, s1000, s5000, s10000, tv100, tv500, tv1000, tv5000, tv10000, g100, g500, g1000, g5000, g10000);
                        winnerWho(&nPlayer1, &nPlayer2);
                        printf("\nThank you for playing!");
                    }

                    else if (nEndR2 == 2){
                        winnerWho(&nPlayer1, &nPlayer2);
                        printf("\nThank you for playing!");
                    }
                }

            }//numplay 2

        }//play
        
        // 2. HOW TO PLAY
        else if (nMenu == 2){
            displayHowToPlay();
        }//how to play
    
    } //while main menu
    
    return 0;
} //int main
