#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int x = 0;
	int digitPlace;
	int singleDigit;
	string numbero = "4235";
	digitPlace = numbero.size() - 1;
	for (int i = 0; i < numbero.size(); i++) {
		switch (numbero[i]) {
		case '0':
			singleDigit = 0;
			break;
		case '1':
			singleDigit = 1;
			break;
		case '2':
			singleDigit = 2;
			break;
		case '3':
			singleDigit = 3;
			break;
		case '4':
			singleDigit = 4;
			break;
		case '5':
			singleDigit = 5;
			break;
		case '6':
			singleDigit = 6;
			break;
		case '7':
			singleDigit = 7;
			break;
		case '8':
			singleDigit = 8;
			break;
		case '9':
			singleDigit = 9;
			break;
		default:
			cout << "Error" << endl;
		}

		x = x + (singleDigit*pow(10, digitPlace));
		digitPlace--;
	}
	cout << x << endl;
	cin >> x;
	return 0;
}