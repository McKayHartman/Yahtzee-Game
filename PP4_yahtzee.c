// header files
#include "yahtzee_lib.h"

// main program
int main()
{
    // initialize program
        // initialize the random number generator
            // function: initializePlayer
    initializePlayer();
        // declare variable to hold the dice
    //int dice[NUM_DICE];

        // declare the variable to store the user's choice
    char choice;
        // inialize the variable that stores the play
    //int play = NO_PLAY;

        // print a title
    printf("\nWelcome to Simple Yahtzee!\n");
    printf("==========================\n\n");

    // begin game
        // prompt the user for the play
            // function: printf
    printf("Do you want to roll the dice (y/n): ");
        // wait for user input
            // function: getChoice
    choice = getChoice();

        // TODO 1: create a loop that runs while the user wants to continue
    while(choice == 'y')
    {
        
            // TODO 2: roll the dice to fill the array of dice
        printf("Your roll: ");
        int dice[5] = {1,1,1,1,1};
        for(int i = 0; i <= 4; i++)
        {
            dice[i] = rollDice();

            // TODO 3: print the dice
            printf("%d ", dice[i]);
        }
            // TODO 4: call the function decidePlay and store the result in
            //         the play variable
        int play = decidePlay(dice);
      
            // TODO 5: evaluate the play variable and print the appropriate 
            //         message
            // if play is 0
        if(play == 0)
        {
            // print message
            printf("\nYou rolled no particular play.");
        }
        // if play is 1
        if(play == 1)
        {
            // print message
            printf("\nYou rolled a Yahtzee!");
        }
        // if play is 2
        if(play == 2)
        {
            // print message
            printf("\nYou rolled a Large Streight!");
        }
        // if play is 3
        if(play == 3)
        {
            // print message
            printf("\nYou rolled a Small Streight!");
        }
        // if play is 4
        if(play == 4)
        {
            // print message
            printf("\nYou rolled a Full House!");
        }
        // if play is 5
        if(play == 5)
        {
            // print message
            printf("\nYou rolled Four of a Kind!");
        }
        // if play is 6
        if(play == 6)
        {
            // print message
            printf("\nYou rolled Three of a Kind!");
        }
       // prompt the user for continuing
        // function: printf
        printf("\n\nPlay again? (y/n): ");


    // Read the choice
        // function: getChoice
        choice = getChoice();
        // printf("%c", choice);
    }

        
    
    // END OF TODO 1: loop

    // End program
        // print a message
            // function: printf
    printf("\nThanks for playing Yahtzee!\n");
        // return success
    return 0;
}
