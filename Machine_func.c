/* 
Functions of final project <Machine_main.c>
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

///this function will display how to play the game
void displayHowToPlay(){
    printf("\nJeopardy Round");
    printf("\nYou will answer 4 questions each");
    printf("\nPick a category and an amount\nYou will be given a question about the selected category");
    printf("\nAnswer the question given");
    printf("\nCorrect answer will give you the amount your choose as you points");
    printf("\nWrong answer retain your score");
    printf("\n\nDouble Round");
    printf("\nYou will answer 2 questions each.");
    printf("\nCorrect answer will give you the amount you choose and will double it");
    printf("\nWrong answer will reset your score to 0");
    printf("\n\nFinal Round");
    printf("\nYou will answer 1 question each");
    printf("\nYou will pick any amount you want to wager from your current points");
    printf("\nCorrect answer will give you your current points plus the wagered amount");
    printf("\nWrong answer will deduct you current points to the wagered amount");
}

/*
these functions will display sports/ tv/ music/ geography questions
Precondition: positive number from 1-3
@param Value - a value 100/500/1000/5000/10000 which corresponds to a question each
@return Value - will return Value
*/
int Sports_question(int Value) {
    if (Value == 100){
        printf("\nWhen did Kobe Bryant died?");  
        printf("\nA.December 2019"); 
        printf("\nB.January 2020");
        printf("\nC.Febuary 2020");
        printf("\nD.March 2020"); 
    }
    else if (Value == 500){
        printf("\nWhat team has the most NBA championships?");  
        printf("\nA.Chicago Bulls"); 
        printf("\nB.Houston Rockets");
        printf("\nC.Golden State Warriors");
        printf("\nD.Boston Celtics"); 
    }
    else if (Value == 1000){
        printf("\nWhich team won the NBA Championship in 2022?");  
        printf("\nA.Boston Celtics"); 
        printf("\nB.Los Angeles Lakers");
        printf("\nC.Golden State Warriors");
        printf("\nD.Chicago Bulls"); 
     
    }
    else if (Value == 5000){
        printf("\nWhich team was LeBron James on when his team won the NBA Championship in 2016?");  
        printf("\nA.Chicago Bulls"); 
        printf("\nB.Los Angeles Lakers");
        printf("\nC.Cleveland Cavaliers");
        printf("\nD.Boston Celtics"); 
    }
    else if (Value == 10000){
        printf("\nWhat number does Klay Thompson wear for the Warriors?");  
        printf("\nA.#11"); 
        printf("\nB.#1");
        printf("\nC.#3");
        printf("\nD.#30"); 
    }
    return Value;
}

int TV_question(int Value) {
    if (Value == 100){
        printf("\nHow many movies does Star Wars have?");  
        printf("\nA.12"); 
        printf("\nB.6");
        printf("\nC.8");
        printf("\nD.4"); 
    }
    else if (Value == 500){
        printf("\nHow many movies does Hunger Games have?");  
        printf("\nA.4"); 
        printf("\nB.3");
        printf("\nC.6");
        printf("\nD.2"); 
    }
    else if (Value == 1000){
        printf("\nWho is the first actor of spider-man?");  
        printf("\nA.Tom Holland"); 
        printf("\nB.Tobey Maguire");
        printf("\nC.Andrew Garfield");
        printf("\nD.Miles Morales"); 
    }
    else if (Value == 5000){
        printf("\nHow many Harry Potter movies are there?");  
        printf("\nA.6"); 
        printf("\nB.8");
        printf("\nC.3");
        printf("\nD.4");  
    }
    else if (Value == 10000){
        printf("\nReal name of You-Know-Who?");  
        printf("\nA.Lord Voldemort"); 
        printf("\nB.Tom Marvolo");
        printf("\nC.Draco Malfoy");
        printf("\nD.Sirius Black"); 
    }
    return Value;
}

