#pragma once

#include <iostream>
using namespace std;

struct Node {
	int key;
	Node *next;
};

class LinkedList {
private:
	Node* head;
    Node* createNode(int k);
public:
	LinkedList();
	Node* searchKey(int k);
	void insertNode(Node* h, int k);
	void deleteNode(int k);
};
