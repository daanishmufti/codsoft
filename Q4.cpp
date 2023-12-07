#include<iostream>
#include<fstream>
#include <cstdlib>
#include <vector>
using namespace::std;

string file = "C:\\code soft intern code c++\\list.txt";

void add()
{
	cin.clear();
	cin.sync();
	ofstream outFile(file.c_str(), ios::app);
	string cont;
	cout << "Enter content: ";
	getline(cin, cont);
	if (!outFile)
	{
		cout << "File does not exist !";
		exit(1);
	}
	outFile << cont << endl;
	outFile.close();
	cout << endl;
	
}

void showlist()
{
	string cont;
	ifstream inFile(file.c_str(), ios::in);
	if(!inFile)
	{
		cout << "File does not exist !" << endl;
		exit(1);
	}
	getline(inFile, cont);
	while (!inFile.eof())
	{
		cout << cont << endl;
		getline(inFile, cont); 
	}
	inFile.close();
	cout << endl << endl;
	}

void removecont()
{
	 int cont;
    showlist();
    cin.clear();
    cin.sync();
    cout << "What do you want to remove? ";
    cin >> cont;

    vector<string> options;
    ifstream inFile(file.c_str(), ios::in);

    if (!inFile) {
        cout << "File not found. " << endl;
        exit(1);
    }

    string opt;
    int num = 1;

    while (getline(inFile, opt)) {
        if (num != cont) {
            options.push_back(opt);
        }
        ++num;
    }

    inFile.close();

    ofstream outFile(file.c_str(), ios::out);
    if (!outFile) {
        cout << "File not found. " << endl;
        exit(1);
    }

    for (int i = 0; i < options.size(); ++i) {
        outFile << options[i] << endl;
    }

    outFile.close();

    cout << "Option removed successfully.\n";
}

void mark() {
    int taskNum;
    showlist();
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNum;

    vector<string> options;
    ifstream inFile(file.c_str(), ios::in);

    if (!inFile) {
        cout << "File not found." << endl;
        exit(1);
    }

    string opt;
    int num = 1;

    while (getline(inFile, opt)) {
        if (num != taskNum) {
            options.push_back(opt);
        } else {
            options.push_back(opt + " (completed)");
        }
        ++num;
    }

    inFile.close();

    ofstream outFile(file.c_str(), ios::out);
    if (!outFile) {
        cout << "File not found." << endl;
        exit(1);
    }

    for (int i = 0; i < options.size(); ++i) {
        outFile << options[i] << endl;
    }

    outFile.close();

    cout << "Task marked as completed successfully.\n";
}
int main()
{
	int option = 1;
	while(option != 0)
	{
		cout << " select an option " << endl;
		cout << "0. Exit program "<< endl;
		cout << "1. Dislpay to-dolist "<< endl;
		cout << "2. Add item to list "<< endl;
		cout << "3. Remove item "<< endl;
		cout << "4. Mark Tash as completed "<< endl;
		cout << "Enter your option: ";
		cin >> option;
		switch(option)
		{
			case(0):
			{
				break;
			}
			case(1):
			{
			    showlist();	
				break;	
			}
			case(2):
			{
				add();
            break;
			}
			case(3):
			{
				removecont();
				break;
			}
			case(4):
			{
				mark();
				break;
			}
		}
		
	}
	return 0;
}
