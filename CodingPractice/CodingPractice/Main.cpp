#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int value;
	node *left;
	node *right;
};

#include<iostream>
using namespace std;

class BST {
public:
	struct node {
		int data;
		node* left;
		node* right;
	};

	node* root;

	node* makeEmpty(node* t) {
		if (t == NULL)
			return NULL;
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		return NULL;
	}

	node* insert(int x, node* t)
	{
		if (t == NULL)
		{
			t = new node;
			t->data = x;
			t->left = t->right = NULL;
		}
		else if (x < t->data)
			t->left = insert(x, t->left);
		else if (x > t->data)
			t->right = insert(x, t->right);
		return t;
	}

	node* findMin(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t) {
		if (t == NULL)
			return NULL;
		else if (t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}

	node* remove(int x, node* t) {
		node* temp;
		if (t == NULL)
			return NULL;
		else if (x < t->data)
			t->left = remove(x, t->left);
		else if (x > t->data)
			t->right = remove(x, t->right);
		else if (t->left && t->right)
		{
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(t->data, t->right);
		}
		else
		{
			temp = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			delete temp;
		}

		return t;
	}

	void inorder(node* t) {
		if (t == NULL)
			return;
		inorder(t->left);
		cout << t->data << " ";
		inorder(t->right);
	}

	node* find(node* t, int x) {
		if (t == NULL)
			return NULL;
		else if (x < t->data)
			return find(t->left, x);
		else if (x > t->data)
			return find(t->right, x);
		else
			return t;
	}

public:
	BST() {
		root = NULL;
	}

	~BST() {
		root = makeEmpty(root);
	}

	void insert(int x) {
		root = insert(x, root);
	}

	void remove(int x) {
		root = remove(x, root);
	}

	void display() {
		inorder(root);
		cout << endl;
	}

	void search(int x) {
		root = find(root, x);
	}
};

typedef struct {
	int value;
	int nextSmallest;
} stackNode;

class queueOfStacks {
public:
	queueOfStacks() {
		onPush = 1;
	}

	void push(int n) {
		if (!onPush) {
			transferToPush();
		}
		pushing.push(n);
	}

	int pop() {
		if (onPush) {
			transferToPop();
		}
		int tmp = popping.top();
		popping.pop();
		return tmp;
	}

private:
	stack<int> pushing;
	stack<int> popping;
	bool onPush;

	void transferToPush() {
		while (!popping.empty()) {
			pushing.push(popping.top());
			popping.pop();
		}
		onPush = 1;
	}

	void transferToPop() {
		while (!pushing.empty()) {
			popping.push(pushing.top());
			pushing.pop();
		}
		onPush = 0;
	}
};

class stackOfStacks {
public:
	stackOfStacks() {
		stackSizeLimit = 3;
		currentStackSize = 0;
		addStack();
	}

	void push(int n) {
		mainStack.top().push(n);
		currentStackSize++;
		if (currentStackSize >= stackSizeLimit) {
			addStack();
			currentStackSize = 0;
			
		}
	}

	void pop() {
		if (mainStack.top().empty()) {
			removeStack();
		}
		mainStack.top().pop();
		currentStackSize = 3;
	}
private:
	stack<stack<int>> mainStack;
	int stackSizeLimit;
	int currentStackSize;

	void addStack() {
		stack<int> freshStack;
		mainStack.push(freshStack);
		cout << "Added a new stack" << endl;
	}

	void removeStack() {
		mainStack.pop();
		cout << "Removed an empty stack" << endl;
	}
};

class customStack {
public:
	customStack() {
		minValue = INT16_MAX;
	}

	void push(int n) {
		stackNode newNode;
		newNode.value = n;
		if (n < minValue) {
			newNode.nextSmallest = minValue;
			minValue = n;
		}
		else {
			newNode.nextSmallest = minValue;
		}
		stack.push(newNode);
	}