int Music_question(int Value) {
    if (Value == 100){
        printf("\nWhich classical composer was deaf?");  
        printf("\nA.Johann Sebastian Bach"); 
        printf("\nB.Ludwig van Beethoven");
        printf("\nC.Wolfgang Amadeus Mozart");
        printf("\nD.Pyotr Ilyich Tchaikovsky"); 
    }
    else if (Value == 500){
        printf("\nWho composed the famous ballet The Nutcracker?");  
        printf("\nA.Johann Sebastian Bach"); 
        printf("\nB.Ludwig van Beethoven");
        printf("\nC.Wolfgang Amadeus Mozart");
        printf("\nD.Pyotr Ilyich Tchaikovsky");  
    }
    else if (Value == 1000){
        printf("\nWho is the composer of the opera Don Giovanni and The Magic Flute?");  
        printf("\nA.Johann Sebastian Bach"); 
        printf("\nB.Ludwig van Beethoven");
        printf("\nC.Wolfgang Amadeus Mozart");
        printf("\nD.Pyotr Ilyich Tchaikovsky"); 
    }
    else if (Value == 5000){
        printf("\nWhat is the three-word title of Beethoven’s composition, part of his ninth symphony, that is used as the official anthem of the European Union?");  
        printf("\nA.Rhapsody in Blue"); 
        printf("\nB.The Swan Lake");
        printf("\nC.Ode to Joy");
        printf("\nD.Romeo and Juliet"); 
    }
    else if (Value == 10000){
        printf("\nWhich is not a composition by Tchaikovsky?");  
        printf("\nA.Ave Maria"); 
        printf("\nB.Swan Lake");
        printf("\nC.Dance of the Sugar Plum Fairy");
        printf("\nD.1812 Overture"); 
    }
    return Value;
}

int Geography_question(int Value) {
    if (Value == 100){
        printf("\nWhat is the name of the tallest mountain in the Philippines?");  
        printf("\nA.Mount Everest"); 
        printf("\nB.Mount Pinatubo");
        printf("\nC.Mount Apo");
        printf("\nD.Mayon Volcano"); 
    }
    else if (Value == 500){
        printf("\nWhat city is the Golden Gate Bridge located in?");  
        printf("\nA.Houston"); 
        printf("\nB.San Francisco");
        printf("\nC.Los Angeles");
        printf("\nD.New York"); 
    }
    else if (Value == 1000){
        printf("\nIn what ocean is the Bermuda Triangle located?");  
        printf("\nA.Atlantic Ocean "); 
        printf("\nB.Arctic Ocean");
        printf("\nC.Indian Ocean");
        printf("\nD.Pacific Ocean"); 
    }
    else if (Value == 5000){
        printf("\nHow many islands in the Philippines?");  
        printf("\nA.7,171"); 
        printf("\nB.7,211");
        printf("\nC.7,107");
        printf("\nD.7,641"); 
    }
    else if (Value == 10000){
        printf("\nWhat is the only country in the world that is also a continent?");  
        printf("\nA.Vatican City"); 
        printf("\nB.Madagascar");
        printf("\nC.Australia");
        printf("\nD.Taiwan"); 
    }
    return Value;
}

