#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int x;
	vector<int> one = { 3, 6, 5, 4, 8, 5 };
	vector<int> two = { 3, 5 , 7, 1, 8, 5, 9, 5, 3 };
	vector<int> dupes;

	sort(one.begin(), one.end());
	sort(two.begin(), two.end());

	int i = 0;
	int j = 0;

	while (i < one.size() && j < two.size()) {
		cout << one[i] << " " << two[j] << endl;
		if (one[i] == two[j]) {
			dupes.push_back(one[i]);
			i++;
			j++;
			cout << "Match" << endl;
		}
		else if (one[i] < two[j]) {
			i++;
		}
		else {
			j++;
		}	}

	for (int k = 0; k < dupes.size(); k++) {
		cout << dupes[k] << " ";
	}
	cout << endl;
	cin >> x;
	return 0;
}