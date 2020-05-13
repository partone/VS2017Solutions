#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>

using namespace std;

void printIntVector(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int getBinDigits(int n) {
	int digits = 0;
	while (n != 0) {
		digits++;
		n >>= 1;
	}
	return digits;
}

bool getBit(int n, int b) {
	return n & (1 << b);
}

int setBit(int n, int b) {
	return n | 1 << b;
}

int clearBit(int n, int b) {
	return n & ~(1 << b);
}

int toggleBit(int n, int b) {
	return getBit(n, b) ? clearBit(n, b) : setBit(n, b);
}

void printInBinary(int n) {
	while (n != 0) {
		cout << (n & 1);
		n >>= 1;
	}
	cout << endl;
}

int insertBinary(int m, int n, int i, int j) {
	for (int k = i; k <= j; k++) {
		m = clearBit(m, k);
	}
	n = n << i;
	return m | n;
}

void asBinary(float n) {
	string result ="0.";
	int i;
	for (i = 0; i < 32; i++) {
		n *= 2;
		if (n == 0) {
			i = 64;
		}
		else if (n >= 1) {
			n -= 1;
			result += "1";
		}
		else {
			result += "0";
		}
	}

	if (i == 64) cout << result << endl; else cout << "ERROR" << endl;
}

void largestToggleNumber(int n) {
	bool toggleZero = 0;
	bool toggledOne = 0;
	int iCounter = 0;
	for (int i = getBinDigits(n) - 1; i >= 0; i--) {
		if (getBit(n, i)) iCounter++;

		if (!getBit(n, i) && !toggleZero) {
			n = toggleBit(n, i);
			toggleZero = 1;
		} else if (getBit(n, i) && toggleZero) {
			n = toggleBit(n, i);
			toggledOne = 1;
			i = -1;
		}
	}

	if (!toggledOne) {
		n = pow(2, getBinDigits(n));
		for (int i = 0; i < iCounter - 1; i++) {
			n = setBit(n, i);
		}
	}
	cout << "Largest: ";
	printInBinary(n);
}

void smallestToggleNumber(int n) {
	bool toggleZero = 0;
	bool toggledOne = 0;
	int iCounter = 1;
	for (int i = 0; i < getBinDigits(n) - 1; i++) {
		if (getBit(n, i)) iCounter++;

		if (!getBit(n, i) && !toggleZero) {
			n = setBit(n, i);
			toggleZero = 1;
		}
		else if (getBit(n, i) && toggleZero) {
			n = clearBit(n, i);
			i = INT16_MAX;
			toggledOne = 1;
		}
	}

	if (!toggledOne) {
		int oldDig = getBinDigits(n) - 1;
		n = pow(2, iCounter) - 1;
		n = n << (oldDig - iCounter);
	}
	
	cout << "Smallest: ";
	printInBinary(n);
}

void smallestAndBiggestToggleNumber(int n) {
	smallestToggleNumber(n);
	largestToggleNumber(n);
}

int bitSwaps(int x, int y) {
	printInBinary(x);
	printInBinary(y);
	int swaps = 0;
	int result = x ^ y;
	for (result; result != 0; result = result >> 1) {
		if(result & 1) swaps++;
	}

	return swaps;
}

int howManyStepsRec(int remainder, int maxStepCount) {
	return 1;
}

int howManySteps(int steps, int maxStepCount) {
	int counter = 0;
	for (int i = 1; i < maxStepCount + 1; i++) {
		counter += howManyStepsRec(steps - i, maxStepCount);
	}
	return counter;
}

bool intersects(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	float m1 = (y2 - y1) / (x2 - x1);
	float m2 = (y4 - y3) / (x4 - x3);
	float m3 = (y3 - y4) / (x3 - x4);

	if (m1 == m2 || m3 == m1) return false;

	float b1 = y2 - (m1 * x2);
	float b2 = y4 - (m2 * x4);

	float x = (b2 - b1) / (m1 - m2);

	float y = (m1 * x) + b1;

	if (min(x1, x2) < x && max(x1, x2) > x && min(x3, x4) < x && max(x1, x2) > x) return true; else return false;
}

int trailingFactorialZeros(int n) {
	return floor(n / 5);
}

int smallestDifference(vector<int> v, vector<int> w) {
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());

	int i = 0;
	int j = 0;
	int smallestDifference = INT16_MAX;
	
	while (i < v.size() && j < w.size()) {
		if (abs(v[i] - w[j]) < smallestDifference) smallestDifference = abs(v[i] - w[j]);

		if (v[i] > w[j]) j++; else i++;
	}

	return smallestDifference;
}

