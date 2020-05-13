/*
Eric Parton
A01023503
Compilers

Grammar rules
S -> TA
T -> CM
A -> +TA | -TA | e
M -> *CM | /CM | e
C -> (S) | id | -id
*/

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//States
void S();	//Start
void T();	//Auxiliary state
void A();	//Addition or subtraction
void M();	//Multiplication or division
void C();	//Constant or parenthesis

string input;
bool error;
int pos;

void removeGodDamnSquareRootFromInput() {
	string toReplace("sqrt");
	int loc = input.find(toReplace);
	while (loc != -1) {
		input.replace(loc, toReplace.length(), "1");
		loc = input.find(toReplace);
	}
}

void main() {
	while (1) {
		error = 0;
		pos = 0;

		cout << "Input your expression, don't use spaces, positive integers only" << endl;
		cin >> input;

		removeGodDamnSquareRootFromInput();

		S();	//All expressions start at S

		//If there are trailing issues
		if (pos < input.length()) {
			error++;
			cout << "Error at index " << pos << ": Unidentified trailing character(s)" << endl;
		}

		if (error == 0) {
			cout << "Beautiful expression, no errors" << endl;
		}
		cout << endl;
	}
}

//Increments pos to skip multi-digit values
void skipToEndOfValue() {
	if (pos >= input.length()) return;
	bool decimal = 0;
	while (input[pos] == '1' || 
		input[pos] == '2' ||
		input[pos] == '3' || 
		input[pos] == '4' || 
		input[pos] == '5' || 
		input[pos] == '6' || 
		input[pos] == '7' || 
		input[pos] == '8' || 
		input[pos] == '9' || 
		input[pos] == '0' ||  
		input[pos] == '.') {
		if (!decimal && input[pos] == '.') decimal = 1; else if (decimal && input[pos] == '.') {
			error++;
			cout << "Error at index " << pos << ": Invalid floating point number" << endl;
		}
		pos++;
	}
	if (pos < input.length()) {
		if (input[pos] != '1' &&
			input[pos] != '3' &&
			input[pos] != '4' &&
			input[pos] != '5' &&
			input[pos] != '6' &&
			input[pos] != '7' &&
			input[pos] != '8' &&
			input[pos] != '9' &&
			input[pos] != '0' &&
			input[pos] != '.' &&
			input[pos] != '*' &&
			input[pos] != '+' &&
			input[pos] != '-' &&
			input[pos] != '/' &&
			input[pos] != '(' &&
			input[pos] != ')' &&
			input[pos] != '^'
			) {
			error++;
			cout << "Error at index " << pos << ": Invalid data type" << endl;
		}
	}
}

bool isAnOperator(int i) {
	if (i >= input.size()) {
		return 0;
	}
	if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^')
	{
		return 1;
	}
	return 0;
}

bool checkOutOfBounds() {
	if (pos > input.length()) {
		error++;
		cout << "Error at index " << pos - 1 << ": Unidentified trailing character(s)" << endl;
		return 1;
	}
	return 0;
}

//Start
void S() {
	T();
	A();
}

//Auxiliary state
void T() {
	C();
	M();
}

//Addition or subtraction
void A() {
	if (checkOutOfBounds()) return;
	//+TA or -TA
	if (input[pos] == '+' || input[pos] == '-')
	{
		pos++;
		T();
		A();
	}
}

//Multiplication or division
void M() {
	if (checkOutOfBounds()) return;
	//*CM or /CM
	if (input[pos] == '*' || input[pos] == '/' || input[pos] == '^')
	{
		pos++;
		C();
		M();
	}
}

//Constant or parenthesis
void C() {
	if (checkOutOfBounds()) return;

	//A negative number
	if (input[pos] == '-') pos++;
	
	//If the rule is (S)
	if (input[pos] == '(') {
		pos++;
		S();
		if (input[pos] == ')') {
			pos++;
		}
		else {
			error++;
			cout << "Error at index " << pos << ": Missing ')'" << endl;
		}

	}
	//If an terminal has been placed
	else if (!isAnOperator(pos)) {
		pos++;
		skipToEndOfValue();
	}
	//If someone fucked up
	else {
		error++;
		cout << "Error at index " << pos << ": Not a constant or '('" << endl;
	}
}