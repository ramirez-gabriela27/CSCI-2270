#include <iostream>
using namespace std;
#include "BST.hpp"

BinarySearchTree::BinarySearchTree() {          // Constructor
	root = NULL;
}

BSTNode* BinarySearchTree::createNode(int k) {     //Function to make nodes
	BSTNode* newNode = new BSTNode;
	newNode->key = k;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void BinarySearchTree::insertNode(int k) {      //Function to insert node(with helper)
	root = insertNodeHelper(root, k);
}
BSTNode* BinarySearchTree::insertNodeHelper(BSTNode* r, int k) {
	// Insert at the head
	if (r == NULL)
		r = createNode(k);
	else if (r->key < k) // insert to the RIGHT
		r->right = insertNodeHelper(r->right, k);
	else
		r->left = insertNodeHelper(r->left, k);

	return r;
}


void BinarySearchTree::searchKey(int k) {       //Function to search node(with helper)
	BSTNode* ret = searchKeyHelper(root, k);
	if (ret) // ret is not NULL
		cout << ret->key << " has been found." << endl;
	else
		cout << "Key is not in tree." << endl;
}
BSTNode* BinarySearchTree::searchKeyHelper(BSTNode* root, int k) {
	if (root) {
		if (root->key == k)
			return root;
		else if (root->key < k) // Look to the right
			return searchKeyHelper(root->right, k);
		else if (root->key > k) // Look to the left
			return searchKeyHelper(root->left, k);
	} else {
		return NULL;
	}
}

BSTNode* BinarySearchTree::minNode(BSTNode* r) {
	if (r->left)
		return minNode(r->left);
	if (!r->left)
		return r;

}
void BinarySearchTree::deleteNode(int k) {      //Function delete(with helper)
	root = deleteNodeHelper(root, k);
}
BSTNode* BinarySearchTree::deleteNodeHelper(BSTNode* r, int k) {
	// Insert at the head
	if (!r) // R is null
		return r;
	else if (r->key < k) // delete from the RIGHT
		r->right = deleteNodeHelper(r->right, k);
	else if (r->key > k) // delete from the LEFT
		r->left = deleteNodeHelper(r->left, k);
	else { // This is our node, we found it!
		// 3 Cases
		BSTNode* toReturn = r;
		if (r->left == r->right) { // both are null -> NO CHILDREN
			delete r;
			r = NULL;
		} else if (r->left == NULL) { //  there is a right child
			toReturn = r->right;
			delete r;
			return toReturn;
		} else if (r->right == NULL) { //  there is a left child
			toReturn = r->left;
			delete r;
			return toReturn;
		} else { // There are two children
			BSTNode* rightMin = minNode(r->right);
			int kay = rightMin->key;
			deleteNodeHelper(root, rightMin->key);

			rightMin->key = kay;
			rightMin->left = r->left;
			rightMin->right = r->right;
			delete r;
			return rightMin;
		}
	}

	return r;
}
