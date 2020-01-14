#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu(){
	cout << "======Main Menu======" << endl;
    cout << "1. Print the inventory" << endl;
	cout << "2. Delete a movie" << endl;
	cout << "3. Quit" << endl;
}

int main(int argc, char const *argv[]) {
    string fileName = argv[1];
    MovieTree tree;
    string choice, title, wordIn, line = "";
    stringstream lineStrm;
    string words[4];
    int counter = 0;

    //open the movie file
    ifstream inFile;
    inFile.open(fileName);
    //if it can't be opened, print the message
    if (inFile.fail()) {
        cout << "Failed to open the file." << endl;
    }

    while(getline(inFile,line)){
        stringstream lineStrm(line);
        while(getline(lineStrm,wordIn,',')){
            words[counter] = wordIn;
            counter ++;
        }
        counter = 0;
        tree.addMovie(stoi(words[0]),words[1],stoi(words[2]),stof(words[3]));
    }
    inFile.close();

    while(choice != "3"){
        menu();
        getline(cin,choice);

        switch (stoi(choice)) {
            case 1:     //Print the inventory
                tree.printMovieInventory();
                break;

            case 2:     //Delete a movie
                cout << "Enter title:" << endl;
				getline(cin,title);
				tree.deleteMovie(title);
                break;

            case 3:     //Quit
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid input" << endl;
        }
    }
    return 0;
}
