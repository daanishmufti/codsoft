#include<iostream>
using namespace::std;

int main()
{
	double num1 , num2, result;
	char op;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	cout << "What operation would you like to apply: ";
	cin >> op;
	switch(op)
	{
		case('+'):
		{
			result = num1 + num2;
			cout << "The result is "<< result;
			break;
		}
		case('-'):
		{
			result = num1 - num2;
			cout << "The result is "<< result;
			break;
		}
		case('*'):
		{
			result = num1 * num2;
			cout << "The result is "<< result;
			break;
		}
		case('/'):
		{
		 if(num2 != 0)
		 {
		 	result = num1 / num2;
		 	cout << "The result is "<< result;
		 }
		 else
		 {
		 	 cout << "0 Error";
		 }
		 break;
		}
		case('%'):
		{
			result = int(num1) % int(num2);
			cout << result;
			break;
		}
	}
	return 0;
}
