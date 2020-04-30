//Matthew Julio, Esham Mahmud, Maddison Hicks-Kuskie
//due May 5
//This is a connect 4 game that will display the hisoric wins to the user

//GENERAL NOTES
//2D string "game" is the game board, folows game [x-coord] [y-coord] format										Read by: Matthew, 
//files will be open when given to functions from main													Read by: Matthew, 
//recordWin is the only funciton called in main for the win scenario.  Make a note if you want that to change.						Read by: Matthew, 
//can someone with a workign executable (Matthew cannont get his to stop winning) tell me what the error message is for not opening the files.txt? 	Read by: Matthew, 
//Matthew is aware that the functions do not give any verriables in their present state.								Read by: Matthew, 


#include<stdio.h>
#include<string.h>
#define maxName 50
#define scores.txt record
#define maxTurns 49

//previews
int getMenuChoice (void);
void displayGame (char game [] []);
_BOOL checkForWin (char game [] []);
void displayWins (FILE wins, int);
_BOOL turnTracker (int position);
void recordWin (FILE wins, char winnerName []);
void getUserInput (int turnCounter, char game [] []);
void updateArray (char game [] [], int userInput, int turnCounter);
int verticalPositions (char game [] [], char x-position);
void getPlayerNames (char player1 [], char player2 []);

int main (void)
{
//Matthew
	char player1 [maxName], player2 [maxName], game [7] [7]=' ', winner [];
	_BOOL win=0;
	int turnCounter=-1, menuChoice,;
	FILE *wins;
	menuChoice=getMenuChoice;
	do
	{
		switch(manuChoice)
		{
		case 1:
			{
				do
				{
					displayGame (game);
					getUserInput (turnCounter, game [] []);
					turnCounter++;
					win=checkForWin (game);
				}while(win==0 && turnCounter!=maxTurns)
				if (win==1)
				{
					wins=fopen("record", "a");
					recordWin (win, winner []);
				} else
				{
					if (turnCounter==maxTurns)
					{
						Prinf("INSERT LOOSING/RUN OUT OF TURNS STATEMENT HERE");
					}
				}
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

void displayGame (char game [] [])
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

void displayWins (FILE* wins, int numNames)	//Function scans scores.txt file for name and score and displays the information to the user's screen.
{
//Maddison

char names[];
int score;

	recordWin();

	//The file is opened in main. wins = fopen("scores.txt", "r");
	for(int w = 0; w < numNames; w++){
		printf("%c: %d", names[w], score);
	}
}

void turnTracker (void)
{
//Esham

}

void recordWin (FILE* wins, char winnerName[])	//This function saves the player's names and corresponding scores to the scores.txt file. It stores the top ten scores and is sorted by highest order.
{
//Maddison
	//the file is opened in the main funciton.  wins = fopen("scores.txt", "a"); //(write or append? - will it store all scores or just the scores from that round of games?)
	for(){
		fprintf(wins,);
}

}

void getUserInput (int position, char game [] [])
{
//Maddison
char playerName;
	printf("%c - Enter your move: ", playerName); 				//I will need the turn counter for update array to know which character to add.  Can you put that in with when you call the function? Matthew.
	scanf("%d", &position);
	updateArray();
	turnTracker();
}

void updateArray (char game [] [], int x, int turnCounter)
{
//Matthew
	int y;
	char xo;
	y=verticalPostion(game, x);
	if(y==-1)
	{
		return 0;
	}
	xo=turnTracker (turnCounter);
	game [x] [y]=xo;
}

int verticalPosition (char game [] [], int x-position)
{
//if a -1 is returned, the move was invalid
//Matthew
	for (int i=0; i<=7; i++)
	{
		if (game [x-position] [i]==' ')
		{
			return i;
			i=10;
		}
	}
	printf("TEXT FOR IVALID MOVE");							//find out the text for an invalid move
	return -1;
}

void getPlayerNames (void)
{
//Esham

}
