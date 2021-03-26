// Name: Muhammad Ahmad
// Roll: BCSF19M509
#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *next;//TO point to next node, null otherwise
	//Constructor
	Node (int d, Node *n = NULL) {
		data = d;
		next = n;
	}
};


class LinkedList {
	Node *first, *last;
public:
	LinkedList() {	first = new Node(0);	last = NULL;	}
	void addNodeAtStart(int d) {
		Node *newNode = new Node(d);
		newNode -> next = first -> next;
		first -> next = newNode;
		(first-> data)++; //Task a
		if (last == NULL)	last = newNode;
	}
	void addNodeAtEnd(int d) {
		if (last == NULL)	addNodeAtStart(d);
		else {
			(first->data)++; //Task a
			last -> next = new Node(d);
			last = last -> next;
		}
	}
	void addNodeAfter(int d1, int d2) {
		Node *t;
		for (t = first->next ; t != NULL && t -> data != d1; t = t -> next);
		if (t != NULL) {
			(first->data)++; //Task a
			Node *newNode = new Node(d2);
			newNode -> next = t -> next;
			t -> next = newNode;
			if (t == last)	last = newNode;
		}
	}
	void deleteNodeFromStart() {
		if (first->next != NULL) {
			(first->data)--; //Task a
			Node *t = first -> next;
			first -> next = t -> next; //t->next may be second node or NULL
			delete t;
			if (first -> next == NULL)		last = NULL;
		}
	}
	void deleteNodeFromEnd() {
		if (last != NULL) {
			if (first -> next == last)		deleteNodeFromStart();
			else {
				(first->data)--; //Task a
				Node *t = first;
				for ( ; t->next != last; t = t -> next );//Move to second last node
				delete t->next;
				t->next = NULL;
				last = t;
			}
		}
	}
	// ==========================Task a==============================
	void displaySize() const {
		cout << "Size: " << first->data << '\n';
	}

	// ==========================Task b==============================
	void split() {
		Node* temp = first->next;
		while (temp != NULL) {
			if (temp->data > 50) {
				int half = (temp->data) / 2;
				temp->data -= half;
				this->addNodeAfter(temp->data, half);
			}
			temp = temp->next;
		}
		return;
	}

	//==========================Task c==============================

	// Using Stack (Recursive Solution i.e implicit stack)
	bool isPalindrome(Node** left, Node* right) {
		//Base Case
		if (right == NULL) return true;

		//Recursive Case
		bool check = isPalindrome(left, right->next);
		if (!check)	return check;

		check = ((*left)->data == right->data);
		// cout << (*left)->data << ' ' << right->data << '\n';
		*left = (*left)->next;

		return check;
	}

	// Using Array

	bool isPalindrome_arr() const {
		// Copy all the values in an array and use two pointers
		int arr[first->data];
		Node* temp = first->next;
		for (int i = 0; i < first->data; i++, temp = temp->next)
			arr[i] = temp->data;

		int left = 0, right = first->data - 1;
		while (left < right)
			if (arr[left++] != arr[right--])
				return false;

		return true;
	}

	void isPalindrome() {
		// They both Work uncomment to test
		Node* start = first->next;
		if (isPalindrome(&start, start))
			cout << "Is A palindrome\n";
		else
			cout << "Not A palindrome\n";

		// if (isPalindrome_arr())
		// 	cout << "Is A palindrome\n";
		// else
		// 	cout << "Not A palindrome\n";
	}

	//==========================Task d==============================
	void removeNegatives() {
		Node * temp = this->first;
		while (temp->next != NULL) {
			if (temp->next->data < 0) {
				Node*  temp_ref = temp->next;
				temp->next = temp->next->next;
				delete temp_ref;
				(this->first->data)--;
			}	else {
				temp = temp->next;
			}
		}
		return;
	}

	// ==========================Task e==============================

	bool isExist(const int& ELEMENT) const {
		Node* temp = first->next;
		while (temp != NULL) {
			if (temp->data == ELEMENT)
				return true;
			temp = temp->next;
		}
		return false;
	}

	void addFromArray(int * arr, int size) {
		for (int i = 0; i < size; i++) {
			if (!isExist(arr[i]))
				addNodeAtEnd(arr[i]);
		}
	}

	// ==========================Task f==============================
	void showPairs() const {
		Node * temp = first->next;
		while (temp->next != NULL) {
			cout << temp->data << ' ' << temp->next->data << '\n';
			temp = temp->next;
		}
		return;
	}



	void show() {
		if ( first -> next == NULL)
			cout << "List is empty\n";
		for ( Node *t = first -> next ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};



int main() {
	cout << "---------------Task A and Task B---------------\n";
	LinkedList list;
	list.addNodeAtEnd(23);
	list.addNodeAtEnd(59);
	list.addNodeAtEnd(37);
	list.addNodeAtEnd(46);
	list.addNodeAtEnd(64);
	list.addNodeAtEnd(29);
	list.displaySize();
	list.show();
	list.split();
	list.displaySize();
	list.show();
	cout << "---------------TaskC---------------\n";
	list.isPalindrome();
	list.show();
	LinkedList list2;
	list2.addNodeAtStart(1);
	list2.addNodeAtEnd(2);
	list2.addNodeAtEnd(1);
	list2.isPalindrome();
	list2.show();
	list2.addNodeAfter(2, 2);
	list2.isPalindrome();
	list2.show();
	list2.addNodeAtEnd(2);
	list2.isPalindrome();
	list2.show();
	list2.addNodeAtStart(2);
	list2.isPalindrome();
	list2.show();
	cout << "---------------TaskD---------------\n";
	list.addNodeAtStart(-8);
	list.addNodeAtStart(-59);
	list.addNodeAtEnd(-65);
	list.addNodeAfter(46, -998);
	cout << "Before Removing Negative Values\n";
	list.displaySize();
	list.show();
	list.removeNegatives();
	cout << "After Removing Negative Values\n";
	list.displaySize();
	list.show();
	cout << "---------------TaskE---------------\n";
	LinkedList list3;
	list3.addNodeAtEnd(23);
	list3.addNodeAtEnd(59);
	list3.addNodeAtEnd(37);
	list3.addNodeAtEnd(46);
	list3.addNodeAtEnd(66);
	list3.addNodeAtEnd(29);
	int arr[] = {26, 36, 46, 56, 66};
	cout << "Before Adding Array Values\n";
	list3.show();
	cout << "After Adding Array Values\n";
	list3.addFromArray(arr, 5);
	list3.show();
	cout << "---------------TaskF---------------\n";
	list3.deleteNodeFromEnd();
	list3.deleteNodeFromEnd();
	list3.deleteNodeFromEnd();
	cout << "List:\n";
	list3.show();
	cout << "Linked Pairs:\n";
	list3.showPairs();
	return 0;
}