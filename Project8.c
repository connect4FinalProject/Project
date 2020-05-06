//Matthew Julio, Esham Mahmud, Maddison Hicks-Kuskie
//due May 5
//This is a connect 4 game that will display the hisoric wins to the user

#include<stdio.h>
#include<string.h>
#define maxName 50
#define maxTurns 49
#define size 7

//previews
int getMenuChoice (void);
void displayGame (char game[][size+1]);
int checkForWinH (char game[][size+1]);
int checkForWinV (char game[][size+1]);
int checkForWinD1 (char game[][size+1]);
int checkForWinD2 (char game[][size+1]);
int checkForWins (char game[][size+1]);
void displayWins (FILE* wins);
int turnTracker (int turnCounter);
void recordWin (FILE* wins, char winnerName[]);
void getUserInput (char game[][size+1], int turnCounter, char player1[], char player2[]);
void updateArray (char game[][size+1], int x, int turnCounter);
int verticalPosition (char game[][size+1], int Xposition);
void getPlayerNames (char player1[], char player2[]);
void getstr(int max, char str[]);

int main (void)
{
//Matthew
	char game [size] [size+1];
	char player1[maxName], player2[maxName], winner[maxName];
	int win = 0;
	int turnCounter=-1, menuChoice;
	int playerTemp;
	FILE *wins;
	_Bool gamePlayed=0;
	menuChoice=getMenuChoice();
	do
	{
		switch(menuChoice)
		{
		case 1:
			{
				for (int i=0; i<size+1; i++)
				{
					for(int index=0; index<size; index++)
					{
						game [i] [index]=' ';
					}
				}
				if (gamePlayed==0)
				{
					getPlayerNames (player1, player2);
				}
				do
				{
					turnCounter++;
					displayGame (game);
					getUserInput (game, turnCounter, player1, player2);
					win=checkForWins(game);
				}while(win!=1 && turnCounter!=maxTurns);
				if (win==1)
				{
					wins=fopen("scores.txt", "a");
					recordWin (wins, winner);
					fclose(wins);
					displayGame (game);
					playerTemp = turnTracker(turnCounter);
					if(playerTemp == 0){
						printf("\n%s YOU WON!! CONGRATS :D\n\nPlay again? 1 - yes: ",player1);
					}else if(playerTemp == 1){
						printf("\n%s YOU WON!! CONGRATS :D\n\nPlay again? 1 - yes: ",player2);	
					}
					scanf("%d", &menuChoice);
				}else
				{
					if (turnCounter%maxTurns==0)
					{
						printf("It's a tie! Try again...\nPlay again? 1 - yes: ");
							scanf("%d", &menuChoice);
					}
				}
				gamePlayed=1;
				break;
			}
		case 2:
			{
				wins=fopen("scores.txt", "r");
				displayWins(wins);
				fclose(wins);
				break;
			}
		case 0:
			{
				return 0;
				break;
			}
		default:
			{
				printf("Please enter a valid option!\n");
				break;
			}
		}
	} while (menuChoice!=0);
	return 0;
}

//Displays a menu with choices for the user to pick from. From here they can start a game, show scores, and exit the game.
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

//Displays the game board
void displayGame (char game[] [size+1])
{
//Matthew
	char temp;
	printf("[1][2][3][4][5][6][7]\n");
	printf("---------------------\n");
	for(int index=6; index>=0; index--)
	{
		for(int i=0; i<size; i++)
		{
			temp=game [index][i];
			printf("[%c]", temp);
		}
		printf("\n");
	}
	printf("---------------------\n");
	printf("[1][2][3][4][5][6][7]\n");
}

int checkForWins(char game[][size+1]){
	int win = 0;
	if(checkForWinH(game) == 1){
		win = 1;
	}else if(checkForWinV(game) == 1){
		win = 1;
	}else if(checkForWinD1(game) == 1){
		win = 1;
	}else if(checkForWinD2(game) == 1){
		win = 1;
	}
return win;
}

//Checks for horizontal combinations
int checkForWinH (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int combo = 1,x = 0,y = 0,count = 0,win = 0;

	while(y != 7){
		//printf("a\n");
		if(game[y][x] != ' ' && game[y][x+1] == game[y][x]){
			//printf("b\n");
			combo++;
			x++;
			if(combo >= 4){
				//printf("c\n");
				y = 7;
			}
		}else if(x == 7){
			//printf("d\n");
			combo = 1;
			y++;
			x = 0;
		}else{
			//printf("e\n");
			x++;
			combo = 1;
		}
	}
	if (combo >= 4){
		//printf("f\n");
		win = 1;
	}else{
		//printf("g\n");
		win = 0;
	}
	//printf("%d\n",win);
	return win;
}

int checkForWinV (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int combo = 1,x = 0,y = 0,count = 0,win = 0;

	while(x != 7){
		//printf("a\n");
		if(game[y][x] != ' ' && game[y+1][x] == game[y][x]){
			//printf("b\n");
			combo++;
			y++;
			if(combo >= 4){
				//printf("c\n");
				x = 7;
			}
		}else if(y == 7){
			//printf("d\n");
			combo = 1;
			x++;
			y = 0;
		}else{
			//printf("e\n");
			y++;
			combo = 1;
		}
	}
	if (combo >= 4){
		//printf("f\n");
		win = 1;
	}else{
		//printf("g\n");
		win = 0;
	}
	//printf("%d\n",win);
	return win;
}

