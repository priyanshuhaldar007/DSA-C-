#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define SPADE 06
#define CLUB 05
#define DIAMOND 04
#define HEART 03
#define RESULTS "Blackjack.txt"

// Global Variables declared below
int k;
int l;
int d;
int won;
int loss;
int cash = 500;
int bet;
int random_card;
int playerTotal = 0;
int dealer_total;
int clubCard();
int diamondCard();
int heartCard();
int spadeCard();
int randCard();
int betting();
void askTitle();
void rules();
void play();
void dealer();
void stay();
void cashTest();
void askOver();
void fileResults();

// Main Function
int main(void){
    int choice1;
    askTitle();
    printf("\n");
    printf("\n");
    system("pause");
    return (0);
}

// Function for asking player if they want to continue
void askTitle(){
    char choice1;
    int choice2;
    printf("\n Are You Ready?");
    printf("\n (Y/N)\n ");
    scanf("\n%c", &choice1);
    while ((choice1 != 'Y') && (choice1 != 'y') && (choice1 != 'N') && (choice1 != 'n')){
        printf("\n");
        printf("Incorrect Choice. Please Enter Y for Yes or N for No.\n");
        scanf("%c", &choice1);
    }
    // If yes, continue. Prints menu.
    if ((choice1 == 'Y') || (choice1 == 'y')){
        system("cls");
        printf("\nEnter 1 to Begin the game.");

        printf("\nEnter 2 to Exit Game. ");
        printf("\nChoice: ");
        scanf("%d", &choice2);              // Prompts user for choice
        // If invalid choice entered
        if ((choice2 < 1) || (choice2 > 3)){
            printf("\nIncorrect Choice. Please enter 1, 2 or 3\n");
            scanf("%d", &choice2);
        }
        switch (choice2){
        case 1: // Case to begin game
            system("cls");
            play();
            break;

        case 2: // Case to exit game
            system("pause");
            exit(0);
            break;

        default:
            printf("\nInvalid Input");
        }
    }
    // If no, exit program
    else if ((choice1 == 'N') || (choice1 == 'n')){
        system("pause");
        exit(0);
    }
    return;
}

