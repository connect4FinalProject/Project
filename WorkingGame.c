#include<stdio.h>
#include<string.h>
#define maxName 50
#define record "scores.txt"
#define maxTurns 49
#define size 7

void displayGame (char game[][size+1]);

int main (void)
{
//Matthew
        char game [size] [size+1];
	for(int i=0; i<size;i++)
	{
		for(int index=0; index<size+1; index++) 
		{
			game[i][index]=' ';
		}
	}
	displayGame (game);
      return 0;
}


void displayGame (char game[][size+1])
{
//Matthew
        printf("[1][2][3][4][5][6][7]\n");
        printf("---------------------\n");
        for(int index=0; index<7; index++)
        {
                for(int i=0; i<7; i++)
		{
                	char temp=game [index][i];
                        printf("[%c]", temp);
                }
                printf("\n");
        }
        printf("---------------------\n");
        printf("[1][2][3][4][5][6][7]\n");
}