/*
these functions will determine if the answer is correct from a specific question
Precondition: positive number from 1-3
@param Value - a number from 1-3 which corresponds to one category
        Answer - a letter from A-D (from a multiple question)
@return Correct - will return a boolean value 
*/
int Sports_answerKey(int Value, char Answer){
    bool Correct=1;
    //1 is false
    if (Value == 100){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
        
    }
    
    else if (Value == 500){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }
    }

    else if (Value == 1000){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    else if (Value == 5000){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    else if (Value == 10000){
        if (Answer == 'A'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    return Correct;
}

int TV_answerKey(int Value, char Answer){
    bool Correct=1;
    //1 is false
    if (Value == 100){
        if (Answer == 'A'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
        
    }
    
    else if (Value == 500){
        if (Answer == 'A'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    else if (Value == 1000){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    else if (Value == 5000){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    else if (Value == 10000){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }    }

    return Correct;
}

int Music_answerKey(int Value, char Answer){
    bool Correct=1;
    //1 is false
    if (Value == 100){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
        
    }
    
    else if (Value == 500){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }
    }

    else if (Value == 1000){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    else if (Value == 5000){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    else if (Value == 10000){
        if (Answer == 'A'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    return Correct;
}

int Geography_answerKey(int Value, char Answer){
    bool Correct=1;
    //1 is false
    if (Value == 100){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'C'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
        
    }
    
    else if (Value == 500){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    else if (Value == 1000){
        if (Answer == 'A'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    else if (Value == 5000){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'D'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }
    }

    else if (Value == 10000){
        if (Answer == 'A'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'B'){
            printf("\nIncorrect Answer"); 
        }

        else if (Answer == 'C'){
            printf("\nCorrect Answer"); 
            Correct=0;
        }

        else if (Answer == 'D'){
            printf("\nIncorrect Answer"); 
        }
    }

    return Correct;
}

/*
this function will ask the user to pick a number from 1-5 
Precondition: positive number from 1-5
@param
@return Value - will return new values of "Value"
*/
int getValue(){ //applicable for every gameboard
    int Value;
    printf("\nValue Amount(PHP):\n1. 100\n2. 500\n3. 1000\n4. 5000\n5. 10,000");
    printf("\nSelect Amount: ");
    scanf("%d", &Value);
    switch (Value){
    case 1: Value = 100;
        break;
    case 2: Value = 500;
        break;
    case 3: Value = 1000;      
        break;
    case 4: Value = 5000;      
        break;
    case 5: Value = 10000;        
    }

    return Value;
}


/*
these functions will display the gameboard, params will become 0 if already answered
Precondition: 
@param values are from int main
@return 
*/
void gameboard1(int s1, int s2, int s3, int s4, int s5, int tv1, int tv2, int tv3, int tv4, int tv5, int m1, int m2, int m3, int m4, int m5) {
    printf("\n");
    printf("|  Sports   |    TV     |   Music   |\n");
    printf("|-----------------------------------|\n");
    printf("|    %d    |    %d    |    %d    |\n", s1, tv1, m1);
    printf("|    %d    |    %d    |    %d    |\n", s2, tv2, m2);
    printf("|    %d   |    %d   |    %d   |\n", s3, tv3, m3);
    printf("|    %d   |    %d   |    %d   |\n", s4, tv4, m4);
    printf("|    %d  |    %d  |    %d  |\n", s5, tv5, m5);
}

void gameboard2(int tv1, int tv2, int tv3, int tv4, int tv5, int m1, int m2, int m3, int m4, int m5, int g1, int g2, int g3, int g4, int g5) {
    char Category;
    printf("\n");
    printf("|    TV     |   Music   | Geography |\n");
    printf("|-----------------------------------|\n");
    printf("|    %d    |    %d    |    %d    |\n", tv1, m1, g1);
    printf("|    %d    |    %d    |    %d    |\n", tv2, m2, g2);
    printf("|    %d   |    %d   |    %d   |\n", tv3, m3, g3);
    printf("|    %d   |    %d   |    %d   |\n", tv4, m4, g4);
    printf("|    %d  |    %d  |    %d  |\n", tv5, m5, g5);
}

void gameboard3(int s1, int s2, int s3, int s4, int s5, int m1, int m2, int m3, int m4, int m5, int g1, int g2, int g3, int g4, int g5) {
    char Category;
    printf("\n");
    printf("|  Sports   |   Music   | Geography |\n");
    printf("|-----------------------------------|\n");
    printf("|    %d    |    %d    |    %d    |\n", s1, m1, g1);
    printf("|    %d    |    %d    |    %d    |\n", s2, m2, g2);
    printf("|    %d   |    %d   |    %d   |\n", s3, m3, g3);
    printf("|    %d   |    %d   |    %d   |\n", s4, m4, g4);
    printf("|    %d  |    %d  |    %d  |\n", s5, m5, g5);
}

void gameboard4(int s1, int s2, int s3, int s4, int s5, int tv1, int tv2, int tv3, int tv4, int tv5, int g1, int g2, int g3, int g4, int g5) {
    char Category;
    printf("\n");
    printf("|  Sports   |    TV     | Geography |\n");
    printf("|-----------------------------------|\n");
    printf("|    %d    |    %d    |    %d    |\n", s1, tv1, g1);
    printf("|    %d    |    %d    |    %d    |\n", s2, tv2, g2);
    printf("|    %d   |    %d   |    %d   |\n", s3, tv3, g3);
    printf("|    %d   |    %d   |    %d   |\n", s4, tv4, g4);
    printf("|    %d  |    %d  |    %d  |\n", s5, tv5, g5);
}

/*
these functions will ask the user for a category and return the input
Precondition: character from A-C
@param 
@return Category
*/
char getCategory_gameboard1(){ //for certain game board
    char Category;
    printf("\nCATEGORIES(CAPITAL LETTER ONLY):\nA Sports\nB TV\nC Music");
    printf("\nSelect Category: ");
    scanf(" %c", &Category);

    switch (Category){
    case 'A': printf("\nSports");
        break;
    case 'B': printf("\nTV");
        break;
    case 'C': printf("\nMusic");        
    }
    return Category;
}

char getCategory_gameboard2(){ //for certain game board
    char Category;
    printf("\nCATEGORIES(CAPITAL LETTER ONLY):\nA TV\nB Music\nC Geography");
    printf("\nSelect Category: ");
    scanf(" %c", &Category);

    switch (Category){
    case 'A': printf("\nTV");
        break;
    case 'B': printf("\nMusic");
        break;
    case 'C': printf("\nGeography");        
    }
    return Category;
}

char getCategory_gameboard3(){ //for certain game board
    char Category;
    printf("\nCATEGORIES(CAPITAL LETTER ONLY):\nA Sports\nB Music\nC Geography");
    printf("\nSelect Category: ");
    scanf(" %c", &Category);

    switch (Category){
    case 'A': printf("\nSports");
        break;
    case 'B': printf("\nMusic");
        break;
    case 'C': printf("\nGeography");        
    }
    return Category;
}

char getCategory_gameboard4(){ //for certain game board
    char Category;
    printf("\nCATEGORIES(CAPITAL LETTER ONLY):\nA Sports\nB TV\nC Geography");
    printf("\nSelect Category: ");
    scanf(" %c", &Category);

    switch (Category){
    case 'A': printf("\nSports");
        break;
    case 'B': printf("\nTV");
        break;
    case 'C': printf("\nGeography");        
    }
    return Category;
}



/*
these functions will display the questions
Precondition: character from A-C
@param Category - a character from A-C
        Value - a value 100/500/1000/5000/10000 which corresponds to a question each
@return 
*/
void displayQuestion_gameboard1(char Category, int Value) {
    if (Category == 'A') {
        Sports_question(Value);
    }

    else if (Category == 'B') {
        TV_question(Value);
    }

    else if (Category == 'C') {
        Music_question(Value);      
    }
}

void displayQuestion_gameboard2(char Category, int Value) {
    if (Category == 'A') {
        TV_question(Value);
    }

    else if (Category == 'B') {
        Music_question(Value);
    }

    else if (Category == 'C') {
        Geography_question(Value);      
    }
}

void displayQuestion_gameboard3(char Category, int Value) {
    if (Category == 'A') {
        Sports_question(Value);
    }

    else if (Category == 'B') {
        Music_question(Value);
    }

    else if (Category == 'C') {
        Geography_question(Value);      
    }
}

void displayQuestion_gameboard4(char Category, int Value) {
    if (Category == 'A') {
        Sports_question(Value);
    }

    else if (Category == 'B') {
        TV_question(Value);
    }

    else if (Category == 'C') {
        Geography_question(Value);      
    }
}

/*
these functions will compute for the score of the player
Precondition: 
@param *Player1 - an integer: the player's current score
        Value - a value 100/500/1000/5000/10000
        correct - a boolean value to determine whether the player answer correctly or not
@return 
*/
//1 PLAYER FOR JEOPARDY ROUND
void player1Score(int *Player1, int Value, bool correct){
    if (correct == 0){
        *Player1 = *Player1 + Value;
        printf("\nCurrent Score: %d", *Player1); 
    }
    else if (correct == 1){
        printf("\nCurrent Score: %d", *Player1); 
    }

}

//FOR 1 PLAYER: DOUBLE ROUND
void player1Score_Double(int *Player1, int Value, bool correct){
    if (correct == 0){
        *Player1 = (*Player1 + Value)*2;
        printf("\nCurrent Score: %d", *Player1); 
    }
    else if (correct == 1){
        *Player1 = 0;
        printf("\nCurrent Score: %d", *Player1); 
    }
}



/*
this function will compute for the score of the player for final round (for 1 or 2 players)
Precondition: 
@param *Player1 - an integer: the player's current score
        Wager - a value between 0 to *Player1
        correct - a boolean value to determine whether the player answer correctly or not
@return 
*/
void final1Player(int *Player1, int Wager, bool correct){
    if (correct == 0){
        *Player1 = *Player1 + Wager;
    }
    else if (correct == 1){
        *Player1 = *Player1 - Wager;
    }

}


/*
FOR 2 PLAYERS: DOUBLE ROUND
this function will compute for the score of the player
Precondition: 
@param *Player1 - an integer: the player's current score
        Value - a value 100/500/1000/5000/10000
        correct - a boolean value to determine whether the player answer correctly or not
@return new score of the player
*/
void Score_Double_2P(int *Player, int Value, bool correct){
    if (correct == 0){
        *Player = (*Player + Value)*2;
    }
    else if (correct == 1){
        *Player = 0;
    }
}

/*
this function will determine who the winner is
Precondition: 
@param *Player1 - an integer: player 1 current score
        *Player2 - an integer: player 2 current score
@return the winner
*/
void winnerWho(int *Player1, int *Player2){
    if (*Player1 > *Player2)
        printf("\nPlayer 1 wins!");   

    else if (*Player2 > *Player1)
        printf("\nPlayer 2 wins!");    

    else if (*Player1 == *Player2){
        printf("\nIt's a tie!"); 
    }
    printf("\nFINAL SCORES"); 
    printf("\nPlayer 1 Score: %d", *Player1); 
    printf("\nPlayer 2 Score: %d", *Player2); 


}




/*
//FOR 2 PLAYERS: PLAYER 1 WILL ANSWER IN JEOPARDY ROUND
void playersScore_JeopardyR(int *Player1, int *Player2, int Value, char Category, char Answer, bool correct, int *playerToAns, int *attempts){
    if (correct == 0){
        *Player1 = *Player1 + Value;
        printf("\nPlayer 1 Score: %d", *Player1); 
        printf("\nPlayer 2 Score: %d", *Player2); 
        *attempts = *attempts + 1;
        *playerToAns=2;
    }
    else if (correct == 1){
        printf("\nPlayer 2: ");
        printf("\nType your answer: ");
        scanf(" %c", &Answer);

        if (correct == 0){
            *Player2 = *Player2 + Value;
            printf("\nPlayer 1 Score: %d", *Player1); 
            printf("\nPlayer 2 Score: %d", *Player2); 
            *attempts = *attempts + 1;    
            *playerToAns=2;
        }
        else if (correct == 1){
            printf("\nPlayer 1 Score: %d", *Player1); 
            printf("\nPlayer 2 Score: %d", *Player2); 
            *attempts = *attempts + 1;
            *playerToAns=1;
        }
    }
}


//FOR 2 PLAYERS: PLAYER 2 WILL ANSWER IN JEOPARDY ROUND
void playersScore_JeopardyR2(int *Player1, int *Player2, int Value, char Category, char Answer, bool correct, int *playerToAns, int *attempts){
    if (correct == 0){
        *Player2 = *Player2 + Value;
        printf("\nPlayer 1 Score: %d", *Player1); 
        printf("\nPlayer 2 Score: %d", *Player2); 
        *attempts = *attempts + 1;
        *playerToAns=1;
    }
    else if (correct == 1){
        printf("\nPlayer 1: ");
        printf("\nType your answer: ");
        scanf(" %c", &Answer);
        correct = Sports_answerKey(Value, Answer);

        if (correct == 0){
            *Player1 = *Player1 + Value;
            printf("\nPlayer 1 Score: %d", *Player1); 
            printf("\nPlayer 2 Score: %d", *Player2); 
            *attempts = *attempts + 1;    
            *playerToAns=1;
        }
        else if (correct == 1){
            printf("\nPlayer 1 Score: %d", *Player1); 
            printf("\nPlayer 2 Score: %d", *Player2); 
            *attempts = *attempts + 1;
            *playerToAns=2;
        }
    }
}
*/