int checkForWinD1 (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int combo = 1,x = 0,y = 0,count = 0,win = 0,i = 0,j = 0;

	while(y != 7){
		//printf("a\n");
		if(game[y][x] != ' ' && game[y+1][x+1+i] == game[y][x+i]){
			//printf("b\n");
			combo++;
			x++;
			y++;
			if(combo >= 4){
				//printf("c\n");
				y = 7;
			}
		}else if(x == 7){
			//printf("d\n");
			combo = 1;
			i++;
			j++;
			y = 0;
			x = 0;
		}else{
			//printf("e\n");
			x++;
			combo = 1;
		}
	}
	if (combo >= 4){
		//printf("f\n");
		win = 1;
	}else{
		//printf("g\n");
		win = 0;
	}
	//printf("D1 %d\n",win);
	return win;
}

int checkForWinD2 (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int combo = 1,x = 6,y = 0,count = 0,win = 0,i = 0,j = 0;

	while(y != 7){
		//printf("a\n");
		if(game[y][x] != ' ' && game[y+1][x-1-i] == game[y][x-i]){
			//printf("b\n");
			combo++;
			x--;
			y++;
			if(combo >= 4){
				//printf("c\n");
				y = 7;
			}
		}else if(x == 7){
			//printf("d\n");
			combo = 1;
			i++;
			j++;
			y = 0;
			x = 6;
		}else{
			//printf("e\n");
			x--;
			combo = 1;
		}
	}
	if (combo >= 4){
		//printf("f\n");
		win = 1;
	}else{
		//printf("g\n");
		win = 0;
	}
	//printf("D2 %d\n",win);
	return win;
}

//This function opens the game file. It then displays results and record a new win through recordWin.
void displayWins (FILE* wins)
{
//Maddison
char names[maxName], temp;
int score[maxName];


	for(int i=0; i < maxName && fscanf(wins, "%c %d", names, score) != '\n'; i++){
		scanf("%c", &temp);
		names[i] = temp;
	}

	for(int a = 0; a < 11; a++){
	fscanf(wins, "%c %d", &names[11], &score[11]);
	}
	for(int w = 0; w < 10; w++){
		printf("%c: %d", names[w], score[w]);
	}
}
//Checks which player's turn it currently is.
int turnTracker (int turnCounter)
{
//Esham
	int turn;
	if (turnCounter % 2 == 0){
		turn = 1;
	}else{
		turn = 0;
	}

	return turn;
}

//This function is called from displayWins to append the file and add a new win.
void recordWin (FILE* wins, char winnerName[])
{
//Maddison
int max = 20, score[11][2], array[max], i, j, swap, n;
char name, mName = 50;

	for(int n = 0; n < 10 ; n++){
		fprintf(wins, "%c %d", winnerName[mName], score[11][2]);
	}
	//Bubble sort:
	for(i = 0; i < 10; i++){
	fscanf(wins, "%c %d", &name, &array[i]);
	}
	for(i = 0; i < 10 - 1; i++){
		for(j = 0; j < 10 - i - 1; j++){
			if(array[j] > array[j+1]){
			swap = array[j];
			array[j] = array[j+1];
			array[j+1] = swap;
		}
		}
	}

}

void getUserInput (char game[][size+1], int turnCounter, char player1[], char player2[])
{
//Maddison
	int position, temp = turnTracker(turnCounter);
	if(temp == 0){
	printf("%s - Enter your move: ", player1);
	scanf("%d", &position);
	}
	else if(temp == 1){
	printf("%s - Enter your move: ", player2);
	scanf("%d", &position);
	}
	updateArray(game, position, turnCounter);


}

//Checks each vertical position from to to bottom to see where an open spot is in the array.  
void updateArray (char game[][size+1], int x, int turnCounter)
{
//Matthew
	int y, xoCode;
	char xo;
	x=x-1;
	y=verticalPosition(game, x);
	if(y==-1)
	{
		return;
	}
	xoCode=turnTracker (turnCounter);
	if(xoCode==0)
	{
		xo='X';
	}
	else
	{
		if(xoCode==1)
		{
			xo='O';
		}
	}
	game[y][x]=xo;
}

//This function is called by the update array function to know the vertical position of the array.
int verticalPosition (char game[][size+1], int Xposition)
{
//if a -1 is returned, the move was invalid
//Matthew
	if (Xposition<0 || Xposition>=7)
	{
	printf("Please enter a valid move: \n");
	return -1;
	}
	for (int i=0; i<=7; i++)
	{
		if (game[i][Xposition]==' ')
		{
			return i;
			i=10;
		}
	}
	printf("Please enter a valid move: \n");
	return -1;
}

//This function prompts the users to enter their names, then it is stored in a string.
void getPlayerNames (char player1[], char player2[])
{
//Esham
	int max;

	printf("Player 1, enter your name: ");
	scanf("%s",player1);
	printf("Player 2, enter your name: ");
	scanf("%s",player2);

	printf("%s, you'll be X's\n", player1);
	printf("%s, you'll be O's\n", player2);


}
