#include "yahtzee_lib.h"

void initializePlayer()
{
	// Gets random number
	srand(time(NULL));
	// Stores into a variable random_number
	//int random_number = rand();
}
char getChoice()
{
	char choice;
	scanf("  %c", &choice);
	// Scan initial input
	while(choice != 'y' && choice != 'n')
	{

		// Print request (because of error)
		printf("\nInvalid option. Please type 'y' to play or 'n' to exit: ");
		// scan input
		//printf("\nDo you want to roll the dice (y/n): ");
		scanf(" %c", &choice);
	}

	// Returns choice after 'y' or 'n' is input
	return choice;
}
int rollDice()
{
	// initialize count
	int dice_number;
	// Rolls dice by using rand()
	dice_number = rand() % NUM_DICE + 1;
	// output number	
	return dice_number;
}

void countNumber(const int dice[], int counts[])
{
	//int counts[6] = {0,0,0,0,0,0};
	// Count how many dice contain each number 1-6
	// for loop to go through each possibility
	for(int i = 1; i <= 6; i++)
	{
		for(int j = 0; j <= 5; j++)
		{
			// check if true
			if(dice[j] == i)
			{
				// add one to the count
				counts[i]++;
			}
		}
	}
}

bool isYahtzee(const int dice[])
{
	// check if all dice are equal
	if(dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == 
		dice[3] && dice[3] == dice[4])
	{
		//return true
		return true;
	}
	// if not Yahtzee
	else
	{
		// return false
		return false;
	}
}

bool isFourOfAKind(const int counts[])
{
	// check if any count is 4
	if(counts[0] == 4 || counts[1] == 4 || counts[2] == 4 || 
		counts[3] == 4 || counts[4] == 4 || counts[5] == 4)
	{
		// return true
		return true;
	}
	// if no 4
	else
	{
		// return false
		return false;
	}
}

bool hasTwoEqual(const int counts[])
{
	// check if any twos
	if(counts[0] == 2 || counts[1] == 2 || counts[2] == 2 || 
		counts[3] == 2 || counts[4] == 2 || counts[5] == 2)
	{
		// return true
		return true;
	}
	// if no twos
	else
	{
		//return false
		return false;
	}
}
bool hasThreeEqual(const int counts[])
{
	// check if any threes
	if(counts[0] == 3 || counts[1] == 3 || counts[2] == 3 || 
		counts[3] == 3 || counts[4] == 3 || counts[5] == 3)
	{
		// return true
		return true;
	}
	// if no threes
	else
	{
		// return false
		return false;

	}
}

bool isThreeOfAKind(const int counts[])
{
	int three = hasThreeEqual(counts);
	int two = hasTwoEqual(counts);
	//if three true
	if(three > two)
	{
		return true;
	}
	
	// if not
	return false;
	
}

bool isFullHouse(const int counts[])
{
	int three = hasThreeEqual(counts);
	int two = hasTwoEqual(counts);
	// check if two and three true
	if(three && two)
	{
		// return true
		return true;
	}
	// if not
	else
	{
		// return false
		return false;
	}
}

bool isLargeStraight(const int counts[])
{
	// first combintaion
	if(counts[0] == 1 && counts[1] == 1 && counts[2] == 1 
		&& counts[3] == 1 && counts[4] == 1 && counts[5] == 0)
	{
		//return true
		return true;
	}
	// second combination
	if(counts[0] == 0 && counts[1] == 1 && counts[2] == 1 
		&& counts[3] == 1 && counts[4] == 1 && counts[5] == 1)
	{
		// return true
		return true;
	}
	// if not
	else
	{
		// return false
		return false;
	}
}
bool isSmallStraight(const int counts[])
{
	if(counts[0] >= 1 && counts[1] >= 1 && counts[2] >=1 && counts[3] >= 1 && 
	counts[4] == 0 && counts[5] == 0)
	{
		// Return true
		return true;
	}
	// Check if second combination
	if(counts[0] == 0 && counts[1] >= 1 && counts[2] >= 1 && counts[3] >=1 && 
		counts[4] >= 1 && counts[5] == 0)
	{
		// return true
		return true;
	}
	// Check if third combination
	if(counts[0] == 0 && counts[1] == 0 && counts[2] >= 1 && counts[3] >= 1 && 
		counts[4] >= 1 && counts[5] >= 1)
	{
		// return true
		return true;
	}
	// else
	return false;
}

int decidePlay(const int dice[])
{
	// initialize the counts array
	int counts[6] = {0,0,0,0,0,0};
	countNumber(dice, counts);

	// check if yahtzee is true
	if(isYahtzee(dice))
	{
		// return constant
		return YAHTZEE;
	}

	// check if four of a kind is true
	if(isYahtzee(dice))
	{
		// return constant
		return FOUR_OF_A_KIND;
	}

	// check if three of a kind is true
	if(isThreeOfAKind(counts))
	{
		return THREE_OF_A_KIND;
	}
	// check if full house
	if(isFullHouse(counts))
	{	
		// return constant
		return FULL_HOUSE;
	}
	// check if large straight
	if(isLargeStraight(counts))
	{
		// return constant
		return L_STRAIGHT;
	}
	// check if small straight
	if(isSmallStraight(counts))
	{
		// return constant
		return S_STRAIGHT;
	}
	// if nothing
	else
	{
		// return constant
		return NO_PLAY;
	}
}
