/*
Eric Parton
A01023503
Compilers


Grammar rules being implemented
K -> COC|(K)
C -> id|K
O -> +|-|*|/

*/

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void K();
void C();
void O();

string input;
bool error = 0;
int pos = 0;

bool currentIsAnOperator() {
	if (input[pos] == '+' || input[pos] == '-' || input[pos] == '*' || input[pos] == '/')
	{
		return 1;
	}
	return 0;
}

int main() {
	while (1) {
		cout << "Input your expression, don't use spaces" << endl;
		cin >> input;

		K();	//All expressions start at K
		

		cout << endl << error << " " << pos << endl;
	}
	cin >> input;
}

void K() {
	cout << "K" << input[pos];
	//If it's (K)
	if (input[pos] == '(') {
		pos++;
		K();
		if (input[pos] == ')')
		{
			pos++;
		}
		else
		{
			error++;
		}
	}
	//Otherwise if it's a constant
	else if (!currentIsAnOperator()){
		C();
		O();
		C();
	}
	else {
		error++;
	}
}

//Constant or another expression
void C() {
	cout << "C" << input[pos];
	if (currentIsAnOperator()) {
		error++;
		pos++;
	}
	else {
		pos++;
		//If it's the end of the input
		if (pos >= input.length() || currentIsAnOperator()) {
			//All good
		}
		else {
			K();
		}
	}
	

}

//Operator
void O() {
	cout << "O" << input[pos] << flush;
	//If there's an invalid operator
	if (!currentIsAnOperator)
	{
		error++;
	}

	pos++;
}