// Displays Club Card Image
int clubCard(){
    srand((unsigned)time(NULL));
    k = rand() % 13 + 1;
    // If the value of random number is 9 or less, print card with that number
    if (k <= 9){
        // Club Card
        printf("-------\n");
        printf("|%c |\n", CLUB);
        printf("| %d |\n", k);
        printf("| %c|\n", CLUB);
        printf("-------\n");
    }
    // If the value of random number is 10, print card with J (Jack) on face
    if (k == 10){
        // Club Card
        printf("-------\n");
        printf("|%c |\n", CLUB);
        printf("| J |\n");
        printf("| %c|\n", CLUB);
        printf("-------\n");
    }
    // If the value of random number is 11, print card with A (Ace) on face
    if (k == 11){
        // Club Card
        printf("-------\n");
        printf("|%c |\n", CLUB);
        printf("| A |\n");
        printf("| %c|\n", CLUB);
        printf("-------\n");

        // If the value of random number is Ace, change value to 11 or 1 depending on dealer total
        if (playerTotal <= 10){
            k = 11;
        }
        else{
            k = 1;
        }
    }
    // If the value of random number is 12, print card with Q (Queen) on face
    if (k == 12){
        // Club Card
        printf("-------\n");
        printf("|%c |\n", CLUB);
        printf("| Q |\n");
        printf("| %c|\n", CLUB);
        printf("-------\n");
        k = 10; // Set card value to 10
    }
    // If the value of random number is 13, print card with K (King) on face
    if (k == 13){
        // Club Card
        printf("-------\n");
        printf("|%c |\n", CLUB);
        printf("| K |\n");
        printf("| %c|\n", CLUB);
        printf("-------\n");
        k = 10; // Set card value to 10
    }
    return k;
}
// Displays Diamond Card Image
int diamondCard(){
    // Generates random seed for rand() function
    srand((unsigned)time(NULL)); 
    k = rand() % 13 + 1;
    // If the value of random number is 9 or less, print card with that number
    if (k <= 9){
        // Diamond Card
        printf("-------\n");
        printf("|%c |\n", DIAMOND);
        printf("| %d |\n", k);
        printf("| %c|\n", DIAMOND);
        printf("-------\n");
    }
    // If the value of random number is 10, print card with J (Jack) on face
    if (k == 10){
        // Diamond Card
        printf("-------\n");
        printf("|%c |\n", DIAMOND);
        printf("| J |\n");
        printf("| %c|\n", DIAMOND);
        printf("-------\n");
    }
    // If the value of random number is 11, print card with A (Ace) on face
    if (k == 11{
        // Diamond Card
        printf("-------\n");
        printf("|%c |\n", DIAMOND);
        printf("| A |\n");
        printf("| %c|\n", DIAMOND);
        printf("-------\n");

        // If the value of random number is Ace, change value to 11 or 1 depending on dealer total
        if (playerTotal <= 10){
            k = 11;
        }
        else{
            k = 1;
        }
    }
    // If the value of random number is 12, print card with Q (Queen) on face
    if (k == 12){
        // Diamond Card
        printf("-------\n");
        printf("|%c |\n", DIAMOND);
        printf("| Q |\n");
        printf("| %c|\n", DIAMOND);
        printf("-------\n");
        k = 10; // Set card value to 10
    }
    // If the value of random number is 13, print card with K (King) on face
    if (k == 13){
        // Diamond Card
        printf("-------\n");
        printf("|%c |\n", DIAMOND);
        printf("| K |\n");
        printf("| %c|\n", DIAMOND);
        printf("-------\n");
        k = 10; // Set card value to 10
    }
    return k;
} 
// Displays Heart Card Image
int heartCard(){
    srand((unsigned)time(NULL));
    k = rand() % 13 + 1;
    if (k <= 9){
        // Heart Card
        printf("-------\n");
        printf("|%c |\n", HEART);
        printf("| %d |\n", k);
        printf("| %c|\n", HEART);
        printf("-------\n");
    }
    // If the value of random number is 10, print card with J (Jack) on face
    if (k == 10){
        // Heart Card
        printf("-------\n");
        printf("|%c |\n", HEART);
        printf("| J |\n");
        printf("| %c|\n", HEART);
        printf("-------\n");
    }
    // If the value of random number is 11, print card with A (Ace) on face
    if (k == 11){
        // Heart Card
        printf("-------\n");
        printf("|%c |\n", HEART);
        printf("| A |\n");
        printf("| %c|\n", HEART);
        printf("-------\n");
        // If the value of random number is Ace, change value to 11 or 1 depending on dealer total
        if (playerTotal <= 10){
            k = 11;
        }
        else{
            k = 1;
        }
    }
    // If the value of random number is 12, print card with Q (Queen) on face
    if (k == 12){
        // Heart Card
        printf("-------\n");
        printf("|%c |\n", HEART);
        printf("| Q |\n");
        printf("| %c|\n", HEART);
        printf("-------\n");
        k = 10; // Set card value to 10
    }
    // If the value of random number is 13, print card with K (King) on face
    if (k == 13){
        // Heart Card
        printf("-------\n");
        printf("|%c |\n", HEART);
        printf("| K |\n");
        printf("| %c|\n", HEART);
        printf("-------\n");
        k = 10; // Set card value to 10
    }
    return k;
}
// Displaying Spade Card Image
int spadeCard(){
    // Generates random seed for rand() function
    srand((unsigned)time(NULL));
    k = rand() % 13 + 1;
    // If the value of random number is 9 or less, print card with that number
    if (k <= 9){
        // Spade Card
        printf("-------\n");
        printf("|%c |\n", SPADE);
        printf("| %d |\n", k);
        printf("| %c|\n", SPADE);
        printf("-------\n");
    }
    // If the value of random number is 10, print card with J (Jack) on face
    if (k == 10){
        // Spade Card
        printf("-------\n");
        printf("|%c |\n", SPADE);
        printf("| J |\n");
        printf("| %c|\n", SPADE);
        printf("-------\n");
    }
    // If the value of random number is 11, print card with A (Ace) on face
    if (k == 11){
        // Spade Card
        printf("-------\n");
        printf("|%c |\n", SPADE);
        printf("| A |\n");
        printf("| %c|\n", SPADE);
        printf("-------\n");
        // If the value of random number is Ace, change value to 11 or 1 depending on dealer total
        if (playerTotal <= 10){
            k = 11;
        }
        else{
            k = 1;
        }
    }
    if (k == 12){
        // Spade Card
        printf("-------\n");
        printf("|%c |\n", SPADE);
        printf("| Q |\n");
        printf("| %c|\n", SPADE);
        printf("-------\n");
        k = 10; // Set card value to 10
    }
    // If the value of random number is 13, print card with K (King) on face
    if (k == 13){
        // Spade Card
        printf("-------\n");
        printf("|%c |\n", SPADE);
        printf("| K |\n");
        printf("| %c|\n", SPADE);
        printf("-------\n");
        k = 10; // Set card value to 10
    }
    return k;
}
// Generates random card
int randCard(){
    // Generates random seed for rand() function
    srand((unsigned)time(NULL)); 
    random_card = rand() % 4 + 1;

    if (random_card == 1){
        clubCard();
        l = k;
    }

    if (random_card == 2){
        diamondCard();
        l = k;
    }

    if (random_card == 3){
        heartCard();
        l = k;
    }

    if (random_card == 4){
        spadeCard();
        l = k;
    }
    return l;
}
// Plays game
void play(){
    // holds value of playerTotal
    int p = 0; 
    // counter for asking user to hold or stay (aka game turns)
    int i = 1; 
    char choice3;

    cash = cash;
    cashTest();
    // Prints amount of cash user has
    printf("\nCash: $%d\n", cash); 
    // Generates random card
    randCard();                   
    // Computes player total 
    playerTotal = p + l;          
    p = playerTotal;
    // Prints player total
    printf("\nYour Total is %d\n", p);
    // Computes and prints dealer total 
    dealer();                       
    // Prompts user to enter bet amount   
    betting();                         

    // While loop used to keep asking user to hit or stay at most twenty-one times
    // because there is a chance user can generate twenty-one consecutive 1's
    while (i <= 21){
        // If user total is 21, win
        if (p == 21){
            printf("\nUnbelievable! You Win!\n");
            won = won + 1;
            cash = cash + bet;
            printf("\nYou have %d Wins and %d Losses. Awesome!\n", won, loss);
            dealer_total = 0;
            askOver();
        }
        // If player total is over 21, loss
        if (p > 21){
            printf("\nWoah Buddy, You Went WAY over.\n");
            loss = loss + 1;
            cash = cash - bet;
            printf("\nYou have %d Wins and %d Losses. Awesome!\n", won, loss);
            dealer_total = 0;
            askOver();
        }
        // If player total is less than 21, ask to hit or stay
        if (p <= 21){
            printf("\n\nWould You Like to Hit or Stay?");

            scanf("%c", &choice3);
            // If invalid choice entered
            while ((choice3 != 'H') && (choice3 != 'h') && (choice3 != 'S') && (choice3 != 's')){
                printf("\n");
                printf("Please Enter H to Hit or S to Stay.\n");
                scanf("%c", &choice3);
            }
            // If Hit, continues
            if ((choice3 == 'H') || (choice3 == 'h')){
                randCard();
                playerTotal = p + l;
                p = playerTotal;
                printf("\nYour Total is %d\n", p);
                dealer();
                // Is dealer total is 21, loss
                if (dealer_total == 21){
                    printf("\nDealer Has the Better Hand. You Lose.\n");
                    loss = loss + 1;
                    cash = cash - bet;
                    printf("\nYou have %d Wins and %d Losses. Awesome!\n", won, loss);
                    dealer_total = 0;
                    askOver();
                }
                // If dealer total is over 21, win
                if (dealer_total > 21){
                    printf("\nDealer Has Went Over!. You Win!\n");
                    won = won + 1;
                    cash = cash + bet;
                    printf("\nYou have %d Wins and %d Losses. Awesome!\n", won, loss);
                    dealer_total = 0;
                    askOver();
                }
            }
            // If Stay, does not continue
            if ((choice3 == 'S') || (choice3 == 's')){
                printf("\nYou Have Chosen to Stay at %d.!\n", playerTotal);
                stay();
            }
        }
        // While player total and dealer total are less than 21, re-do while loop
        i++; 
    }
}
// Function to play for dealer AI
void dealer(){
    int z;

    if (dealer_total < 17){
        srand((unsigned)time(NULL) + 1);
        z = rand() % 13 + 1;
        if (z <= 10){
            d = z;
        }

        if (z > 11){
            d = 10;
        }
        // If the value of random number is 11(Ace), change value to 11 or 1 depending on dealer total
        if (z == 11){
            if (dealer_total <= 10){
                d = 11;
            }
            else{
                d = 1;
            }
        }
        dealer_total = dealer_total + d;
    }
    // Prints dealer total
    printf("\nThe Dealer Has a Total of %d", dealer_total); 
}

void stay(){
    dealer();
    if (dealer_total >= 17){
        if (playerTotal >= dealer_total){
            printf("\nUnbelievable! You Win!\n");
            won = won + 1;
            cash = cash + bet;
            printf("\nYou have %d Wins and %d Losses. Awesome!\n", won, loss);
            dealer_total = 0;
            askOver();
        }
        // If player's total is less than dealer's total, loss
        if (playerTotal < dealer_total){
            printf("\nDealer Has the Better Hand. You Lose.\n");
            loss = loss + 1;
            cash = cash - bet;
            printf("\nYou have %d Wins and %d Losses. Awesome!\n", won, loss);
            dealer_total = 0;
            askOver();
        }
        // If dealer's total is more than 21, win
        if (dealer_total > 21){
            printf("\nUnbelievable! You Win!\n");
            won = won + 1;
            cash = cash + bet;
            printf("\nYou have %d Wins and %d Losses. Awesome!\n", won, loss);
            dealer_total = 0;
            askOver();
        }
    }
    else{
        stay();
    }

}

void cashTest(){
    if (cash <= 0){
        printf("You Are Bankrupt. Game Over");
        cash = 500;
        askOver();
    }
}
// Asks user amount to bet
int betting(){
    printf("\n\nEnter Bet: $");
    scanf("%d", &bet);
    // If player tries to bet more money than player has
    if (bet > cash){
        printf("\nYou cannot bet more money than you have.");
        printf("\nEnter Bet: ");
        scanf("%d", &bet);
        return bet;
    }
    else{
        return bet;
    }
}

void askOver(){
    char choice1;

    printf("\nWould You Like To Play Again?");
    printf("\nPlease Enter Y for Yes or N for No\n");
    scanf("\n%c", &choice1);
    // If invalid choice entered
    while ((choice1 != 'Y') && (choice1 != 'y') && (choice1 != 'N') && (choice1 != 'n')){
        printf("\n");
        printf("Incorrect Choice. Please Enter Y for Yes or N for No.\n");
        scanf("%c", &choice1);
    }
    // If yes, continue.
    if ((choice1 == 'Y') || (choice1 == 'y')){
        system("cls");
        play();
    }
    // If no, exit program
    else if ((choice1 == 'N') || (choice1 == 'n')){
        fileResults();
        printf("\nBYE!!!!\n\n");
        system("pause");
        exit(0);
    }
    return;
}

void fileResults(){
    FILE *fpresults;
    fpresults = fopen(RESULTS, "w");
    if (fpresults == NULL){
        printf("\nError: File Missing\n");
        system("pause");
        exit(1);
    }
    else{
        fprintf(fpresults, "\n\t RESULTS");
        fprintf(fpresults, "\n\t---------\n");
        fprintf(fpresults, "\nYou Have Won %d Times\n", won);
        fprintf(fpresults, "\nYou Have Lost %d Times\n", loss);
        fprintf(fpresults, "\nKeep Playing !");
    }
    fclose(fpresults);
    return;
}
