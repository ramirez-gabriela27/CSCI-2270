// CSCI2270 Fall 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 204 – Saumya Sinha
// Homework 1 - Problem # 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
    will sort an array of input values
    @param myArray (int array) - SORTED array that can hold at most 100 ints
    @param numEntries (int) - number of elements inserted so far
    @param newValue (int) - incoming value to be inserted into the array
    @return arraySize (int) - current size of the array
*/
int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
    int currentSize = numEntries;
    myArray[currentSize] = newValue;
    currentSize++;

    int holder;

    //bubble sort
    for (int i = 1; i < currentSize; i++) {
        for (int j = 0; j < currentSize - i; j++) {

            if (myArray[j] > myArray[j+1]) {
                holder = myArray[j+1];
                myArray[j+1] = myArray[j];
                myArray[j] = holder;
            }
        }
    }
    return currentSize;
}

int main(int argc, char*argv[]) {
    string fileName = argv[1];
    int myArray[100];

    //open the file
    ifstream inFile;
    inFile.open(fileName);
    //if it can't be opened, print the message
    if (inFile.fail()) {
        cout << "Failed to open the file." << endl;
    }

    string line;
    int numOfInt = 0;
    int inputValue = 0;

    while(getline(inFile,line)){
        if (line != ""){
            if (numOfInt > 100){
                //Close file number of input integers goes above 100
                inFile.close();
            }else{
                inputValue = stoi(line);
                int currentSize = insertIntoSortedArray(myArray, numOfInt, inputValue);

                cout << myArray[0];
                for(int i = 1; i < currentSize; i++){
                    cout << "," << myArray[i];
                }
                cout << endl;

                numOfInt++;
            }
        }else;
    }

    inFile.close();
    return 0;
}
