/*
Name: Muhammad Ahmad
Roll: BCSF19M509
*/

#include <iostream>

using namespace std;

class Node {
public:
	Node *next;
	int data;
	Node (int d) {
		data = d;
		next = NULL;
	}
};
class LinkedList {
	Node *first, *last;
public:
	LinkedList() {
		first = new Node(0);
		last = NULL;
	}
	void addNodeAtStart(int d) {
		Node *newNode = new Node(d);
		newNode -> next = first -> next;
		first -> next = newNode;
		if (last == NULL)	last = newNode;
	}
	Node* addInOrder(int d, Node *t) {
		if ( t == NULL || t->data > d) {
			if (t == NULL) {
				last = new Node(d);
				return last;
			}
			Node *newNode  = new Node(d);
			newNode -> next = t;
			return newNode;
		}
		else
			t -> next = addInOrder(d, t->next);
		return t;
	}
	void addInOrder(int d) {
		first -> next = addInOrder(d, first->next);
	}
	Node* deleteNode(int d, Node* t) {
		if (t == NULL)   	return NULL;
		if (t -> data == d) {
			Node *toDelete = t -> next;
			delete t;
			return toDelete;
		}
		else {
			t -> next = deleteNode( d, t -> next);
			if (t -> next == NULL)	last = t;
		}
		return t;
	}
	void deleteNode(int d) {
		if (first -> next == NULL)	return;
		first -> next = deleteNode(d, first -> next) ;
	}
	void printRecReverse(Node *t) {
		if (t ==  NULL)		return;
		printRecReverse( t -> next);
		cout << t -> data << ' ';
	}
	void printRecReverse() {
		printRecReverse(first->next);
		cout << '\n' ;
	}
	void printRec(Node *t) {
		if (t ==  NULL)		return;
		cout << t -> data << ' ';
		printRec( t -> next);
	}
	//wrapper function
	void printRec() {
		printRec(first->next);
		cout << '\n' ;
	}
	//===================== Task A =================
	bool printKthPositiveNode(int k, Node* curr) {
		// Base Case
		// Reached End of list
		if (curr == NULL) {
			return false;
		}
		// cout << k << ' ' << curr->data << '\n';
		if (curr->data >= 0) {
			if (k == 1) { // Found
				cout << curr->data << '\n';
				return true;
			}
			// recursive Case
			return 	printKthPositiveNode(k - 1, curr->next);
		}

		return printKthPositiveNode(k, curr->next);
	}

	bool printKthPositiveNode(int k) {
		return printKthPositiveNode(k, first->next);
	}

	//===================== Task B =================
	bool isSumEqual(int target) {
		return isSumEqual(target, first->next);
	}

	bool isSumEqual(int target, Node* curr) {
		// Base Case
		if (target <= 0 or curr == NULL)	return target == 0;

		// Recursive Call (To BackTrack in all possible subsets or combinations)
		return isSumEqual(target - curr->data, curr->next)
		       or isSumEqual(target, curr->next);
	}

};
int main() {
	LinkedList list;
	cout << "================= Task A ==============\n";
	list.addNodeAtStart(30);
	list.addNodeAtStart(29);
	list.addNodeAtStart(-38);
	list.addNodeAtStart(64);
	list.addNodeAtStart(46);
	list.addNodeAtStart(-37);
	list.addNodeAtStart(-59);
	list.addNodeAtStart(23);
	list.printRec();
	// list.printKthPositiveNode(3);
	list.printKthPositiveNode(4);
	list.printKthPositiveNode(7);
	cout << "================= Task B ==============\n";
	LinkedList list1;
	list1.addNodeAtStart(29);
	list1.addNodeAtStart(64);
	list1.addNodeAtStart(46);
	list1.addNodeAtStart(37);
	list1.addNodeAtStart(59);
	list1.addNodeAtStart(23);
	list1.printRec();
	cout << list1.isSumEqual(123) << '\n'; // Will return true
	cout << list1.isSumEqual(124) << '\n'; // Will return true
	cout << list1.isSumEqual(118) << '\n'; // Will return false
	cout << list1.isSumEqual(1244) << '\n'; // Will return false
	return 0;
}