	void pop() {
		minValue = stack.top().nextSmallest;
		stack.pop();
	}

	int getSmallest() {
		return minValue;
	}

private:
	stack<stackNode> stack;
	int minValue;
};

class linode {
public:
	int value;
	linode * next;

	linode() {
		value = -1;
		next = NULL;
	}

	linode(int v) {
		value = v;
		next = NULL;
	}
};

class linkedList {
public:
	linode * head;

	//Constructor
	linkedList() {
		head = new linode();
		head->next = NULL;
		head->value = NULL;
	}

	void printList() {
		linode * current = head;
		while (current->next != NULL) {
			cout << current->value << " ";
			current = current->next;
		}
		cout << current->value << " " << endl;
	}

	void insertList(int value) {
		linode * current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		linode * newNode = new linode(value);
		current->next = newNode;
	}

	int listLength() {
		linode * current = head;
		int counter = 1;
		while (current->next != NULL) {
			current = current->next;
			counter++;
		}
		return counter;
	}

	void deleteListIndex(int index) {
		if (index == 0) {
			linode *tmp = head;
			head = head->next;
			free(tmp);
			return;
		}
		int counter = 0;
		linode * current = head;
		while (current->next != NULL) {
			if (counter + 1 == index) {
				linode * tmp = current->next;
				current->next = current->next->next;
				free(tmp);
				return;
			}
			else {
				counter++;
				current = current->next;
			}
		}
		return;
	}

	void insertListIndex(int index, int value) {
		if (index == 0) {
			linode *tmp = head;
			head = head->next;
			free(tmp);
			return;
		}
		int counter = 0;
		linode * current = head;
		while (current->next != NULL) {
			if (counter + 1 == index) {
				linode * newNode = new linode(value);
				newNode->next = current->next;
				current->next = newNode;
				return;
			}
			else {
				counter++;
				current = current->next;
			}
		}
		return;
	}

private:
	
};

bool uniqueWord(string s) {
	unordered_map<char, char> wordMap;
	pair<unordered_map<char, char>::iterator, bool> fail;
	for (int i = 0; i < s.length(); i++) {
		fail = wordMap.emplace(s[i], s[i]);
		if (fail.second == false) {
			return 0;
		}
	}
	return 1;
}

bool isPermutation(string x, string y) {
	if (x.length() != y.length()) return 0;

	unordered_map <char, int> letterMap;
	//Add first string to hash table
	for (int i = 0; i < x.length(); i++) {
		if (letterMap.find(x[i]) == letterMap.end())
			letterMap[x[i]] = 1;
		else
			letterMap[x[i]] += 1;
	}

	//Remove second string from hash table
	for (int i = 0; i < y.length(); i++) {
		if (letterMap.find(y[i]) == letterMap.end()) {
			return 0;
		}
		else {
			letterMap.at(y[i]) -= 1;
			if (!letterMap.at(y[i])) letterMap.erase(y[i]);
		}
		
	}

	if (letterMap.empty()) return 1; else return 0;
}

void urlify(char s[], int len) {
	int finalLen = 18;
	int j = finalLen - 2;
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] != ' ') {
			s[j] = s[i];
			j--;
		}
		else {
			s[j] = '0';
			s[j - 1] = '2';
			s[j - 2] = '%';
			j = j - 3;
		}
	}
}

bool palinPerm(string x) {
	unordered_map<char, int> letterCounter;
	int illegalMoves = 0;
	for (int i = 0; i < x.length(); i++) {
		if (letterCounter.find(x[i]) == letterCounter.end()) {
			letterCounter[x[i]] = 1;
			illegalMoves++;
		}
		else {
			letterCounter[x[i]]++;
			if (letterCounter[x[i]] % 2 == 0) {
				illegalMoves--;
			}
			else {
				illegalMoves++;
			}
		}
	}

	if (illegalMoves > 1) {
		return 0;
	}
	return 1;
}

