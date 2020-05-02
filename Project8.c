//Matthew Julio, Esham Mahmud, Maddison Hicks-Kuskie
//due May 5
//This is a connect 4 game that will display the hisoric wins to the user

//GENERAL NOTES
//2D string "game" is the game board, folows game [x-coord] [y-coord] format										Read by: Matthew, Esham
//files will be open when given to functions from main													Read by: Matthew, Esham
//recordWin is the only funciton called in main for the win scenario.  Make a note if you want that to change.						Read by: Matthew, Esham
//can someone with a workign executable (Matthew cannont get his to stop winning) tell me what the error message is for not opening the files.txt? 	Read by: Matthew, Esham
	//There is no error message as far as I can tell, it only shows a blank line then shows the menu again.
//Matthew is aware that the functions do not give any verriables in their present state.								Read by: Matthew, Esham


#include<stdio.h>
#include<string.h>
#define maxName 50
#define record "scores.txt"
#define maxTurns 49
#define size 7

//previews
int getMenuChoice (void);
void displayGame (char game[][]);
_Bool checkForWinH (char game[][]);
_Bool checkForWinV (char game[][]);
_Bool checkForWinD (char game[][]);
void displayWins (FILE wins, int);
_Bool turnTracker (int position);
void recordWin (FILE wins, char winnerName[]);
void getUserInput (int position, char game[][], int turnCounter);
void updateArray (char game[][], int userInput, int turnCounter);
int verticalPositions (char game[][], char x-position);
void getPlayerNames (char player1[], char player2[]);
void getstr(int max, char str[]);

int main (void)
{
//Matthew
	char player1[maxName], player2[maxName], game[size][size], winner[maxName];
	_Bool win=0;
	int turnCounter=-1, menuChoice;
	FILE *wins;
	menuChoice=getMenuChoice;
	do
	{
		switch(menuChoice)
		{
		case 1:
			{
				do
				{
					displayGame (game);
					getUserInput (turnCounter, game[][], turnCounter);
					turnCounter++;
					win=checkForWin (game);
				}while(win==0 && turnCounter!=maxTurns);
				if (win==1)
				{
					wins=fopen("record", "a");
					recordWin (wins, winner[]);
				}else
				{
					if (turnCounter==maxTurns)
					{
						printf("INSERT LOOSING/RUN OUT OF TURNS STATEMENT HERE");		//Can soemone find out what is printed if all turns are used up(all squares are full); Esham: It says "It's a tie! Try again...",
																						//Then in the next line it says "Play again? 1 - yes: "
					}
				}
			}
		case 2:
			{
				wins=fopen("record" "r");
				displayWins(wins);
				fclose("wins");
			}
		case 0:
			{
				return 0;
			}
		default:
			{
				printf("Please enter a valid option!\n");
			}
		}
	} while (menuChoice!=0);
	return 0;
}
int getMenuChoice (void)
{
//Esham
	int menuInput;

	printf("***CONNECT 4***\n");
	printf("1. Play Game\n");
	printf("2. Show Scores\n");
	printf("0. EXIT\n");
	scanf("%d",&menuInput);

	return menuInput;
}

void displayGame (char game[][])
{
//Matthew
	printf("[1][2][3][4][5][6][7]\n");
	printf("---------------------\n");
	for(int index=0; index!=7; index++)
	{
		for(int i=0; i!=7; i++)
		{
			printf("[%s]", game [index] [i]);
		}
		printf("\n");
	}
	printf("---------------------\n");
	printf("[1][2][3][4][5][6][7]\n");
}

_Bool checkForWinH (void)
{
//Eshamw

}

_Bool checkForWinV (void)
{
//Esham

}

_Bool checkForWinD (void)
{
//Esham

}

void displayWins (FILE* wins, int numNames)	//Function scans scores.txt file for name and score and displays the information to the user's screen.
						//Does it sort the displayed results?
{
//Maddison

char names[];
int score;

	recordWin(wins, names[]);

	for(int w = 0; w < numNames; w++){
		printf("%c: %d", names[w], score);
	}
}

_Bool turnTracker (void)
{
//Esham

}

void recordWin (FILE* wins, char winnerName[])	//This function saves the player's names and corresponding scores to the scores.txt file. It stores the top ten scores and is sorted by highest order.
{
//Maddison
int score, i, j;

	for(int n = 0; n < ; n++){
		fprintf(wins, "%c %d", winnerName[], score);
}
	//Bubble sort:
	

}

void getUserInput (int position, char game[][], int turnCounter)
{
//Maddison
char playerName;
	printf("%c - Enter your move: ", playerName); 				//I will need the turn counter for update array to know which character to add.  Can you put that in with when you call the function? Matthew.
	scanf("%d", &position);
	updateArray(game, position, turnCounter);
	turnTracker();								//Why is turn tracker called here?
}

void updateArray (char game[][], int x, int turnCounter)
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
	game[x][y]=xo;
}

int verticalPosition (char game[][], int Xposition)
{
//if a -1 is returned, the move was invalid
//Matthew
	for (int i=0; i<=7; i++)
	{
		if (game[Xposition][i]==' ')
		{
			return i;
			i=10;
		}
	}
	printf("Please enter a valid move: ");							//find out the text for an invalid move;  Esham: text for invalid move is "Please enter a valid move: ""Please enter a valid move: "; than you.
	return -1;
}

void getPlayerNames (char player1[], char player2[])
{
//Esham
	int max;

	printf("Player 1, enter your name: ");
	getstr(max,player1);
	printf("Player 2, enter your name: ");
	getstr(max,player2);


}

void getstr(int max, char str[])
{
//Esham

	int i = 0;

	do{
		str[i] = getchar();
		i++;
	}while(i<max && str[i - 1] != '\n');
	str[i - 1] = '\0';

}
