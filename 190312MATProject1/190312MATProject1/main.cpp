#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Rule struct
struct rule {
	string ruleString;
	bool u = false;
	bool v = false;
	bool w = false;
	bool x = false;
	bool y = false;
	bool z = false;
};

//Possible letters
char variableChars[6] = { 'u', 'v', 'w', 'x', 'y', 'z'};

void generateStrings(string base, string recursion, int loops);
vector<string> recursiveStep(vector<rule> rules, vector<string> validStrings, int loops);
vector<rule> splitUpRules(string recursion);
vector<rule> analyseRules(vector<rule> rules);
string replaceRule(rule r, char c, string s);
string trim(const string& str);
bool containsLetter(string str, char c);
vector<string> replaceAllRules(rule r, char c, vector<string> validStrings, vector<string> foundStrings);
vector<string> replaceAllRules2(string ruleText, int varCharNo, vector<string> validStrings);
string replaceRule2(string r, char cChar, string s);

int main()
{
	int x;
	//Variables for user input
	string base;
	string recursion;
	int loops;

	//Request user input
	cout << "Input base, type 'NULL' for a null base\n";
	getline(cin, base);
	if (base == "NULL") base = "";
	cout << "Input recursion rules, separate each with a comma\n";
	getline(cin, recursion);
	cout << "Input N (no. of recursions)\n";
	cin >> loops;

	//Run the function
	generateStrings(base, recursion, loops);

	cout << "Exit?\n";
	cin >> x;
	return 0;
}

void generateStrings(string base, string recursion, int loops) {
	vector<rule> rules = splitUpRules(recursion);		//This holds the separate rules
	rules = analyseRules(rules);						//Checks which variables are present to avoid wasting resources later
	vector<string> validStrings;						//This holds all the output strings
	validStrings.push_back(base);

	validStrings = recursiveStep(rules, validStrings, loops);		//Get the valid strings
}

//The application of the given rules
vector<string> recursiveStep(vector<rule> rules, vector<string> validStrings, int loops) {
	vector<string> protoStrings;			//Holds the strings during the replacing segment
	vector<string> protoStrings2;			//Same as above
	vector<string> precheckedStrings;		//Holds all new strings generated regardless of duplicates
	for (int k = 0; k < loops; k++) {				//For each desired loop
		cout << "Loop " << k + 1 << ": ";
		for (int j = 0; j < rules.size(); j++)		//For each rule
		{
			//Apply each valid string to the current rule, replacing 'u'
			protoStrings = replaceAllRules2(rules[j].ruleString, 0, validStrings);

			/*Kick it off with u, variableLetters[0], then go down the rabbit hole until z*/

			//Get rid of duplicates
			
			for (int i = 0; i < protoStrings.size(); i++) {
				if (!(find(precheckedStrings.begin(), precheckedStrings.end(), protoStrings[i]) != precheckedStrings.end())) {
					precheckedStrings.push_back(protoStrings[i]);					//Append the aux vector to the protoStrings
					cout << protoStrings[i] << " ";
				}
			}
		//	precheckedStrings.insert(precheckedStrings.end(), protoStrings.begin(), protoStrings.end());	//All strings including dupes
		}
		cout << "\n";

		validStrings.insert(validStrings.end(), precheckedStrings.begin(), precheckedStrings.end());		//Transfer valid strings from step to main vector
		precheckedStrings.clear();
		//cout << "START ";
		//for (int i = 0; i < validStrings.size(); i++) {
		//	cout << validStrings[i] << " ";
		//	//Push each replaced string in to protoStrings
		//}
		//cout << "END" << endl;
		//validStrings = protoStrings;
		//validStrings.push_back("");
	}
	return protoStrings;
}

