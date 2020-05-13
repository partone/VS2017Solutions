#include <stdlib.h>
#include <iostream>

using namespace std;

class node {
public:
	int value;
	node * next;

	node() {
		value = -1;
		next = NULL;
	}

	node(int v) {
		value = v;
		next = NULL;
	}
};

class linkedList {
public:	
	//Constructor
	linkedList() {
		head = new node();
		head->next = NULL;
		head->value = NULL;
	}

	void printList() {
		node * current = head;
		while (current->next != NULL) {
			cout << current->value << " ";
			current = current->next;
		}
		cout << current->value << " " << endl;
	}

	void insertList(int value) {
		node * current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		node * newNode = new node(value);
		current->next = newNode;
	}

	int listLength() {
		node * current = head;
		int counter = 1;
		while (current->next != NULL) {
			current = current->next;
			counter++;
		}
		return counter;
	}

	void deleteListIndex(int index) {
		if (index == 0) {
			node *tmp = head;
			head = head->next;
			free(tmp);
			return;
		}
		int counter = 0;
		node * current = head;
		while (current->next != NULL) {
			if (counter + 1 == index) {
				node * tmp = current->next;
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

	void insertListIndex(int index, int value);

private:
	node * head;
};

void linkedList::insertListIndex(int index, int value) {
	if (index == 0) {
		node *tmp = head;
		head = head->next;
		free(tmp);
		return;
	}
	int counter = 0;
	node * current = head;
	while (current->next != NULL) {
		if (counter + 1 == index) {
			node * newNode = new node(value);
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
/*
int main() {
	int x;
	linkedList the;
	the.insertList(2);
	the.insertList(3);
	the.insertList(4);
	the.insertList(6);
	the.insertList(7);
	the.printList();
	the.deleteListIndex(0);
	the.deleteListIndex(2);
	the.printList();
	cin >> x;
	return 1;
}*/