/*
vector<int> v = { 1, 2, 3, 11, 15 };
vector<int> w = { 8, 19, 23, 127, 235 };

i					0	1	2	3	3	4	5
j					0	0	0	0	1	1	
v[i]				1	2	3	11	11	15	
w[j]				8	8	8	8	19	19	
smallestDifference	inf	7	6	3	3	3	
*/

int subtract(int a, int b) {
	for (int i = 0; i < abs(b); i++) {
		b > 0 ? a += -1 : a += 1;
	}
	return a;
}

int multiply(int a, int b) {
	int result = 0;
	for (int i = 0; i < abs(b); i++) {
		b > 0 ? result += a : result = subtract(result, a);
	}
	return result;
}

int multiply(float a, float b) {
	int result = 0;
	for (int i = 0; i < abs(b); i++) {
		b > 0 ? result += a : result = subtract(result, a);
	}
	return result;
}

int divide(int a, int b) {
	int counter = 0;
	float multiplication = 0;
	while (abs(multiplication) != abs(a)) {
		multiplication += abs(b);
		counter++;
	}
	return multiply(a, b) > 0 ? counter : multiply(counter, -1);
}

unordered_set <char> getHits(string guess, string solution) {
	unordered_set<char> hits;
	int counter = 0;
	for (int i = 0; i < solution.length(); i++) {
		if (guess[i] == solution[i]) {
			hits.insert(guess[i]);
			counter++;
		}
	}
	cout << counter << " hits" << endl;
	return hits;
}

void pseudoHits(unordered_set<char> solutionSet, unordered_set<char> solutionHitSet, string guess) {
	int counter = 0;
	for (int i = 0; i < guess.length(); i++) {
		if (solutionSet.find(guess[i]) != solutionSet.end() && solutionHitSet.find(guess[i]) == solutionHitSet.end()) {
			counter++;
		}
	}
	cout << counter << " psuedo-hits" << endl;
}

void mastermind(string guess, string solution) {
	int hits = 0;
	int psuedohits = 0;
	unordered_set <char> solutionSet;

	for (int i = 0; i < solution.length(); i++) solutionSet.insert(solution[i]);

	unordered_set <char> solutionHitSet = getHits(guess, solution);
	pseudoHits(solutionSet, solutionHitSet, guess);
}

int findUnsortedRangeStart(vector<int> v) {
	int counter = 0;
	int current = v[counter];
	int prev = INT16_MIN;
	while (current >= prev && counter < v.size()) {
		prev = current;
		counter++;
		current = v[counter];
	}
	return counter;
}

int findUnsortedRangeEnd(vector<int> v) {
	int counter = v.size() - 1;
	int current = v[counter];
	int prev = INT16_MAX;
	while (current <= prev && counter >= 0) {
		prev = current;
		counter--;
		current = v[counter];
	}
	return counter;
}

int findPositionLeft(int n, vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= n) {
			return i;
		}
	}
}

int findPositionRight(int n, vector<int> v) {
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] < n) {
			return i;
		}
	}
}
void findUnsortedRange(vector<int> v) {
	//Find the unsorted range
	int unsortedRangeStart = findUnsortedRangeStart(v);
	int unsortedRangeEnd = findUnsortedRangeEnd(v) + 1;
	if (unsortedRangeEnd == 0) {
		cout << "The vector is sorted" << endl;
		return;
	}

	int minUnsorted = *min_element(v.begin() + unsortedRangeStart, v.begin() + unsortedRangeEnd);
	int maxUnsorted = *max_element(v.begin() + unsortedRangeStart, v.begin() + unsortedRangeEnd);

	cout << "(" << findPositionLeft(minUnsorted, v) << ", " << findPositionRight(maxUnsorted, v) << ")" << endl;
	return;
}