bool oneAway(string x, string y){
	if (x == y) return 1;
	int lenX = x.length();
	int lenY = y.length();
	int lenDiff;
	/*
	0 = same length
	1 = x is longer
	2 = y is longer
	*/

	if (lenX == lenY) {
		lenDiff = 0;
	}
	else if (lenX > lenY) {
		lenDiff = 1;
	}
	else {
		lenDiff = 2;
	}

	int mistakeCounter = 0;
	int i = 0;
	int j = 0;

	for (int i = 0; i < lenX; i++) {
		//Same letter
		if (x[i] == y[j]) {
			i++;
			j++;
		}
		//Different letters
		else {
			mistakeCounter++;
			if (mistakeCounter > 1) return 0;

			switch (lenDiff) {
			case 0:
				i++;
				j++;
				break;
			case 1:
				i++;
				break;
			case 2:
				j++;
				break;
			default:
				"Error on lenDiff\n";
			}
		}
	}
	return 1;
}

string compress(string s) {
	string result = "";
	int charCounter = 0;
	char current;
	char last = s[0];
	char i;
	for (int i = 0; i < s.length(); i++) {
		current = s[i];
		if (current != last) {
			result += last;
			result += to_string(charCounter);
			charCounter = 1;
		}
		else {
			charCounter++;
		}
		last = current;
	}
	result += last;
	result += to_string(charCounter);
	if (result.length() > s.length()) return s;
	return result;
}

