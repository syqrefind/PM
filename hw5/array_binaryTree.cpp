#include<iostream>
#include<array>

using namespace std;

class TreeNode {
private:
	int item; // Data portion

	int leftChild; // Index to left child

	int rightChild; // Index to right child

public:
	TreeNode();
	TreeNode(int& nodeItem, int left, int right);
	void setItem(int);
	int getItem() ;
	int getLeft() ;
	int getRight();
	void setLeft(int);
	void setRight(int);
}; // end TreeNode



int main() {
	std::array<TreeNode*,10>arr;
	for (int i = 0; i<10; i++)
		arr[i]->setItem(i + 1);//Generates the sample array

	std::cout << "The sample array has integers from 1 to 10:" << std::endl;
	for (int i = 0; i<10; i++)
		std::cout << arr[i]->getItem() << std::endl;
	cout << "Enter a node index(from 0 to 9): " << endl;
	int index;
	cin >> index;
	if ((index < 0) | (index>9)) {
		cout << "Invalid input." << endl;
		return 0;
	}
	cout << "Enter the operation you want to do:\n1. get the value\n2. change the value \n3.exit" << endl;
	int opt;
	cin >> opt;
	if (opt == 1)
		cout << arr[index]->getItem();
	else if (opt == 2) {
		cout << "Enter the new value:\n";
		int value;
		cin >> value;
		arr[index]->setItem(value);
	}
	else {
		cout << "Invalid option." << endl;
		return 0;
	}

	return 0;

}

TreeNode::TreeNode() {}

TreeNode::TreeNode(int& nodeItem, int left, int right) {

	this->item = nodeItem;

	this->leftChild = left;

	this->rightChild = right;

}

void TreeNode::setItem(int item) {

	this->item = item;

}

void TreeNode::setLeft(int i) {

	this->leftChild = i;

}

void TreeNode::setRight(int i) {

	this->rightChild = i;

}

int TreeNode::getItem(){

	return this->item;

}

int TreeNode::getLeft(){

	return this->leftChild;

}

int TreeNode::getRight(){

	return this->rightChild;

}

