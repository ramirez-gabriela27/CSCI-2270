#include <iostream>
using namespace std;
#include "LinkedList.hpp"

LinkedList::LinkedList() {              // Constructor
	head = NULL;
}

Node* LinkedList::createNode(int k) {   //Function to make nodes
	Node* newNode = new Node;
	newNode->key = k;
	newNode->next = NULL;
	return newNode;
}

void LinkedList::insertNode(Node* h, int k) {//Function to insert node(with helper)
    // Insert at the head
	if (h == NULL){
		h = createNode(k);
        cout << "Node: " << k <<" inserted." << endl;
	}
    // Insert at the end recursively
    else{
        h = h->next;
        insertNode(h,k);
	}
}

Node* LinkedList::searchKey(int k) {       //Function to search node(with helper)
    Node* h = head;

    while(h != NULL && h->key != k){
        h = h->next;
    }
    return h;
}

void LinkedList::deleteNode(int k) {      //Function delete(with helper)
	Node* n = searchKey(k);
    if(n == NULL){
        cout << "Node does not exist/can't be deleted." << endl;
    }else{
        if(n == head){
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Node: " << k << " deleted." << endl;
        }else{
            Node* pres = head;
            Node* prev = NULL;
            while(pres->key != k){
                prev = pres;
                pres = pres->next;
            }
            prev->next = pres->next;
            delete pres;
            cout << "Node: " << k << " deleted." << endl;
        }
    }
}