/*
input			{2, -8, 3, -2, 4, 5, -10, 3}
maxCollection	2		2	2	3	3,-2	3,-2,4	3,-2,4,5
curCollection	2		2	-	3	3,-2	3,-2,4	3,-2,4,5
maxSum			-inf	2	2	3	3		5		
curSum			0		2	0	3	1		5
i				0		1		2	3		4			5
v[i]			2		-8		3	-2		4
*/

vector<int> largestContiguousSet(vector<int> v) {
	vector<int> maxCollection;
	vector<int> curCollection;
	int maxSum = INT16_MIN;
	int curSum = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= 0) {
			curCollection.push_back(v[i]);
			curSum += v[i];
		}
		else {
			if (v[i] + curSum < 0) {
				curSum = 0;
				curCollection.clear();
			}
			else {
				curCollection.push_back(v[i]);
				curSum += v[i];
			}
		}
		if (curSum > maxSum) {
			maxSum = curSum;
			maxCollection = curCollection;
		}
	}

	return maxCollection;
}

string buildStringFromPattern(string a, string b, string pattern) {
	string result;
	for(int i = 0; i < pattern.length(); i++) {
		if (pattern[i] == 'a')
			result += a;
		else
			result += b;
	}
	return result;
}

/*
bool validStringPattern(string pattern, string value) {
	string a;
	string b;
	int aCount;
	int bCount;

	for (int i = 0; i < pattern.length(); i++) {
		if (pattern[i] == 'a')
			aCount++;
		else
			bCount++;
	}

	switch (pattern[0]) {
	case 'a':

		break;
	case 'b':

		break;
	}
}

typedef struct coord {
	int x;
	int y;
} coord;


unordered_set <coord> searchForPond(coord tile, vector<vector<int>> land, unordered_set<coord> visited) {
	visited.insert(tile);
	queue<coord> toCheck;

	toCheck.push(tile);
	int counter = 0;

	while (!toCheck.empty()) {
		coord currentTile = toCheck.front();
		toCheck.pop();
		
		for (int x = currentTile.x - 1; x < currentTile.x + 2; x++) {
			for (int y = currentTile.y - 1; y < currentTile.x + 2; y++) {
				if (x >= 0 && x < land.size() && y >= 0 && y < land[0].size()) {
					coord checkingTile{ x, y };
					if (land[x][y] == 0 && visited.find(checkingTile) == visited.end()) {
						visited.insert(checkingTile);
						toCheck.push(checkingTile);
						counter++;
					}
				}
			}
		}
	}
	cout << counter << " ";
	return visited;
}

void findPonds(vector<vector<int>> land) {
	unordered_set <coord> visited;
	
	for (int x = 0; x < land.size(); x++) {
		for (int y = 0; y < land[0].size(); y++) {
			coord currentTile;
			currentTile.x = x;
			currentTile.y = y;
			if (land[x][y] == 0 && visited.find(currentTile) == visited.end()) {
				visited = searchForPond(currentTile, land, visited);
			}
		}
	}

	cout << endl;
}
*/

void findNumbersToSwap(vector<int> v, vector<int> w) {
	int sumV = 0;
	int sumW = 0;

	for (int i = 0; i < v.size(); i++) {
		sumV += v[i];
	}

	for (int i = 0; i < w.size(); i++) {
		sumW += w[i];
	}

	int halfDifference = (sumW - sumV) / 2;

	for (int i = 0; i < w.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (w[i] - v[j] == halfDifference) {
				cout << "Swap " << w[i] << " " << v[j] << endl;
				return;
			}
		}
	}

	cout << "No valid swap" << endl;
	return;
}

