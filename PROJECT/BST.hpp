#pragma once

#include <iostream>
using namespace std;

struct BSTNode {
	int key;
	BSTNode *left, *right;
};

class BinarySearchTree {
private:
	BSTNode* root;
	BSTNode* searchKeyHelper(BSTNode* root, int k);
	BSTNode* insertNodeHelper(BSTNode* r, int k);
	BSTNode* createNode(int k);
	BSTNode* deleteNodeHelper(BSTNode* r, int k);
	BSTNode* minNode(BSTNode* r);
public:
	BinarySearchTree();
	void searchKey(int k);
	void insertNode(int k);
	void deleteNode(int k);
};
