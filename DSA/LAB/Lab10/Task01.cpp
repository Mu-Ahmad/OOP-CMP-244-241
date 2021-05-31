// Name: Muhammad Ahmad
// Roll: BCSF19M509

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BST{
	struct BTNode{
		int data;
		BTNode *left, *right;
		BTNode(int data, BTNode *left=NULL, BTNode *right=NULL){
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
	BTNode *root;
public:
	BST(){	root = NULL;	}
	BTNode* add(int d, BTNode*& t){	
		if (t==NULL)	return new BTNode(d);
		if (t->data>d) 		t->left = add(d, t->left);
		else if (t->data<d) t->right = add(d, t->right);
		return t;	
	}
	void add(int d){	
		root = add(d, root);
	}
	void inorder(BTNode* t){
		if (t!=NULL){
			inorder(t->left);
			cout << t->data << ' ';
			inorder(t->right);
		}
	}
	void inorder(){
		inorder(root);
		cout << '\n';
	}
	void preorder(BTNode* t){
		if (t!=NULL){
			cout << t->data << ' ';
			preorder(t->left);
			preorder(t->right);
		}
	}
	void preorder(){
		preorder(root);
		cout << '\n';
	}
	int countNodes(BTNode*& t){
		//Count nodes as we calculate height, instead of finding max, add left and right
		if(t==NULL) return 0;

		return 1 + countNodes(t->left) + countNodes(t->right);
	}
	int countNodes(){
		return countNodes(root);
	}
	int inOrderArray(BTNode*& t, int *array, int index){
		if (t!=NULL){
			//call function for left of tree and get index
			index = inOrderArray(t->left, array, index);
			//store value of current node in array according to index
			array[index] = t->data;
			//call function for right of tree with index+1 and get index
			index = inOrderArray(t->right, array, index+1);
			return index;
		}
		return index;
	}
	void addBinarySearch(int *array, int start, int end){
		if (start<=end){
			//calculate middle index
			int mid = (start + end) / 2; 
			//add element in BST from middle
			this->add(array[mid]); 
			//call same function for left sub-array
			addBinarySearch(array, start, mid-1);
			//call same function for right sub-array
			addBinarySearch(array, mid+1, end);
			return;
		}
		return;		
	}
	void checkAndBalanceTree(int countNodes){
		//declare array of approriate size
		int treeArray[countNodes + 1];
		//call inorderArray with appropriate arguments
		this->inOrderArray(root, treeArray, 1);
		//remove BST
		this->removeNodes(root);
		//call addBinarySearch with appropriate arguments
		this->addBinarySearch(treeArray, 1, countNodes);
	}
	void checkAndBalance(){
		//get left count at root
		int leftCount = this->countNodes(root->left);
		//get right count at root
		int rightCount = this->countNodes(root->right);
		//get difference
		int diff = leftCount - rightCount;
		//if difference is inappropriate
		// call checkAndBalanceTree with appropriate arguments;
		if(diff >= 2 or diff <= -2)
			checkAndBalanceTree(rightCount + leftCount + 1);
	}
	void removeNodes(BTNode*& t){
		if (t == NULL) return;
		//call this function for left
		removeNodes(t->left);
		//call this function for right
		removeNodes(t->right);
		//delete t
		delete(t);
		t = NULL;
	}
	~BST(){
		removeNodes(root);
	}
};


int main(){
	srand(time(0));
	BST tree;
	for (int i=0;i<20;i++)
		tree.add(rand()%900+100);
    
	// task b
	cout <<"Nodes Count :"<< tree.countNodes()<<'\n';
	
	tree.preorder();
	tree.inorder();
	tree.checkAndBalance();
	tree.preorder();
	tree.inorder();
	return 0;
}