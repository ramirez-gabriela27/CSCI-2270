// CSCI2270 Fall 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 204 – Saumya Sinha
// Homework 1 - Problem # 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Park structures
struct Park{
    string parkname;
    string state;
    int area;
};

/*
    populate an array of "Park" structures
    @param parks[] (array) - array of "Park" structures
    @param parkname (string) - name of the park
    @param state (string) - state where the park is
    @param area (int) - area of the park
    @param length (int) - length of the array
    @return N/A
*/
void addPark(Park parks[], string parkname, string state, int area, int length){

    Park parkInput{
        parkname,
        state,
        area
    };

    parks[length] = parkInput;
    length++;
}

/*
    print the list of "Park" structures
    @param parks[] (array) - array of "Park" structures
    @param length (int) - length of the array
    @return N/A
*/
void printList(const Park parks[], int length){
    for (int i = 0; i < length; i++){
        Park park = parks[i];

        cout << park.parkname << " [" << park.state << "] area: " << park.area << endl;
    }
}

/*
    split a message based on a delimiter and put it in a two dimensional array
    @param message (string) - message input by user
    @param delimiter (char) - delimiter (place of division) input by the user
    @param messageSubstrings (array) - array of substrings
    @param size (int) - size of the array
    @return substringNums (int) - the number of substrings
*/
int split (string message, char delimiter, string messageSubstrings[], int size){
    if (message.length() == 0) {
        return 0;
    }

    string temp = "";
    int substringNums = 0;

    message += delimiter;

    for (int i = 0; i < message.length(); i++)
    {
        if(message[i]==delimiter){
            if(temp.length() == 0) continue;
            messageSubstrings[substringNums] = temp;
            substringNums ++;
            temp = "";
        }
        else{
            temp = temp + message[i];
        }
    }

    if(size<substringNums){
        return -1;
    }
    else{
        return substringNums;
    }
}

int main(int argc, char *argv[]) {
    string fileInName = argv[1];
    string fileOutName = argv[2];
    int minArea = stoi(argv[3]);

    Park parks[100];
    string parkname = "";
    string state = "";
    int area = 0;
    int length = 0;

    //open the in file
    ifstream inFile;
    inFile.open(fileInName);
    //if it can't be opened, print the message
    if (inFile.fail()) {
        cout << "Failed to open the file." << endl;
    }

    //open the outfile
    ofstream outFile;
    outFile.open(fileOutName);

    string line;
    string msgSubs[3];

    while(getline(inFile,line) && length <= 100){
        // if the line is empty, skip it
        if (line.empty()) continue;
        // else take in the line and split it at the comma
        split(line, ',', msgSubs,3);

        //add park to the array of parks
        addPark(parks, msgSubs[0], msgSubs[1], stoi(msgSubs[2]),length);
        length++;

        if(stoi(msgSubs[2]) > minArea){
            outFile << msgSubs[0] << "," << msgSubs[1] << "," << msgSubs[2] << endl;
        }else;
    }

    printList(parks, length);

    inFile.close();
    outFile.close();
    return 0;
}
