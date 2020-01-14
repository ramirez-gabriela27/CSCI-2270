#include <iostream>
#include <cmath>
#include <vector>
#include "Project.hpp"

using namespace std;

HashTable::HashTable(){     // Constructor
    TABLE_SIZE = 10009;
    buckets.resize(TABLE_SIZE);
    type = "";
}

bool HashTable::insertItem(int key){    // Insert Item (to Hash Table)
    if (type == "Linked List"){
        // int index = hashFunctionMod(key);
        // Node newNode;
        // newNode->key = key;
        // newNode->next = NULL;
        //
        // if(buckets[index] == -1){
        //     buckets.insert(buckets.begin()+index, newNode);
        // }else{
        //     linkedList(key);
        // }
        return true;

    }else if (type == "Binary Search Tree"){
        return true;

    }else if (type == "Linear Probe"){
        int index = hashFunctionMod(key);
        if(buckets[index]->key > 0){
            index = linearProbe(index);
        }if(index >= 0){
            HashNode* newNode = new HashNode;
            newNode->key = key;
            buckets[index] = newNode;
        }
        return true;

    }else if (type == "Cuckoo"){
        return true;

    }else{
        cout << type << " is not a valid type.\n";
        cout << "Couldn't insert item\n";
        return false;
    }
}

bool HashTable::deleteItem(int key){    // Delete Item (from Hash Table)
    if (type == "Linked List"){
        return true;

    }else if (type == "Binary Search Tree"){
        return true;

    }else if (type == "Linear Probe"){
        return true;

    }else if (type == "Cuckoo"){
        return true;

    }else{
        cout << "Couldn't believe\n" << endl;
        return false;
    }
    return false;
}

HashNode* HashTable::searchItem(int key){   // Search for Item in Hash Table
    if (type == "Linked List"){
        return NULL;

    }else if (type == "Binary Search Tree"){
        return NULL;

    }else if (type == "Linear Probe"){
        return NULL;

    }else if (type == "Cuckoo"){
        return NULL;

    }else{
        cout << "Couldn't find key" << endl;
        return NULL;
    }
    return NULL;
}

void HashTable::printTable(){   // Print the Hash Table
    return;
}

int HashTable::hashFunctionMod(int key){    // Hash Function(with Mod) - DEFAULT
    return key % TABLE_SIZE;
}

int HashTable::hashFunctionFloor(int key){  // Hash Function(with Floor)
    return floor(key/TABLE_SIZE);
}

////////////////////////////Collision Resolution////////////////////////////////

int HashTable::linkedList (int key){    // Linked List resolution

    return 0;
}

int HashTable::BinaryST(int key){       // BST resolution

    return 0;
}

int HashTable::linearProbe(int key){    // Linear Probe resolution
    for (int i = key+1; i != key; i++){
        if (i >= TABLE_SIZE){  //wrap around
            i = -1;
            continue;
        }
        if (buckets[i]->key == -1){
            return i;
        }
    }
}

int HashTable::cuckooHashing(int key){  // Cuckoo Hashing resolution

    return 0;
}
