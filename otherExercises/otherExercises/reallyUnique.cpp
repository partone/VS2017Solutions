#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v = { 3, 4, 6, 8, 7, 7, 5, 4, 8, 3, 6 };
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size() - 1; i = i + 2) {
		cout << v[i] << " " << v[i + 1] << endl;
		if (v[i] != v[i + 1]) {
			cout << v[i] << " is the unique number" << endl;
			i = v.size();
		}
	}

	cin >> v[0];
	return 0;
}