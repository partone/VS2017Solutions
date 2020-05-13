#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSrch(vector<int> v, int s, int f, int n);

int main() {
	int x = 0;
	vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	sort(v.begin(), v.end());

	cout << binSrch(v, 0, v.size() - 1, -2) << endl;
	cout << binSrch(v, 0, v.size() - 1, -1) << endl;
	cout << binSrch(v, 0, v.size() - 1, 0) << endl;
	cout << binSrch(v, 0, v.size() - 1, 1) << endl;
	cout << binSrch(v, 0, v.size() - 1, 2) << endl;
	cout << binSrch(v, 0, v.size() - 1, 3) << endl;
	cout << binSrch(v, 0, v.size() - 1, 4) << endl;
	cout << binSrch(v, 0, v.size() - 1, 5) << endl;
	cout << binSrch(v, 0, v.size() - 1, 6) << endl;
	cout << binSrch(v, 0, v.size() - 1, 7) << endl;
	cout << binSrch(v, 0, v.size() - 1, 8) << endl;
	cout << binSrch(v, 0, v.size() - 1, 9) << endl;
	cout << binSrch(v, 0, v.size() - 1, 10) << endl;
	cout << binSrch(v, 0, v.size() - 1, 11) << endl;
	cout << binSrch(v, 0, v.size() - 1, 17) << endl;
	cout << binSrch(v, 0, v.size() - 1, 111) << endl;
	cout << binSrch(v, 0, v.size() - 1, 5303) << endl;


	cin >> x;
	return 0;
}

int binSrch(vector<int> v, int s, int f, int n) {
	int m = ((f + s) / 2);
	if (n == v[m]) {
		return m;
	} else if (f <= s) {
		return -1;
	} else if (n < v[m]) {
		return binSrch(v, s, m , n);
	}
	else if (n > v[m]) {
		return binSrch(v, m + 1, f, n);
	} 
}
