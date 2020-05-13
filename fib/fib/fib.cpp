#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void fibInt(int n);
int fibRec(int n);

unordered_map<int, int> savedFib;


int main() {
	int x;
	//fibInt(11);
	cout << fibRec(11);
	cin >> x;
	return 0;
}

int fibRec(int n) {
	int k;
	n--;
 	if (n <= 1) {
		return 1;
	}
	if (savedFib.find(n) == savedFib.end()) {
		cout << n << " not found, calculating" << endl;
		k = fibRec(n - 1) + fibRec(n);
		savedFib.insert({ n, k });
	}
	else {
		cout << n << " found, time saved!" << endl;
		k = savedFib.find(n)->second;
	}
	return k;
}

void fibInt(int n) {
	int last = 0;
	int tmp;
	int current = 1;
	for (int i = 0; i < n; i++) {
		cout << current << " ";
		tmp = current;
		current = current + last;
		last = tmp;
	}
}