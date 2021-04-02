/*
Name: Muhammad Ahmad
Roll: BCSF19M509
*/

#include <iostream>

using namespace std;

#define DUMMY 0

class DNode {
public:
	DNode *prev, *next;
	int data;
	DNode (int d, DNode *p = NULL , DNode *n = NULL ) {
		data = d;
		prev = p;
		next = n;
	}
};

class DHCLList {
public:
	DNode *head;
	DHCLList() {	head = new DNode(DUMMY);	head -> next = head -> prev = head;	}
	void addNodeAtHead(int d) {
		DNode *newNode = new DNode(d, head, head->next);
		head -> next -> prev = newNode;
		head -> next = newNode;
	}
	void addNodeAtTail(int d) {
		DNode *newNode = new DNode(d, head->prev, head);
		head -> prev -> next = newNode;
		head -> prev = newNode;
	}
	void print(DNode *t) {
		if (t == head)	return;
		cout << t -> data << ' ';
		print(t->next);
	}
	void print() {
		print(head->next);
		cout << '\n';
	}
	void printR(DNode *t) {
		if (t == head)	return;
		cout << t -> data << ' ';
		printR(t->prev);
	}
	void printR() {
		printR(head->prev);
		cout << '\n';
	}
	void addInOrder(int d, DNode *t) {
		if (t == head || t -> data > d) {
			DNode *newNode = new DNode (d, t -> prev, t);
			t -> prev -> next = newNode;
			t -> prev = newNode;
			return;
		}
		addInOrder(d, t -> next) ;
	}
	void addNodeInOrder(int d) {
		if (head -> next == head) {
			addNodeAtHead(d);
			return;
		}
		addInOrder(d, head -> next) ;
	}
	// ================= Task A ==============
	// Helper Functions
	int indexOf(const int& ELEMENT) const {
		int index = 1; // 1 Based indexing
		DNode* temp = head->next;
		while (temp != head) {
			if (temp->data == ELEMENT)
				return index;
			index++;
			temp = temp->next;
		}
		return -1;
	}
	void swapNodes(int d1, int d2) {
		int i1 = indexOf(d1);
		int i2 = indexOf(d2);

		// if elements are same or one of element is not found
		if (i1 == i2 or i1 == -1 or i2 == -1) return; // Do nothing
		DNode *Node1 = head, *Node2 = head;
		if (i1 > i2) swap(i1, i2); // Node1 will come before Node2
		int t1 = i1, t2 = i2;
		while (t1--) Node1 = Node1->next;
		while (t2--) Node2 = Node2->next;

		if (i2 - i1 == 1) {
			// Updating Links for neighbors
			DNode* tempPrev = Node1->prev;

			Node1->next = Node2->next;
			Node2->next->prev = Node1;
			Node1->prev = Node2;

			Node2->next = Node1;
			Node2->prev = tempPrev;
			tempPrev->next = Node2;
		}
		else {
			// Updating Links for non-neighbors
			DNode* tempPrev = Node1->prev;
			DNode* tempNext = Node1->next;

			Node1->next = Node2->next;
			Node2->next->prev = Node1;
			Node1->prev = Node2->prev;
			Node2->prev->next = Node1;

			Node2->next = tempNext;
			tempNext->prev = Node2;
			Node2->prev = tempPrev;
			tempPrev->next = Node2;
		}

	}
	// ================= Task B ==============
	void reverse() {
		head->prev = reverse(head->next);
	}

	DNode* reverse(DNode *curr) {
		//Base Case
		// Empty list
		if (curr == head)	return head;
		//Last Element i.e tail or new head
		if (curr->next == head) {
			head->next = curr;
			curr->prev = head;
			return curr;
		}

		// Recursive Case
		DNode* the_next = reverse(curr->next); // This Will reverse the rest of the list and return a reference to next node
		// move the current node infront of next
		the_next->next = curr;
		//curr node becomes the last
		curr->next = head;
		// Repair the prev reference
		curr->prev = the_next;
		return curr;
	}

	void reverse2() {
		reverse2(head->next);
		swap(head->next, head->prev);
	}

	void reverse2(DNode* curr) {
		if (curr == head) return;

		swap(curr->next, curr->prev);

		return reverse2(curr->prev);
	}
};

int main() {
	DHCLList list;
	cout << "================ Task A ============\n";
	list.addNodeAtTail(1);
	list.addNodeAtTail(2);
	list.addNodeAtTail(3);
	list.addNodeAtTail(4);
	list.addNodeAtTail(5);
	list.addNodeAtTail(6);
	list.print();
	cout << "Swapping 3 and 4:\n";
	list.swapNodes(3, 4); // Swapping Neighbors
	list.print();
	cout << "Swapping 1 and 6:\n";
	list.swapNodes(1, 6); // Swapping Non-Neighbors
	list.print();
	cout << "Swapping 2 and 5:\n";
	list.swapNodes(2, 5); // Swapping Non-Neighbors
	list.print();
	// Swaping Back to original state
	cout << "================ Task B ============\n";
	list.swapNodes(3, 4); // Swapping Neighbors
	list.swapNodes(1, 6); // Swapping Non-Neighbors
	list.swapNodes(2, 5); // Swapping Non-Neighbors
	cout << "Original List:\n";
	list.print();
	list.reverse2();
	cout << "Reversed List:\n";
	list.print();
	cout << "Using prev Reference: (In Reverse Order)\n";
	// This prove that previous reference are also updated correctly
	// during the reversing process
	DNode* start = list.head->prev;
	while (start != list.head) {
		cout << start->data << ' ';
		start = start->prev;
	}

	return 0;
}