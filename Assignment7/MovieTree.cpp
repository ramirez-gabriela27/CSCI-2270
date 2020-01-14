#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree(){
    root = NULL;
}

void destroyHelper(TreeNode *node){
    if(node){
        destroyHelper(node->leftChild);
        destroyHelper(node->rightChild);

        LLMovieNode* temp = node->head;
        LLMovieNode* nextPtr;

        while(temp){
            nextPtr = temp->next;
            delete temp;
            temp = nextPtr;
        }
        delete node;
    }
}
MovieTree::~MovieTree(){
    destroyHelper(root);
    root = NULL;
}

void printHelperList(LLMovieNode* LLnode){
    while(LLnode != NULL){
        //for every LLMovieNode(m) attached to t
        cout << " >> " << LLnode->title << " " << LLnode->rating << endl;
        LLnode = LLnode->next;
    }
}
void printHelperNode(TreeNode *node){    //INORDER
    if(node){
        if(node->leftChild != NULL){
            printHelperNode(node->leftChild);
        }
        //for every TreeNode(t) in the tree
        cout << "Movies starting with letter: " << node->titleChar << endl;

        printHelperList(node->head);

        if(node->rightChild != NULL){
            printHelperNode(node->rightChild);
        }
    }else;
}
void MovieTree::printMovieInventory(){
    printHelperNode(root);
}

TreeNode* addMovieHelper(TreeNode* &node, TreeNode* newNode){
    if(node == NULL){
        return newNode;
    }
    if(newNode->titleChar < node->titleChar){
        TreeNode* left = addMovieHelper(node->leftChild, newNode);
        node->leftChild = left;
        left->parent = node;
    }else if(newNode->titleChar > node->titleChar){
        TreeNode* right = addMovieHelper(node->rightChild, newNode);
        node->rightChild = right;
        right->parent = node;
    }else if(newNode->titleChar == node->titleChar){
        LLMovieNode* insert = newNode->head;
        LLMovieNode* current = node->head;
        LLMovieNode* previous = NULL;

        while(current != NULL && current->title.compare(insert->title) < 0){
            previous = current;
            current = current->next;
        }
        if(current != NULL && current->title.compare(insert->title) == 0){
            return node;
        }else{
            if(previous == NULL){
                insert->next = node->head;
                node->head = insert;
            }else if(current == NULL){
                previous->next = insert;
            }else{
                previous->next = insert;
                insert->next = current;
            }
        }
    }
    return node;
}
void MovieTree::addMovie(int ranking, string title, int year, float rating){
    LLMovieNode* movie = new LLMovieNode(ranking, title, year, rating);
    TreeNode* node = new TreeNode;
    node->titleChar = title[0];
    node->head = movie;
    node->leftChild = node->rightChild = node->parent = NULL;
    root = addMovieHelper(root, node);
}

TreeNode* deleteMovieHelper(TreeNode* node, string title){
    if (!node){
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return node;
    }

    if (title[0] < node->titleChar){
        node->leftChild = deleteMovieHelper(node->leftChild, title);
    }else if (title[0] > node->titleChar){
        node->rightChild = deleteMovieHelper(node->rightChild, title);
    }else if (title[0] == node->titleChar){
        LLMovieNode* current = node->head;
        LLMovieNode* previous = NULL;

        while (current != NULL && current->title.compare(title) != 0){
            previous = current;
            current = current->next;
        }

        if (!current){
            cout << "Movie: " << title << " not found, cannot delete." << endl;
            return node;
        }

        if (previous == NULL && node->head->next != NULL){
            node->head = node->head->next;
            return node;
        }
        if (previous != NULL && current != NULL){
            previous->next = current->next;
            return node;
        }
        if (node->leftChild == NULL && node->rightChild == NULL){
            delete node;
            return NULL;
        }else if (node->leftChild == NULL){
            TreeNode* temp = node;
            node->rightChild->parent = node->parent;
            node = node->rightChild;
            delete temp;
        }else if (node->rightChild == NULL){
            TreeNode *temp = node;
            node->leftChild->parent = node->parent;
            node = node->leftChild;
            delete temp;
        }else{
            TreeNode* min = node->rightChild;
            while (min->leftChild != NULL){
                min = min->leftChild;
            }
            node->head = min->head;
            node->titleChar = min->titleChar;
            node->rightChild = deleteMovieHelper(node->rightChild, min->head->title);
        }
    }
    return node;
}
void MovieTree::deleteMovie(string title){
    root = deleteMovieHelper(root, title);
}
