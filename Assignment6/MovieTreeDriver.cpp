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
    cout << "1. Find a movie" << endl;
	cout << "2. Query movies" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Average Rating of movies" << endl;
	cout << "5. Quit" << endl;
}

int main(int argc, char const *argv[]) {
    string fileName = argv[1];
    MovieTree tree;
    string choice, movieIn, minRating, minYear, wordIn, line = "";
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
        tree.addMovieNode(stoi(words[0]),words[1],stoi(words[2]),stof(words[3]));
    }
    inFile.close();

    while(choice != "5"){
        menu();
        getline(cin,choice);

        switch (stoi(choice)) {
            case 1:     //Find movie
                cout << "Enter title:" << endl;
                getline(cin,movieIn);
                tree.findMovie(movieIn);
                break;

            case 2:     //Query movies
                cout <<"Enter minimum rating:" << endl;
                getline(cin,minRating);
                cout<< "Enter minimum year:" << endl;
                getline(cin,minYear);
                tree.queryMovies(stof(minRating),stoi(minYear));
                break;

            case 3:     //Print the inventory
                tree.printMovieInventory();
                break;

            case 4:     //Average Rating of movies
                tree.averageRating();
                break;

            case 5:     //Quit
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid input" << endl;
        }
    }
    return 0;
}
