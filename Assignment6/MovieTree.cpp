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

void deleteHelper(MovieNode *node){
    if(!node){
        deleteHelper(node->left);
        deleteHelper(node->right);
        delete node;
    }
}
MovieTree::~MovieTree(){
    deleteHelper(root);
}

void printHelper(MovieNode *node){ // INORDER
    if(node){     // print in order using recurssion
        if(node->left != NULL){
            printHelper(node->left);
        }
        cout << "Movie: " << node->title << " " << node->rating << endl;
        if(node->right != NULL){
            printHelper(node->right);
        }
    }else{
        cout << "Tree is Empty. Cannot print" << endl;
    }
}
void MovieTree::printMovieInventory(){
    printHelper(root);
}

MovieNode* addHelper(MovieNode *node, int ranking, string title, int year, float rating){
    if(!node){
        MovieNode* newNode = new MovieNode(ranking, title, year, rating);
        return newNode;
    }else if(node->title < title){    // insert to the RIGTH
        node->right = addHelper(node->right, ranking, title, year, rating);
    }else if (node->title > title){  // insert to the LEFT
        node->left = addHelper(node->left, ranking, title, year, rating);
    }
    return node;
}
void MovieTree::addMovieNode(int ranking, string title, int year, float rating){
    root = addHelper(root,ranking,title,year,rating);
}

MovieNode* findMovieHelper(MovieNode* root, string title){
    MovieNode* node;
    if(root){
        if(root->title == title){
            return root;
        }else if (root->title < title){
            return findMovieHelper(root->right, title);
        }else if (root->title > title){
            node = findMovieHelper(root->left, title);
        }
    }else{
        node = NULL;
    }
    return node;
}
void MovieTree::findMovie(string title) {
    MovieNode* temp = findMovieHelper(root, title);
    if(temp){
        cout << "Movie Info:" << endl;
        cout << "==================" << endl;
        cout << "Ranking:" << temp->ranking << endl;
        cout << "Title  :" << temp->title << endl;
        cout << "Year   :" << temp->year << endl;
        cout << "Rating :" << temp->rating << endl;
     }else{
        cout << "Movie not found." << endl;
    }
}

void queryMoviesHelper(MovieNode *node, float rating, int year){ // PREORDER
    if(node){
        if(node->rating >= rating && node->year > year){
            cout << node->title << "(" << node->year << ") " << node->rating << endl;
        }
        if(node->left != NULL){
            queryMoviesHelper(node->left, rating, year);
        }
        if(node->right != NULL){
            queryMoviesHelper(node->right, rating, year);
        }
    }
}
void MovieTree::queryMovies(float rating, int year){
    if(!root){
        cout << "Tree is Empty. Cannot query Movies" << endl;
    }else{
        cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
        queryMoviesHelper(root, rating, year);
    }
}

float averageRatingHelper(MovieNode* node, int& counter){
    if(!node){
        return 0;
    }else{
        counter++;
        float sum = node->rating;
        if(node->left != NULL){
            sum+= averageRatingHelper(node->left,counter);
        }
        if(node->right != NULL){
            sum += averageRatingHelper(node->right,counter);
        }
        return sum;
    }
}
void MovieTree::averageRating(){
    int counter = 0;
    float sum = 0.0;
    sum = averageRatingHelper(root, counter);
    float avg = sum/counter;

    if(sum == 0){
        cout << "Average rating:0.0" << endl;
    }else{
        cout << "Average rating:" << avg << endl;
    }
}
