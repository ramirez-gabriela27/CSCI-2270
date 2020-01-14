#pragma once

#include "LinkedList.hpp"
#include "BST.hpp"

#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct HashNode{
    int key;             // The value that belongs to the node
    Node head;           // Head of the LL (object)
    BSTNode root;        // Root of the BST (object)
};

class HashTable
{
private:
    int TABLE_SIZE;     // Size of the table
    string type;        // Collision resolutions (LL, BST, LinProbe, Cuckoo1, Cuckoo2)
    vector<HashNode*> buckets; // Vector holding nodes
public:
    HashTable();                        // Constructor
    bool insertItem(int key);           // Insert based on key
    bool deleteItem(int key);           // Delete based on key
    HashNode* searchItem(int key);      // Search based on key
    void printTable();                  // Print Hash Table (NOT REQUIRED)

    int hashFunctionMod(int key);       // Hash function (Mod) - DEFAULT

    int hashFunctionFloor(int key);     // Hash function (Floor)

    // Collision Resolution mechanisms
    int linkedList (int key);           // Linked List resolution
    int BinaryST(int key);              // Binary Search Tree resolution
    int linearProbe(int key);           // Linear Probe resolution
    int cuckooHashing(int key);         // cuckooHashing resolution
};
