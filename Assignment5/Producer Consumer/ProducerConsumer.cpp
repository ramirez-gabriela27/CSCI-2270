#include <iostream>
#include <cstdlib>
#include "ProducerConsumer.hpp"
using namespace std;

// will be utilizing Circular Array Queue inplementation

/*
    Queue || Circular array implementation
    @param N/A
    @return N/A
*/
ProducerConsumer::ProducerConsumer(){
    queueFront = 0;
    queueEnd = 0;
}

/*
    check if queue is empty
    @param N/A
    @return bool
*/
bool ProducerConsumer::isEmpty(){
    if(counter == 0){
        return true;
    }else{
        return false;
    }
}

/*
    check if queue is full
    @param N/A
    @return bool
*/
bool ProducerConsumer::isFull(){
    if(counter == SIZE){
        return true;
    }else{
        return false;
    }
}

/*
    enqueue
    @param item (string) - item being enqueued
    @return N/A
*/
void ProducerConsumer::enqueue(std::string item){
    if(!isFull()){
        queue[counter] = item;
        queueEnd++;
        counter++;
    }  else{
        cout << "Queue full, cannot add new item" << endl;
    }
}

/*
    dequeue
    @param N/A
    @return N/A
*/
void ProducerConsumer::dequeue(){
    if(!isEmpty()){
        queue[queueFront] = "";
        queueFront++;
        counter--;
        if(queueFront == SIZE){
            queueFront = 0;
        }
        queueEnd = counter - queueFront;
        if(queueEnd < 0){
            queueEnd = abs(queueFront + counter - SIZE);
        }
    }else{
        cout << "Queue empty, cannot dequeue an item" << endl;
    }
}

/*
    return the first item in the queue
    @param N/A
    @return string
*/
string ProducerConsumer::peek(){
    if(isEmpty()){
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }else{
        return queue[queueFront];
    }
}

/*
    return the number of items on the queue
    @param N/A
    @return counter (int) - number of items
*/
int ProducerConsumer::queueSize(){
    return counter;
}
