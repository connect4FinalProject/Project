//Matthew Julio, Esham Mahmud, Maddison Hicks-Kuskie
//due May 5
//This is a connect 4 game that will display the hisoric wins to the user

//GENERAL NOTES
//2D string "game" is teh game board, folows game [x-coord] [y-coord] format
//files will be open when given to functions from main

#include<stdio.h>
#define maxName 50
#define scores.txt record

int main (void)
{
//Matthew
	char player1 [maxName], player2 [maxName];
	_BOOL win=0;
	int turnCounter=-1, menuChoice,;
	FILE *wins;
	menuChoice=getMenuChoice;
	do
	{
		turnCounter++;
		switch(manuChoice)
		{
		case 1:
			{
				
			}
		case 2:
			{
				wins=fopen("record" "r");
				displyWins(wins);
				fclose("wins");
			}
		case 0:
			{
				return 0;
			}
		default:
			{
				prinf("Please enter a valid option!\n");
			}
		}
	} while (menuChoice!=0)
	return 0;
}

void getMenuChoice (void)
{
//Esham
	printf("");
}

void displayGame (void)
{
//Matthew
	printf("[1][2][3][4][5][6][7]\n");
	printf("---------------------\n");
	for(int index=0; index!=7; index++)
	{
		for(int i=0; i!=7; I ++)
		{
			printf("[%s]", game [index] [i]);
		}
		printf("\n");
	}
	printf("---------------------\n");
	printf("[1][2][3][4][5][6][7]\n");
}

void checkForWin (void)
{
//Esham

}

void displayWins (void)
{
//Maddison

}

void turnTracker (void)
{
//Esham

}

void recordWin (void)
{
//Maddison

}

void getUserInput (void)
{
//Maddison
	scanf("", );
}

void updateArray (void)
{
//Matthew

}

void verticalPosition (void)
{
//Matthew

}

void getPlayerNames (void)
{
//Esham

}
