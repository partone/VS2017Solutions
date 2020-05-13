#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

typedef struct coords {
	float x;
	float y;
} coords;

void main() {
	int x;
	vector<int> pointsX;
	vector<int> pointsY;
	vector<string> pointsStr;
	vector<coords> points;
	vector<coords> pointsChecked;

	//Get the stuff from the file
	string line;
	ifstream myfile("coordenadas.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//Push the found points in to a vector
			pointsStr.push_back(line);

		}
		myfile.close();
	} else cout << "Unable to open file";

	//Split points strings
	for (int i = 0; i < pointsStr.size(); i++) {
		string buf;                 // Have a buffer string
		stringstream ss(pointsStr[i]);       // Insert the string into a stream

		coords tmp;

		while (ss >> buf) {
			tmp.x = stoi(buf);
			pointsX.push_back(stoi(buf));
			ss >> buf;
			tmp.y = stoi(buf);
			pointsY.push_back(stoi(buf));
			points.push_back(tmp);
		}
	}


	//Sort the coodinates by x
	sort(pointsX.begin(), pointsX.end());

	//Reconstruct the points vector with this new sort
	vector<coords> tmpHolder;
	int lookFor;

	for (int i = 0; i < pointsX.size(); i++) {
		lookFor = pointsX[i];
		for (int j = 0; j < points.size(); j++) {
			if (points[j].x == lookFor) {
				coords tmp;
				tmp.x = points[j].x;
				tmp.y = points[j].y;
				tmpHolder.push_back(tmp);
				points.erase(points.begin() + j);
			}
		}
	}
	points = tmpHolder;

	//Loop through the points backwards, summing up the areas
	int lastX;
	int lastY = 0;
	int total;
	//Initialise total
	total = points[points.size() - 1].x * points[points.size() - 1].y;
	lastX = points[points.size() - 1].x;
	lastY = points[points.size() - 1].y;
	//For the penultimate total
	for (int k = points.size() - 2; k >= 0; k--) {
		//If there's a larger Y
		if (points[k].y > lastY) {
			total += abs(points[k].x) * (abs(points[k].y) - lastY);		//Add x times the difference in Y
			lastY = points[k].y;
		}
	}

	cout << total;
	cin >> x;
	return;
}