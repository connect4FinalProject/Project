//Matthew Julio, Esham Mahmud, Maddison Hicks-Kuskie
//due May 5
//This is a connect 4 game that will display the hisoric wins to the user

#include<stdio.h>
#include<string.h>
#define maxName 50
#define record "scores.txt"
#define maxTurns 49
#define size 7

//previews
int getMenuChoice (void);
void displayGame (char game[][size+1]);
int checkForWinH (char game[][size+1]);
int checkForWinV (char game[][size+1]);
int checkForWinDDownRight (char game[][size+1]);
int checkForWinDUpRight (char game[][size+1]);
int checkForWinDDownLeft (char game[][size+1]);
int checkForWinDUpLeft (char game[][size+1]);
int checkForWins (char game[][size+1]);
void displayWins (FILE* wins);
int turnTracker (int turnCounter);
void recordWin (FILE* wins, char winnerName[]);
void getUserInput (char game[][size+1], int turnCounter);
void updateArray (char game[][size+1], int x, int turnCounter);
int verticalPosition (char game[][size+1], int Xposition);
void getPlayerNames (char player1[], char player2[]);
void getstr(int max, char str[]);

int main (void)
{
//Matthew
	char game [size] [size+1];
	for (int i=0; i<size; i++)
	{
		for(int index=0; index<size+1; index++)
		{
			game [i] [index]=' ';
		}
	}
	char player1[maxName], player2[maxName], winner[maxName];
	_Bool win=0;
	int turnCounter=-1, menuChoice;
	FILE *wins;
	menuChoice=getMenuChoice();
	do
	{
		switch(menuChoice)
		{
		case 1:
			{
				getPlayerNames (player1, player2);
				do
				{
					displayGame (game);
					getUserInput (game, turnCounter);
					turnCounter++;
					win=checkForWins (game);
				}while(win!=0 && turnCounter!=maxTurns);
				if (win==1)
				{
					wins=fopen("record", "a");
					recordWin (wins, winner);
					fclose(wins);
				}else
				{
					if (turnCounter>=maxTurns)
					{
						printf("It's a tie! Try again...\nPlay again? 1 - yes: ");
					}
				}
			}
		case 2:
			{
				wins=fopen("record", "r");
				displayWins(wins);
				fclose(wins);
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

void displayGame (char game[] [size+1])
{
//Matthew
	char temp;
	printf("[1][2][3][4][5][6][7]\n");
	printf("---------------------\n");
	for(int index=0; index<size; index++)
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

int checkForWinH (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int x,y,count;
	int win = 0;
	count = 1;
	x = 0;
	y = 0;
	while(x != 7)
	{
		if(game[x][y] == game[x][y+1] && y != 6)
		{
			if(count >= 4){
				x = 7;
				win = 1;
			}else{
				count++;
				y++;	
			}
		}else if(game[x][y] != game[x][y+1] && y != 6)
		{
			if(count >= 4){
				x = 7;
				win = 1;
			}else{
				count = 1;
				y++;		
			}

		}else if(y == 6)
		{
			if(count >= 4){
				x = 7;
				win = 1;
			}else{
				x++;
				y = 0;		
			}
		}
	}
return win;
}

int checkForWinV (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int x,y,count;
	int win = 0;
	count = 1;
	x = 0;
	y = 0;
	while(x != 7)
	{
		if(game[x][y] == game[x+1][y] && y != 3)
		{
			if(count >= 4){
				x = 7;
				win = 1;
			}else{
				count++;
				y++;		
			}

		}else if(game[x][y] != game[x+1][y] && y != 3)
		{
			if(count >= 4){
				x = 7;
				win = 1;
			}else{
				count = 1;
				y++;	
			}
		}else if(y == 3)
		{
			if(count >= 4){
				x = 7;
				win = 1;
			}else{
				x++;
				y = 0;		
			}
		}
	}
return win;
}

int checkForWinDDownRight (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int x,y,count,i;
	int win = 0;
	count = 1;
	x = 0;
	y = 0;
	i = 0;
	while(i != 4)
	{
		if(game[x+i][y] == game[x+i+1][y+1] && y != 4)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				count++;
				y++;
				x++;		
			}
		}else if(game[x+i][y] != game[x+i+1][y+1] && y != 4)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				count = 1;
				y++;
				x++;
			}
		}else if(y == 4)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				i++;
				y = 0;
				x = 0;
				count = 1;
			}
		}
	}
