//Matthew Julio, Esham Mahmud, Maddison Hicks-Kuskie
//due May 5
//This is a connect 4 game that will display the hisoric wins to the user

//GENERAL NOTES
//2D string "game" is the game board, folows game [x-coord] [y-coord] format										Read by: Matthew, Esham, Maddi
//files will be open when given to functions from main													Read by: Matthew, Esham, Maddi
//recordWin is the only funciton called in main for the win scenario.  Make a note if you want that to change.						Read by: Matthew, Esham, Maddi
//can someone with a workign executable (Matthew cannont get his to stop winning) tell me what the error message is for not opening the files.txt? 	Read by: Matthew, Esham, Maddi
	//There is no error message as far as I can tell, it only shows a blank line then shows the menu again.
//Matthew is aware that the functions do not give any verriables in their present state.								Read by: Matthew, Esham, Maddi


#include<stdio.h>
#include<string.h>
#define maxName 50
#define record "scores.txt"
#define maxTurns 49
#define size 7

previews
int getMenuChoice (void);
void displayGame (char game[][]);
_Bool checkForWinH (char game[][]);
_Bool checkForWinV (char game[][]);
_Bool checkForWinD (char game[][]);
void displayWins (FILE* wins);
_Bool turnTracker (int position);
void recordWin (FILE* wins, char winnerName[]);
void getUserInput (char game[][], int turnCounter);
void updateArray (char game[][], int userInput, int turnCounter);
int verticalPositions (char game[][], char x-position);
void getPlayerNames (char player1[], char player2[]);
void getstr(int max, char str[]);

int main (void)
{
//Matthew
	char game [size] [size+1] {       }{       }{       }{       }{       }{       }{       };
	char player1[maxName], player2[maxName], winner[maxName];			//fundamental misunderstanding of how char array works
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
					displayGame (game []);
					getUserInput (turnCounter, game [], turnCounter);
					turnCounter++;
					win=checkForWin (game []);
				}while(win==0 && turnCounter!=maxTurns);
				if (win==1)
				{
					wins=fopen("record", "a");
					recordWin (wins, winner []);
				}else
				{
					if (turnCounter==maxTurns)
					{
						printf("It's a tie! Try again...\nPlay again? 1 - yes: ");
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

void displayGame (char game[])
{
//Matthew
	printf("[1][2][3][4][5][6][7]\n");
	printf("---------------------\n");
	for(int index=0; index!=7; index++)
	{
		for(int i=0; i!=7; i++)
		{
			printf("[%s]", game [index]);
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

void displayWins (FILE* wins)
						//Does it sort the displayed results? - it does that in recordWin within the file. Assuming I'm doing what the design document says for the function.
{
//Maddison
//Function scans scores.txt file for name and score then displayes the informations to the user's screen.
char names[];
int score[];

	fscanf(wins, "%c %d", &names[11], &score[11]); //(names[] stores 11 items so it only looks for 10 items-ish (I think))

	for(int w = 0; w < numNames; w++){
		printf("%c: %d", names[w], score[w]);
	}
}

_Bool turnTracker (void)
{
//Esham

}

void recordWin (FILE* wins, char winnerName[][])
{
//Maddison
//This function saves the player's names and corresponding scores to the scores.txt file. It stores only the top ten scores and is sorted by highest order.
int score[][], array[], i, j, swap;
char name;

	//Saving win to file:
	for(int n = 0; n < ; n++){
		fprintf(wins, "%c %d", winnerName[11][maxName], score[11][2]);//array is: [max rows(no more than 10][max characters or integers in that row]
}
	//Bubble sort:
	for(i = 0; i < 10; i++){
	fscanf("%c %d", &name, &array[i]);
	}
	for(i = 0; i < 10 - 1; c++){
		for(j = 0; j < n - i - 1){
			if(array[j] > array[j+1]){
			swap = array[j];
			array[j] = array[j+1];
			array[j+1] = swap;
		}
		}
	}

}

void getUserInput (char game[][], int turnCounter)	//do i need turnCounter? it says so in the design document but I don't see why.
{
//Maddison
//This function will get user input to determine their move then call the updateArray funcion to place the user's symbol in their chosen spot.
char playerName;
int chosenNum, i;
	printf("%c - Enter your move: ", playerName);		//Is there anything else I need to do for this function? I'm a little stuck and wouldn't mind some advice - Maddison
	scanf("%d", game[chosenNum][i]);
	updateArray(game[][], position, turnCounter);
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
