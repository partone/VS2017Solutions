#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int intToBin(int n);

int main() {
	int x;
	cout << intToBin(64) << endl;
	cout << intToBin(65) << endl;
	cout << intToBin(9) << endl;
	cout << intToBin(23) << endl;
	cout << intToBin(4) << endl;

	cin >> x;
	return 0;
}

int intToBin(int n){
	float nDec = n;
	int nBin = 0;
	int digitCounter = 1;
	while (nDec >= 1) {
		nDec = nDec / 2;
		if (floor(nDec) != nDec) {
			nDec = nDec - 0.5;
			nBin = nBin + digitCounter;
		}
		digitCounter = digitCounter * 10;
	}
	return nBin;
}
