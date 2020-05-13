#include <vector>
#include <iostream> 
#include <iterator> 
#include <map> 
#include <math.h>
#include <string>

using namespace std;

int sockMerchant(int n, vector<int> ar);
int countingValleys(int n, string s);
int jumpingOnClouds(vector<int> c);
long repeatedString(string s, long n);
int hourglassSum(vector<vector<int>> arr);

void main() {
	/*vector<int> test = { 1, 1, 3, 1 ,2 ,1 ,3 ,3 ,3 ,3 };
	int n = 10;
	cout << sockMerchant(9, test) << endl;
	cin >> n;

	int n = 8;
	string path = "UDDDUDUU";
	cout << countingValleys(n, path) << endl;

	int n;
	vector<int> clouds = { 0, 0, 0, 0, 1, 0 };
	cout << jumpingOnClouds(clouds) << endl;*/

	int n;

	vector<vector<int>> arr = {
	{1, 1, 1, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{1, 1, 1, 0, 0, 0},
	{0, 9, 2, -4, -4, 0},
	{0, 0, 0, -2, 0, 0},
	{0, 0, -1, -2, -4, 0 } };
	cout << hourglassSum(arr) << endl;
	cin >> n;
}

int hourglassSum(vector<vector<int>> arr) {
	int largestHour = INT16_MIN;
	int currentHour = 0;
	for (int i = 0; i < arr.size() - 2; i++) {
		for (int j = 0; j < arr[i].size() - 2; j++) {
			//If the top row is complete, check the other pieces
			currentHour = arr[i][j] + arr[i][j + 1] + arr [i][j + 2] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2] + arr[i + 1][j + 1];
			if (currentHour > largestHour) largestHour = currentHour;
		}
	}
	return largestHour;
}

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
	long aCount = 0;
	//Get how many 'a's in the string
	for (long i = 0; i < s.size(); i++) {
		if (s[i] == 'a')
			aCount++;
	}

	//Get how many time the string will repeat and the remainder
	long repeats = floor(n / s.size());
	long remainder = n % s.size();

	long aTotal = repeats * aCount;

	for (long i = 0; i < remainder; i++) {
		if (s[i] == 'a')
			aTotal++;
	}

	return aTotal;
}

int countingValleys(int n, string s) {
	int currentLevel = 0;
	int valleys = 0;
	char currentLetter;

	//Traverse the route
	for (int i = 0; i < n; i++) {
		currentLetter = s[i];
		if (currentLetter == 'U') {
			currentLevel++;
		}
		else {
			currentLevel--;
		}

		if (currentLetter == 'U' && currentLevel == 0) {
			valleys++;
		}
	}
	return valleys;
}

int jumpingOnClouds(vector<int> c) {
	int numberOfClouds = c.size();
	int jumps = 0;
	int currentCloud = 0;

	//Until the game is won
	while (currentCloud != numberOfClouds - 1) {
		if (currentCloud + 2 < numberOfClouds && c[currentCloud + 2] == 0) currentCloud += 2;
		else currentCloud += 1;
		jumps++;
	}
	return jumps;
}

int sockMerchant(int n, vector<int> ar) {
	map<int, int> pairs;
	map<int, int>::iterator it;
	//For each sock
	for (int i = 0; i < n; i++) {
		//See if it's been mapped
		it = pairs.find(ar[i]);

		//If it hasn't, create a new entry
		if (it != pairs.end()) {
			//else increment the map by one
			it->second = it->second++;
		}
		else {
			pairs.insert(pair<int, int>(ar[i], 1));
		}
	}

	int total = 0;
	for (it = pairs.begin(); it != pairs.end(); it++) {
		total += floor(it->second / 2);
	}
	return total;
}