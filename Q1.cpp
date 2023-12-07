#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace::std;

int main()
{
	int num, random, tries;
	tries = 1;
	srand(time(NULL));
	random = rand() % 10;
	cout <<"Guess the number: ";
	cin >> num;
    while(tries < 3)
    {
    	if(num == random)
    	{
    		cout << "You are correct " << num << " is the right guess";
    		return 0;
		}
		else if(num < random)
		{
			cout << "Too low, Please try agian: ";
			cin >> num;
			tries++;
		}
		else if(num > random)
		{
			cout << "Too high, Please try again: ";
			cin >> num;
			tries++;
		}
		else
		{
			cout << "Error";
			break;
		}
		
	}
	cout << "Your guesses ran out. The number was " << random ;
	return 0;
	
}