return win;
}

int checkForWinDUpRight (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int x,y,count,i;
	int win = 0;
	count = 1;
	x = 6;
	y = 0;
	i = 0;
	while(i != 4)
	{
		if(game[x-i][y] == game[x-i-1][y+1] && y != 4)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				count++;
				y++;
				x--;		
			}
		}else if(game[x-i][y] != game[x-i-1][y+1] && y != 4)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				count = 1;
				y++;
				x--;
			}
		}else if(y == 4)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				i++;
				y = 0;
				x = 6;
				count = 1;
			}

		}
	}
return win;
}

int checkForWinDDownLeft (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int x,y,count,i;
	int win = 0;
	count = 1;
	x = 0;
	y = 6;
	i = 0;
	while(i != 4)
	{
		if(game[x+i][y] == game[x+i+1][y+1] && y != 2)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				count++;
				y--;
				x++;		
			}
		}else if(game[x+i][y] != game[x+i+1][y+1] && y != 2)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				count = 1;
				y--;
				x++;
			}
		}else if(y == 2)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				i++;
				y = 6;
				x = 0;
				count = 1;
			}
		}
	}
return win;
}

int checkForWinDUpLeft (char game[][size+1])
{
//Esham
// 1 = win 0 = no win
	int x,y,count,i;
	int win = 0;
	count = 1;
	x = 6;
	y = 6;
	i = 0;
	while(i != 4)
	{
		if(game[x-i][y] == game[x-i-1][y-1] && y != 2)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				count++;
				y--;
				x--;		
			}
		}else if(game[x-i][y] != game[x-i-1][y-1] && y != 2)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				count = 1;
				y--;
				x--;
			}
		}else if(y == 2)
		{
			if(count >= 4){
				i = 4;
				win = 1;
			}else{
				i++;
				y = 6;
				x = 6;
				count = 1;
			}
		}
	}
return win;
}

int checkForWins (char game[][size+1])
{
//Esham
	int win = 0;
	if(checkForWinH(game) == 1){
		win = 1;
	}else if(checkForWinV(game) == 1){
		win = 1;
	}else if(checkForWinDDownLeft(game) == 1){
		win = 1;
	}else if(checkForWinDDownRight(game) == 1){
		win = 1;
	}else if(checkForWinDUpLeft(game) == 1){
		win = 1;
	}else if(checkForWinDUpRight(game) == 1){
		win = 1;
	}else{
		win = 0;
	}
return win;
}

void displayWins (FILE* wins)
{
//Maddison
char names[maxName], temp;
int score[maxName];

	for(int i=0; i < maxName && fscanf("") != '\n'; i++){
		scanf("%c", temp);
		names[i] = temp;
	}

	for(int a = 0; a < 11; a++){
	fscanf(wins, "%c %d", &names[11], &score[11]);
	}
	for(int w = 0; w < 10; w++){
		printf("%c: %d", names[w], score[w]);
	}
}

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

void recordWin (FILE* wins, char winnerName[])
{
//Maddison
int max = 20, score[11][2], array[max], i, j, swap, n;
char name/**, maxName = 50**/; //what is going on with the maco here?

	for(int n = 0; n < 10 ; n++){
		fprintf(wins, "%c %d", winnerName[maxName], score[11][2]);
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

void getUserInput (char game[][size+1], int turnCounter)
{
//Maddison
char playerName;
int chosenNum, i, position;

	printf("%c - Enter your move: ", playerName);
	scanf("%d", &position);

	updateArray(game, position, turnCounter);

}

void updateArray (char game[][size+1], int x, int turnCounter)
{
//Matthew
	int y;
	char xo;
	y=verticalPosition(game, x);
	if(y==-1)
	{
		return;
	}
	xo=turnTracker (turnCounter);
	game[x][y]=xo;
}

int verticalPosition (char game[][size+1], int Xposition)
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
	printf("Please enter a valid move: \n");
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