//Recursively replaces all letters
vector<string> replaceAllRules2(string ruleText, int varCharNo, vector<string> validStrings) {
	vector<string> protoStrings;		//To hold strings
	//Base case, once all replacements have been made
	if (varCharNo > 5) {
		protoStrings.push_back(ruleText);
		return protoStrings;
	}

	vector<string> aux;	//Holds strings to make vector copy syntax easier

	for (int i = 0; i < validStrings.size(); i++) {
		//Generate a string
		string proposedString = replaceRule2(ruleText, variableChars[varCharNo], validStrings[i]);
		//If it isn't one we already have
		if (!(find(validStrings.begin(), validStrings.end(), proposedString) != validStrings.end()) /*&&
			!(find(foundStrings.begin(), foundStrings.end(), proposedString) != foundStrings.end())*/) {
			aux = replaceAllRules2(proposedString, varCharNo + 1, validStrings);	//Run the function replacing the next letter
			protoStrings.insert(protoStrings.end(), aux.begin(), aux.end());					//Append the aux vector to the protoStrings
		}
	}
	return protoStrings;
}

//Replace characters in a rule with a given character
string replaceRule2(string r, char cChar, string s) {
	//Thanks https://stackoverflow.com/questions/10030626/replace-char-in-string-with-some-string-inplace
	string c(1, cChar);
	string ruleText = r;
	for (int pos = 0;
		(pos = ruleText.find(c, pos)) != std::string::npos;
		pos += s.length())
	{
		ruleText.replace(pos, c.length(), s);
	}
	return ruleText;
}

//Runs a loop to replace a character with all valid strings
vector<string> replaceAllRules(rule r, char c, vector<string> validStrings, vector<string> foundStrings) {
	vector<string> protoStrings;
	for (int i = 0; i < validStrings.size(); i++) {
		//Generate a string
		string proposedString = replaceRule(r, c, validStrings[i]);
		//cout << endl << proposedString << " " << c << endl;
		//If it isn't one we already have
		if (!(find(validStrings.begin(), validStrings.end(), proposedString) != validStrings.end()) &&
			!(find(foundStrings.begin(), foundStrings.end(), proposedString) != foundStrings.end())) {
			protoStrings.push_back(replaceRule(r, c, validStrings[i]));	//Push it in
		}
	}
	return protoStrings;
}

//Replace characters in a rule with a given character
string replaceRule(rule r, char cChar, string s) {
	//Thanks https://stackoverflow.com/questions/10030626/replace-char-in-string-with-some-string-inplace
	string c(1, cChar);
	string ruleText = r.ruleString;
	for (int pos = 0;
		(pos = ruleText.find(c, pos)) != std::string::npos;
		pos += s.length())
	{
		ruleText.replace(pos, c.length(), s);
	}
	return ruleText;
}

//Check which variable names each rule contains
vector<rule> analyseRules(vector<rule> rules) {
	for (int i = 0; i < rules.size(); i++) {
		if (containsLetter(rules[i].ruleString, 'u'))
			rules[i].u = true;
		if (containsLetter(rules[i].ruleString, 'v'))
			rules[i].v = true;
		if (containsLetter(rules[i].ruleString, 'w'))
			rules[i].w = true;
		if (containsLetter(rules[i].ruleString, 'x'))
			rules[i].x = true;
		if (containsLetter(rules[i].ruleString, 'y'))
			rules[i].y = true;
		if (containsLetter(rules[i].ruleString, 'z'))
			rules[i].z = true;
	}
	return rules;
}

//Returns true if the string contains the char
bool containsLetter(string str, char c) {
	if (str.find(c) != std::string::npos) return true; else return false;
}

//Splits the rules given in to several vector elements
vector<rule> splitUpRules(string recursion) {
	//Thanks https://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
	stringstream ss(recursion);
	vector<rule> result;		//Vector of rules to be returned
	int i = 0;

	while (ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		substr = trim(substr);			//Get the rule string
		rule temp;						//Get a new rule
		result.push_back(temp);			//Push the new rule in
		result[i].ruleString = substr;	//Change the rules ruleString to the obtained string
		i++;
	}
	return result;
}

//Trims whitespace, thanks https://stackoverflow.com/questions/25829143/trim-whitespace-from-a-string/25829178
string trim(const string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}