queue<string> queueizeEq(string e) {
	bool lastCharWasNum = 0;
	string substringOfE = "";
	queue<string> result;

	for (int i = 0; i < e.length(); i++) {
		if (e[i] == '+' || e[i] == '-' || e[i] == '/' || e[i] == '*') {
			result.push(substringOfE);
			substringOfE = "";

			string tmp;
			tmp = e[i];
			result.push(tmp);
			lastCharWasNum = 0;
		}
		else {
			if (lastCharWasNum) {
				substringOfE += e[i];
			}
			else {
				substringOfE = e[i];
			}
			lastCharWasNum = 1;
		}
	}

	result.push(substringOfE);

	return result;
}

queue<string> solveMultiplication(queue<string> e) {
	queue<string> result;
	string currentChar;

	float subResult;
	int firstNumber = NULL;
	int secondNumber = NULL;
	string arithmeticOperator;

	while (!e.empty()) {
		currentChar = e.front();
		e.pop();
		
		if (currentChar == "/" || currentChar == "*") {
			arithmeticOperator = currentChar;
		} else if (currentChar != "+" && currentChar != "-") {
			if (firstNumber == NULL) {
				firstNumber = stoi(currentChar);
			} else {
				secondNumber = stoi(currentChar);
				if (arithmeticOperator == "*") {
					subResult = firstNumber * secondNumber;
				}
				else {
					subResult = firstNumber / secondNumber;
				}
				result.push(to_string(subResult));
				firstNumber = NULL;
				secondNumber = NULL;
			}
		}

	}

	return result;
}

float computeEquation(string e) {
	float result;

	queue<string> equation = queueizeEq(e);

	equation = solveMultiplication(equation);

	while(!equation.empty()) {
		cout << equation.front() << " ";
		equations.pop();
	}
	cout << endl;
	return 1;
}

void main() {
	int x = 21;
	int y = 30;

	/*
	cout << x << " = ";
	printInBinary(x);
	printInBinary(setBit(x, 1));
	printInBinary(clearBit(x, 2));
	*/

	/*
	printInBinary(insertBinary(100, 5, 2, 4));
	*/

	/*
	asBinary(.375);
	asBinary(.7);
	*/

	/*
	smallestAndBiggestToggleNumber(19);
	*/

	/*
	cout << bitSwaps(x, y) << endl;
	*/

	/*
	cout << howManySteps(10, 3) << endl;
	*/

	/*
	cout << intersects(2, 2, 0, 0, 0, 1, 1, 0) << endl;
	cout << intersects(2, 2, 0, 0, 0, 1, 2, 3) << endl;
	*/

	/*
	cout << trailingFactorialZeros(0) << " " << trailingFactorialZeros(6) << " " << trailingFactorialZeros(14) << " " << trailingFactorialZeros(15) << endl;
	*/

	/*
	vector<int> v = { 1, 3, 15, 11, 2, 234, 19 };
	vector<int> w = { 23, 127, 235, 19, 8 };
	cout << smallestDifference(v, w) << endl;
	*/

	/*
	cout << subtract(8, 3) << " " << subtract(8, 10) << " " << subtract(0, 0) << " " << subtract(-3, 3) << " " << subtract(-3, -3) << endl;
	cout << multiply(5, 5) << " " << multiply(0, 1) << " " << multiply(5, -5) << " " << multiply(-5, -5) << endl;
	cout << divide(20, 5) << " " << divide(-20, 5) << " " << divide(-20, -5) << endl;
	*/

	/*
	mastermind("RGBY", "GGRR");
	*/

	/*
	vector<int> unsortedVector = { 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 };
	findUnsortedRange(unsortedVector);
	*/

	/*
	vector<int> v = { 2, -8, 3, -2, 4, 5, -10, 3 };
	printIntVector(largestContiguousSet(v));
	*/

	/*
	cout << validStringPattern("aabab", "catcatgocatgo");
	*/

	/*
	vector<vector<int>> v = { {0, 2, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}, {0, 1, 0, 1} };
	findPonds(v);
	*/

	/*
	vector<int> v = { 4, 1, 2, 1, 1, 2 };
	vector<int> w = { 3, 6, 3, 3 };
	findNumbersToSwap(v, w);
	*/

	cout << computeEquation("2*3+5/6*3+15") << endl;

	cin >> x;
}