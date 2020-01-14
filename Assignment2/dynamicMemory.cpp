// CSCI2270 Fall 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 204 – Saumya Sinha
// Homework 2 - Problem # 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

// Word struct
struct wordItem{
    string word;
    int count;
};

/*
    Read stop words from file
    @param ignoreWordFileName (pointer) - name of ignore file
    @param ignoreWords (string array) - words to be ignored
    @return N/A
*/
void getStopWords (const char *ignoreWordFileName, string ignoreWords[]){
    //open the in file
    ifstream inFile;
    inFile.open(ignoreWordFileName);
    //if it can't be opened, print the message
    if (inFile.fail()) {
        cout << "Failed to open " << ignoreWordFileName << endl;
    }

    string line;
    int count = 0;

    while(getline(inFile,line)){
        if(line !=""){
            ignoreWords[count] = line;
            count++;
        }
    }

    inFile.close();
}

/*
    find if word is stop word
    @param word (string) - word being compared
    @param ignoreWords (string array) - words to be ignored
    @return flag (bool) - is it a stop word?
*/
bool isStopWord(string word, string ignoreWords[]){
    bool flag = NULL;

    for(int i = 0; i < 50; i++){
        if(word == ignoreWords[i]){
            return true;
        }
    }

    return flag;
}

/*
    sum up the total numebr of non-stop words
    @param uniqueWords (wordItem array) - array of unique words
    @param length (int) - length of array
    @return num (int) - sum of individual unique words
*/
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
    int sum = 0;

    for (int i = 0; i < length; i++){
        int num = uniqueWords[i].count;
        sum += num;
    }

    return sum;
}

/*
    sort array of unique words by frequency
    @param uniqueWords (wordItem array) - array of unique words
    @param length (int) - length of array
    @return N/A
*/
void arraySort(wordItem uniqueWords[], int length){

    wordItem holder;

    //bubble sort
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < length - i; j++) {

            if (uniqueWords[j].count < uniqueWords[j+1].count) {
                holder = uniqueWords[j+1];
                uniqueWords[j+1] = uniqueWords[j];
                uniqueWords[j] = holder;
            }
        }
    }
}

/*
    print next 10 words after starting index N from sorted array
    @param uniqueWords (wordItem array) - array of unique words
    @param N (int) - number from command line
    @param totalNumWords (int) - total words
    @return N/A
*/
void printNext10(wordItem uniqueWords[], int N, int totalNumWords){
    int num = N;

    for (int i = num; i < num+10; i++){
        float probability;

        probability = (float)uniqueWords[i].count/totalNumWords;
        cout << fixed;
        cout << setprecision(4) << probability << " - " << uniqueWords[i].word << endl;
    }
}

/*
    double up the array
    @param *&array (wordItem array) - array of word items
    @param &size (int) - size of the array
    @return N/A
*/
void resize(wordItem *&array, int &size){
	int newSize = size*2;
    wordItem* newArray = new wordItem[newSize];

    for (int i=0; i<size; i++){
        newArray[i] = array[i];
    }

	delete [] array;
	array = newArray;
}

int main(int argc, char const *argv[]) {

    if(argc < 4){
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    }

    int N = stoi(argv[1]);
    //string fileIn = argv[2];
    //string fileIgnore = argv[3];

    string ignoreWords[50];
    getStopWords(argv[3],ignoreWords);

    //open the in file
    ifstream inFile;
    inFile.open(argv[2]);
    //if it can't be opened, print the message
    if (inFile.fail()) {
        cout << "Failed to open " << argv[2] << endl;
    }

    int numDoubled = 0;      //keep track of the times array size is doubled
    int numUnique = 0;       //keep track of unique non-common wrods
    int numTotalNC= 0;       //keep track of total non-common words

    int size = 100;
    wordItem* textWords;
    textWords = new wordItem[size];

    string line;
    string val;
    stringstream word;

    while(getline(inFile,line)){
        istringstream word(line);
        while(getline(word,val,' ')){
            if((isStopWord(val,ignoreWords))==false){
                bool flagUnique = true;

                for(int i = 0; i < size; i++){
                    if(val == textWords[i].word){
                        flagUnique = false;
                        textWords[i].count++;
                        numTotalNC++;
                    }
                }
                if(flagUnique == true){
                    textWords[numUnique].word = val;
                    textWords[numUnique].count = 1;
                    numUnique++;
                    numTotalNC++;
                }
            }
            if(numUnique == size){
                resize(textWords,size);
                size = size*2;
                numDoubled++;
            }
        }
    }

    inFile.close();

    cout << "Array doubled: " << numDoubled << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << numUnique << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << numTotalNC << endl;
    cout << "#" << endl;
    cout << "Probability of next 10 words from rank " << N << endl;
    cout << "---------------------------------------" << endl;

    arraySort(textWords, size);
    printNext10(textWords, N, numTotalNC);

    return 0;
}
