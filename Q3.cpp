#include <iostream>

using namespace::std;

void board(char boar[3][3])
{
	cout << "The board: " << endl;
	for(int i =0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			cout << boar[i][j] << " ";
		}
		cout << endl;
	}
}

int columns(char boar[3][3] , int c, char play)
{
	for (int r = 0 ; r < 3 ; r++ )
	{
		if (boar[r][c] != play)
		{
			return 0 ;
		}
	}
	return 1 ;
}

int rows(char boar[3][3] , int r, char play)
{
	for (int c = 0 ; c < 3 ; c++ )
	{
		if (boar[r][c] != play)
		{
			return 0 ;
		}
	}
	return 1 ;
}

int diagnols(char boar[3][3], char play)
{
	for (int i = 0 ; i < 3 ; i++)
	{
		if (boar[i][i] != play)
		{
			return 0;
		}
	}
	return 1;
}

int check(char boar[3][3], char play)
{
	for(int i = 0 ; i < 3 ; i++)
	{
		if ((rows(boar, i , play)) || (columns(boar, i , play)))
		{
		return 1;
	}
}
return diagnols(boar , play);
}

int main()
{
	char boards[3][3] = {{'1' , '2', '3'} ,
	{'4', '5', '6'}, {'7', '8', '9'}};
	
	board(boards);
	
	char turn = 'X';
	int n = 0;
	while(n != 1)
	{
		cout << "player "<< turn << ": ";
		int move;
		cout << endl << "Enter your move: ";
		cin >> move;
		
		int ro = (move - 1) / 3;
		int co = (move - 1) % 3;
		
		if (boards[ro][co] == 'X' || boards[ro][co] == 'O')
		{
			cout << "Error !. Move Invalid please try again: "<<endl;
			continue;
		}
		boards[ro][co] = turn;
		board(boards);
		
		if (check(boards , turn))
		{
			cout << "The player : " << turn << " wins !" << endl;
			break;
		}
		if (turn == 'X')
		{
			turn = 'O';
		}
		else
		turn = 'X';
	}
	
	return 0;
}
