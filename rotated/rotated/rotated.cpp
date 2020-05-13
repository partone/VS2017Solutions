#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int x;
	vector<int> one = { 1, 2, 3, 6, 4, 5, 7 };
	vector<int> two = { 4, 5, 7, 1, 2, 3, 6 };

	int first;
	if (one.size() != two.size()) {
		cout << "Size mismatch" << endl;
		return 0;
	}

	int firstInSecondIndex = -1;
	first = one[0];
	for (int i = 0; i < one.size(); i++) {
		if (two[i] == first) {
			firstInSecondIndex = i;
		}
	}

	if (firstInSecondIndex == -1) {
		cout << "Not rotated" << endl;
		return 0;
	}

	for (int i = 0; i < one.size(); i++) {
		if (firstInSecondIndex >= one.size()) {
			firstInSecondIndex = 0;
		}

		if (one[i] != two[firstInSecondIndex]) {
			cout << "Not rotated" << endl;
			cin >> x;
			return 0;
		}
		else {
			firstInSecondIndex++;
		}
	}
	cout << "Damn, you actually found a rotated one!" << endl;
	cin >> x;
	return 0;
}