#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 8
#define Y 8
int board[Y][X];

int ChessKon(int n);
int CheckKon(int n, int row, int col);
int BinarySeekHelp(int *arr, int len, int v, int left, int right);
int OptimalChessKonHelp(int n, int row, int col);
int OptimalChessKon();

void annull() {
	int i;
	int j;
	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			board[i][j] = 0;
		}
	}
}

void printBoard() {
	int i;
	int j;
	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			printf("%d %s", board[i][j], (board[i][j]<10)? " ":"" );
		}
		printf("\n");
	}
}

int checkboard(int n)
{
	int i;
	int j;
	if (n>2)
	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			if ((board[i][j] == n - 2) && board[i][j] != 0)
				if (CheckKon(n-1, i, j) == 0)
					return 0;
				else
					return 1;
		}
	}
	return 1;
}

int CheckKon(int n, int row, int col)
{
	int j = -3;
	int i = -3;
	int m=0;
	//if ((row - 2 >= 0) && (col - 1 >= 0))
	//	m += board[row-2][col-1]==n;
	//if ((row - 1 >= 0) && (col - 2 >= 0))
	//	m += board[row - 1][col - 2] == n;
	//if ((row + 2 <= Y) && (col - 1 >= 0))
	//	m += board[row +2][col - 1] == n;
	//if ((row + 1 <= Y) && (col - 2 >= 0))
	//	m += board[row + 1][col - 2] == n;
	//if ((row - 2 >= 0) && (col + 1 <= X))
	//	m += board[row - 2][col + 1] == n;
	//if ((row - 2 >= 0) && (col + 2 <= X))
	//	m += board[row - 2][col + 2] == n;
	do
	{
		if(++i==0) ++i;
		if ((row + i >= 0)&& (row + i < Y))
		do
		{
			if (++j == 0) ++j;
			if ((col + j >= 0) && (col + j < X) && (j!=0-i) && (j!=0+i))
			m += (board[row+i][col+j]==n) ? 1 : 0;

		} while (j!=2);
		j = -3;
	} while (i!=2);
	return m;
}

void swap(int *a, int *b)

{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int operations = 0;

int ChessKon(int n)          // workout 2
{
	if (checkboard(n) == 0) return 0;
	if (n == X*Y+1) return 1;
	int row;
	int col;
	for (row = 0; row < Y; row++) {
		for (col = 0; col < X; col++) {
			operations++;
			if (board[row][col] == 0)
			{
				board[row][col] = n;
				if (ChessKon(n + 1)) return 1;
				board[row][col] = 0;
			}
		}		
	}
	return 0;
}

int routes(int *arr, int leny, int lenx, int y, int x) {        //workout 1
	if (arr[x+y*leny]>0-1)
	if (x == 0 && y == 0)
		return 1;
	else if (x == 0)
		return routes(arr , leny, lenx, y-1, x);
	else if (y==0)
		return routes(arr, leny, lenx, y, x - 1);
	else
		return routes(arr, leny, lenx, y, x - 1) + routes(arr, leny, lenx, y - 1, x);

	return 0;
}

void CreateBlock(int *arr, int leny, int lenx)
{
	int i;
	int j;
	for (i = 0; i < leny; i++) {
		for (j = 0; j < lenx; j++) {
		if(rand()%100>90) arr[i*leny+j] = -1;
		else arr[i*leny+j] = 0;
		}
	}
}

void printBoard2(int *arr, int leny, int lenx) {
	int i;
	int j;
	for (i = 0; i < leny; i++) {
		for (j = 0; j < lenx; j++) {
			printf("%d %s", arr[i*leny+j], (arr[i*leny + j]<0) ? "":" ");
		}
		printf("\n");
	}
}


int BinarySeek(int *arr, int len, int v)
{
	int left = 0;
	int right = len;
	//int mid = len / 2;
	return BinarySeekHelp(arr, len, v, left, right);
}

int BinarySeekHelp(int *arr, int len, int v, int left, int right)
{
	int mid = (left + right) / 2;
	if (v > arr[mid])
	{
		if (mid == left) mid++;
		return BinarySeekHelp(arr, len, v, mid, right);
	}
	else if (v<arr[mid]) return BinarySeekHelp(arr, len, v, left, mid);
	else if(v==arr[mid]) return mid;

	return 0;
		
	
}


	int main(int argc, char *argv[])

	{
		srand(time(0));
		annull();		
		(ChessKon(1));      //1,135,343,136 operation   1 min and 35 sek
		printBoard();
		printf("%d\n", operations); 

		int board2[10][10];
		CreateBlock(board2, 10, 10);
		printBoard2(board2, 10, 10);
	    int i;
	    int j;
	    for (i = 0; i < 10; i++) {
		 for (j = 0; j < 10; j++) {
	       printf("%6d", routes(board2, 10, 10, i, j));
	      }
	    printf("\n");
       }
		int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		printf("%d seeking element i\n", BinarySeek(a, 20, 13));

		annull();
		OptimalChessKon();      //70,958,971    3.323 sek
		printBoard();
		printf("%d\n", operations);  

	
	return 0;

}

	int OptimalChessKon()          // workout 2.5   
	{
		int n=1;
		int row ;
		int col ;
		for (row = 0; row < Y; row++)
			for (col = 0; col < X; col++)
			{
				operations++;
				board[row][col] = n;
				if ( OptimalChessKonHelp(n+1, row, col)) return 1;
				board[row][col] = 0;
			}
		return 0;
	}

	int OptimalChessKonHelp (int n, int row,int col)          
	{
		if (n == X*Y + 1) return 1;
		int j = -3;
		int i = -3;
		do
		{
			operations++;
			if (++i == 0) ++i;
			if ((row+i >= 0) && (row+i < Y))
				do
				{
					if (++j == 0) ++j;
					if ((col + j >= 0) && (col + j < X) && (j != 0 - i) && (j != 0 + i) && (board[row+i][col+j]) == 0)
					{
						board[row + i][col + j] = n;
						if (OptimalChessKonHelp(n + 1, row + i, col + j)) return 1;
						board[row + i][col + j] = 0;
					}

				} while (j != 2);
				j = -3;
		} while (i != 2);
		return 0;
	}