vector<vector<int>> zeroMatrix(vector<vector<int>> M) {
	int r = M.size();
	int c = M[0].size();
	int zerozero = 0;
	if (M[0][0] == 0) zerozero = 1;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (M[i][j] == 0) {
				M[i][0] = 0;
				M[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < r; i++) {
		if (M[i][0] == 0) {
			for (int j = 0; j < c; j++) {
				M[i][j] = 0;
			}
		}
	}
	
	for (int j = 1; j < c; j++) {
		if (M[0][j] == 0) {
			for (int i = 0; i < r; i++) {
				M[i][j] = 0;
			}
		}
	}
	
	if (zerozero) {
		for (int i = 0; i < r; i++) {
			M[i][0] = 0;
		}
		for (int j = 0; j < c; j++) {
			M[0][j] = 0;
		}
	}
	
	return M;
}

void printMatrix(vector<vector<int>> M) {
	for (int i = 0; i < M.size(); i++) {
		for (int j = 0; j < M[i].size(); j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

linkedList removeDupesLL(linkedList L) {
	unordered_set<int> valueCounter;
	linode * currentNode = L.head;
	linode * lastNode;
	valueCounter.insert(currentNode->value);
	
	while (currentNode->next != NULL) {
		lastNode = currentNode;
		currentNode = currentNode->next;
		if (valueCounter.find(currentNode->value) != valueCounter.end()) {
			lastNode->next = currentNode->next;
			currentNode = lastNode;
		}
		else {
			valueCounter.insert(currentNode->value);
		}
	}
	return L;
}

typedef struct {
	int fromLast;
	int answer;
} fromLastAnswer;

fromLastAnswer kthToLastRec(linode * N, int n) {
	fromLastAnswer result;
	if (N->next == NULL) {
		if (n == 0) {
			result.answer = N->value;
		}
		else {
			result.answer = -1;
			result.fromLast = 1;
		}
	}
	else {
		result = kthToLastRec(N->next, n);
		if (n == result.fromLast) {
			result.answer = N->value;
		}
		result.fromLast++;
	}
	return result;
}

int kthToLast(linkedList L, int n) {
	fromLastAnswer result;
	result = kthToLastRec(L.head, n);
	return result.answer;
}

linode * getNode(linkedList L, int index) {
	linode * current = L.head;
	for (int i = 0; i < index; i++) {
		if (current->next == NULL) return current;
		current = current->next;
	}
	return current;
}

linkedList removeNode(linkedList L, int index) {
	linode * current = getNode(L, index);
	current->value = current->next->value;
	current->next = current->next->next;
	return L;
}

linkedList partition(linkedList L, int partitionValue) {
	linode * previousNode = L.head;
	linode * currentNode = L.head->next;

	while (currentNode->next != NULL) {
		if (currentNode->value < partitionValue) {
			//Add new head
			linode * newHead = new linode(currentNode->value);
			newHead->next = L.head;
			L.head = newHead;

			//Remove moved node
			previousNode->next = currentNode->next;
		}
		else {
			previousNode = currentNode;
		}
		currentNode = currentNode->next;
	}

	if (currentNode->value < partitionValue) {
		//Add new head
		linode * newHead = new linode(currentNode->value);
		newHead->next = L.head;
		L.head = newHead;

		previousNode->next = NULL;
	}

	return L;
}

int sumLists(linkedList L1, linkedList L2) {
	linode * current1 = L1.head;
	linode * current2 = L2.head;
	int magnitude = 1;
	int total = 0;
	int subtotal;
	int remainder = 0;
	while (current1 != NULL || current2 != NULL) {
		int int1 = current1 ? current1->value : 0;
		int int2 = current2 ? current2->value : 0;
		subtotal = int1 + int2 + remainder;
		remainder = 0;
		if (subtotal > 9) {
			remainder = 1;
			subtotal -= 10;
		}
		total += subtotal * magnitude;
		current1 = current1 ? current1->next : NULL;
		current2 = current2 ? current2->next : NULL;
		magnitude *= 10;
	}
	if (remainder == 1) total += magnitude;

	return total;
}

int getListLength(linkedList L) {
	linode * currentNode = L.head;
	int length = 1;
	while (currentNode != NULL) {
		currentNode = currentNode->next;
		length++;
	}
	return length;
}

bool palinList(linkedList L) {
	L.printList();
	linode * currentNode = L.head;
	stack<int> palindrome;
	int length = getListLength(L);
	int odd = 0;
	length % 2 ? odd = 0 : odd = 1;

	for (int i = 0; i < (length - odd) / 2; i++) {
		palindrome.push(currentNode->value);
		currentNode = currentNode->next;
	}

	if (odd) currentNode = currentNode->next;
	for (int i = 0; i < (length - odd) / 2; i++) {
		if (palindrome.top() == currentNode->value) {
			palindrome.pop();
			currentNode = currentNode->next;
		}
		else {
			return 0;
		}
	}
	if (palindrome.empty()) return 1;
	return 0;
}

bool isRoute(vector<vector<int>> graph, int start, int end) {
	unordered_set<int> evaluated;
	queue<int> toBeEvaluated;
	toBeEvaluated.push(start);

	while (!toBeEvaluated.empty()) {
		int currentlyChecking = toBeEvaluated.front();
		toBeEvaluated.pop();
		evaluated.insert(currentlyChecking);

		for (int i = 0; i < graph[currentlyChecking].size(); i++) {
			if (graph[currentlyChecking][i] == end) return 1;

			if (evaluated.find(graph[currentlyChecking][i]) == evaluated.end()) {
				toBeEvaluated.push(graph[currentlyChecking][i]);
			}
		}
	}
	return 0;
}

typedef struct nodeEvalStruct {
	BST::node * evalNode;
	int level;
} nodeEvalStruct;

vector<linkedList> addNodeToList(int value, int level, vector<linkedList> result) {
	if (result.size() - 1 < level) {
		linkedList newLevel;
		result.push_back(newLevel);
	}
	result[level].insertList(value);
	return result;
}

vector<linkedList> getAllDepthsAsLists(BST::node * root) {
	nodeEvalStruct rootNode;
	rootNode.evalNode = root;
	rootNode.level = 0;

	vector<linkedList> result;
	linkedList newLevel;
	result.push_back(newLevel);


	queue<nodeEvalStruct> toBeEvaluated;

	toBeEvaluated.push(rootNode);

	while (!toBeEvaluated.empty()) {
		BST::node * currentNode = toBeEvaluated.front().evalNode;
		int currentLevel = toBeEvaluated.front().level;
		result = addNodeToList(currentNode->data, currentLevel, result);
		toBeEvaluated.pop();
		cout << "Checking\t" << currentNode->data << " at " << currentLevel << endl;
		if (currentNode->left != NULL) {
			nodeEvalStruct left;
			left.level = currentLevel + 1;
			left.evalNode = currentNode->left;
			cout << "Left:\t" << left.evalNode->data << "\t" << left.level << endl;
			toBeEvaluated.push(left);
		}
		if (currentNode->right != NULL) {
			nodeEvalStruct right;
			right.level = currentLevel + 1;
			right.evalNode = currentNode->right;
			cout << "Right:\t" << right.evalNode->data << "\t" << right.level << endl;
			toBeEvaluated.push(right);
		}
	}
	return result;
}

bool isBalancedRec(BST::node * binNode, int * smallestLevel, int * largestLevel, int currentLevel) {
	bool isBalanced = 1;
	if (binNode->left == NULL && binNode->right == NULL) {
		if (*smallestLevel > currentLevel || *smallestLevel == -1) *smallestLevel = currentLevel;
		if (*largestLevel < currentLevel) *largestLevel = currentLevel;

		if (*largestLevel - *smallestLevel > 1) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (binNode->left != NULL) {
		isBalanced = isBalancedRec(binNode->left, smallestLevel, largestLevel, currentLevel + 1);
	}
	if (binNode->right != NULL) {
		isBalanced = isBalanced && isBalancedRec(binNode->right, smallestLevel, largestLevel, currentLevel + 1);
	}
	return isBalanced;
}

bool isBalanced(BST bintree) {
	int smallestLevel = -1;
	int largestLevel = -1;
	return isBalancedRec(bintree.root, &smallestLevel, &largestLevel, 0);
}

bool isBinarySearchTreeRec(BST::node * binNode, int * lastFound) {
	int isBFS = 1;
	if(binNode->left != NULL) isBFS = isBFS & isBinarySearchTreeRec(binNode->left, lastFound);
	isBFS = isBFS & (binNode->data > *lastFound ? 1 : 0);
	if (binNode->right != NULL) isBFS = isBFS & isBinarySearchTreeRec(binNode->right, lastFound);
	return isBFS;
}

bool isBinarySearchTree(BST bintree) {
	int lastFound;
	return isBinarySearchTreeRec(bintree.root, &lastFound);
}

vector<vector<char>> removeDependency(vector<vector<char>> dependencies, char builtProject) {
	vector<vector<char>> newDependencies;
	for (int i = 0; i < dependencies.size(); i++) {
		if (dependencies[i][0] != builtProject) {
			cout << "Pushed " << dependencies[i][0] << " " << dependencies[i][1] << endl;
			newDependencies.push_back(dependencies[i]);
		}
	}
	return newDependencies;
}

	void printVectorChar(vector<char> n) {
	for (int i = 0; i < n.size(); i++) {
		cout << n[i] << " ";
	}
	cout << endl;
}

void findProjectOrder(vector<char> projects, vector<vector<char>> dependencies) {
	vector<char> buildOrder;

	for (int i = 0; i < projects.size(); i++) {
		int depends = 0;
		for (int j = 0; j < dependencies.size(); j++) {
			if (projects[i] == dependencies[j][1]) {
				depends = 1;
			}
		}
		if (!depends) {
			buildOrder.push_back(projects[i]);
			dependencies = removeDependency(dependencies, projects[i]);
			projects.erase(remove(projects.begin(), projects.end(), projects[i]), projects.end());
			i = -1;
		}
	}

	if (!projects.empty()) cout << "Error!" << endl; 
	else {
		for (int i = 0; i < buildOrder.size(); i++) {
			cout << buildOrder[i] << " ";
		}
		cout << endl;
	}
}

void printVectorInt(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> findRouteRec(BST::node * currentNode, int value, vector<int> result) {
	if (currentNode == NULL) {
		return result;
	}
	if (currentNode->data == value) {
		result.push_back(currentNode->data);
		return result;
	}

	vector<int> left = findRouteRec(currentNode->left, value, result);
	vector<int> right = findRouteRec(currentNode->right, value, result);
	if (!left.empty() || !right.empty()) {
		result.push_back(currentNode->data);
	}
	result.insert(result.end(), left.begin(), left.end());
	result.insert(result.end(), right.begin(), right.end());

	return result;
}

vector<int> findRoute(BST bintree, int value) {
	vector<int> result;
	return findRouteRec(bintree.root, value, result);
}

int findCommonAncestor(BST bintree, int n1, int n2) {
	vector<int> route1 = findRoute(bintree, n1);
	vector<int> route2 = findRoute(bintree, n2);
	int last = -1;
	/*int shortestRoute = route1.size() < route2.size() ? route1.size() : route2.size();
	int i = 0;

	while (route1[i] == route2[i]) {
		last = route1[i];
		i++;
	}*/

	return last;
}

int main() {
	string x = "banjo";
	string y = "janob";
	vector<vector<int>> z{ { 1, 2, 0, 3 }, { 4, 5, 6, 6 }, { 7, 8, 9, 9 }, { 1, 1, 2, 0 }, {5, 4, 3, 2} };

	linkedList L;
	L.head->value = 3;
	L.insertList(1);
	L.insertList(2);
	L.insertList(7);
	L.insertList(3);
	L.insertList(3);
	L.insertList(7);
	L.insertList(6);
	L.insertList(6);
	L.insertList(6);
	L.insertList(6);
	L.insertList(6);
	L.insertList(2);
	L.insertList(4);
	L.insertList(5);
	L.insertList(6);
	L.insertList(6);
	L.insertList(1);
	L.insertList(2);
	L.insertList(1);

	linkedList L1;
	L1.head->value = 5;
	L1.insertList(6);
	L1.insertList(6);

	linkedList L2;
	L2.head->value = 3;
	L2.insertList(7);
	L2.insertList(6);
	L2.insertList(2);

	linkedList L3;
	L3.head->value = 3;
	L3.insertList(2);
	L3.insertList(1);
	L3.insertList(0);
	L3.insertList(0);
	L3.insertList(1);
	L3.insertList(2);
	L3.insertList(3);

	vector<vector<int>> grapho = {
		{1, 3},
		{0},
		{3, 4},
		{4},
		{2}
	};

	vector<int> sorted = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	BST binTree;
	binTree.insert(5);
	binTree.insert(8);
	binTree.insert(2);
	binTree.insert(6);
	binTree.insert(1);
	binTree.insert(3);
	binTree.insert(4);
	binTree.insert(7);
	binTree.insert(9);
	binTree.insert(997);
	binTree.insert(998);
	binTree.insert(999);

	/*cout << x << " has all unique letters: " << uniqueWord(x) << endl;
	x = "tree";
	cout << x << " has all unique letters: " << uniqueWord(x) << endl;
	*/

	/*
	cout << x << " is permutation of " << y << ": " << isPermutation(x, y) << endl;
	y = "apple";
	cout << x << " is permutation of " << y << ": " << isPermutation(x, y) << endl;
	*/

	/*
	char z[18] = { 'M', 'r', ' ', 'J', 'o', 'h', 'n', ' ', 'S', 'm', 'i', 't', 'h', ' ', ' ' , ' ', ' ', '\0' };
	cout << z << " becomes ";
	urlify(z, 13);
	cout << z << endl;
	*/

	/*
	cout << "Is " << x << " a palindrome permutation? " << palinPerm(x) << endl;
	x = "tactcoa";
	cout << "Is " << x << " a palindrome permutation? " << palinPerm(x) << endl;
	*/

	/*
	x = "pale";
	y = "ple";
	cout << "Are " << x << " and " << y << " one away? " << oneAway(x, y) << endl;

	y = "bake";
	cout << "Are " << x << " and " << y << " one away? " << oneAway(x, y) << endl;
	*/

	/*
	x = "aaaabbcccaaababcdefgh";
	cout << x << " can be compressed to " << compress(x) << endl;}
	*/

	/*
	printMatrix(z);
	z = zeroMatrix(z);
	printMatrix(z);
	*/

	/*
	L.printList();
	L = removeDupesLL(L);
	L.printList();
	*/

	/*
	L.printList();
	cout << kthToLast(L, 0) << endl;
	*/

	/*
	L.printList();
	L = removeNode(L, 3);
	L.printList();
	*/

	/*x
	L.printList();
	L = partition(L, 4);
	L.printList();
	*/

	/*
	//cout << sumLists(L1, L2) << endl;
	*/

	/*
	//cout << "List is a palindrome: " << palinList(L3) << endl;
	*/

	/*
	customStack coolStack;
	coolStack.push(5);
	cout << "My smallest number is " << coolStack.getSmallest() << endl;
	coolStack.push(2);
	cout << "My smallest number is " << coolStack.getSmallest() << endl;
	coolStack.push(3);
	cout << "My smallest number is " << coolStack.getSmallest() << endl;
	coolStack.pop();
	coolStack.push(5);
	cout << "My smallest number is " << coolStack.getSmallest() << endl;
	coolStack.pop();
	coolStack.pop();
	coolStack.pop();
	coolStack.push(1);
	cout << "My smallest number is " << coolStack.getSmallest() << endl;
	*/

	/*
	stackOfStacks coolStack2 = stackOfStacks();
	coolStack2.push(3);
	coolStack2.push(3);
	coolStack2.push(3);
	coolStack2.push(3);
	coolStack2.push(3);
	coolStack2.push(3);
	coolStack2.push(3);
	coolStack2.pop();
	coolStack2.pop();
	coolStack2.pop();
	coolStack2.pop();
	*/

	/*
	queueOfStacks Q = queueOfStacks();
	Q.push(3);
	Q.push(4);
	Q.push(3);
	Q.push(5);
	Q.push(4);
	cout << "Popped: " << Q.pop() << endl;
	cout << "Popped: " << Q.pop() << endl;
	cout << "Popped: " << Q.pop() << endl;
	cout << "Popped: " << Q.pop() << endl;
	*/

	/*
	cout << "Is there a route?:" << isRoute(grapho, 1, 4) << endl;
	cout << "Is there a route?:" << isRoute(grapho, 4, 1) << endl;
	*/

	/*
	BinaryTree sortedTree;
	sortedTree.head = createTree(sorted, 0, sorted.size() - 1);
	createTree(sorted, 0, sorted.size());
	sortedTree.printTreeDFS();
	*/

	/*
	vector<linkedList> depth = getAllDepthsAsLists(binTree.root);
	for (int i = 0; i < depth.size(); i++) {
		depth[i].printList();
	}
	*/

	/*
					5
			2				8
		1		3		6		9
				4		7
	*/

	/*
	cout << "Is balanced? " << isBalanced(binTree) << endl;
	*/

	/*
	cout << "Is binary search tree? " << isBinarySearchTree(binTree) << endl;
	*/
	
	/*
	vector<char> projects = { 'a', 'b', 'c', 'd', 'e', 'f' };
	vector<vector<char>> dependencies = { {'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'} };

	findProjectOrder(projects, dependencies);
	*/

	/*
	cout << "The common ancestor is " << findCommonAncestor(binTree, 7, 9);
	*/

	

	cin >> x;
}

