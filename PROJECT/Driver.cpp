#include <iostream>
#include <cmath>
#include <vector>
#include "Project.hpp"
using namespace std;

int main() {
    string fileName, outputFile, type = "";

    cout << "Please insert the file from which the data is being read: " << endl;
    getline(cin, fileName);
    cout << "Please insert the file to which you are writting the data: " << endl;
    getline(cin, outputFile);

    cout << "Please insert the type of collison resolution you want to implenet:" << endl;
    cout << "Choose from: \n1. Linked List \n2. Binary Search Tree \n3. Linear Probe \n4. Cuckoo" << endl;
    getline(cin, type);


    HashTable newTable;

    

    return 0;
}
