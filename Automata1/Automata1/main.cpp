#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x;
	int currentPos = 0;
	int m[3][2] = 
	{
		{0, 1},
		{0, 2},
		{2, 2}
	};

	string str;
	cout << "Enter a string: ";
	getline(cin, str);

	for (char& c : str) {
		switch (c) {
			case 'a':
				currentPos = m[currentPos][0];
				break;
			case 'b':
				currentPos = m[currentPos][1];
				break;
			default:
				cout << "Error\n";
		}
		cout << currentPos << endl;
	}
	if (currentPos)
		cout << "Es valido" << endl;
	else
		cout << ":(" << endl;

	cin >> x;

	return 0;
}