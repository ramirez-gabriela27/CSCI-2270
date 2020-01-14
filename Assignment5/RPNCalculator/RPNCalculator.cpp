#include <iostream>
#include "RPNCalculator.hpp"
using namespace std;

// will be utilizing Linked List Stack implementation

/*
    Stack || Linked list implementation
    @param N/A
    @return N/A
*/
RPNCalculator::RPNCalculator(){
    stackHead = NULL;
}

/*
    Clear memory
    @param N/A
    @return N/A
*/
RPNCalculator::~RPNCalculator(){
    while(!isEmpty()){
        pop();
    }
}

/*
    check if stack is empty
    @param N/A
    @return N/A
*/
bool RPNCalculator::isEmpty(){
    return (stackHead == NULL);
}

/*
    PUSH values onto the stack
    @param num (float) - floating point number
    @return N/A
*/
void RPNCalculator::push(float num){
    Operand* newIn = new Operand;
    newIn->number = num;
    //newIn->next = NULL;
    newIn->next = stackHead;
    stackHead = newIn;
}

/*
    POP values off the stack
    @param N/A
    @return N/A
*/
void RPNCalculator::pop(){
    if(!isEmpty()){
        Operand* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }else{
        cout << "Stack empty, cannot pop an item." << endl;
    }
}

/*
    peek at top of the stack
    @param N/A
    @return stackHead (Operand*) - top of the stack
*/
Operand* RPNCalculator::peek(){
    if(!isEmpty()){
        Operand* temp = getStackHead();
        return stackHead;
    }else{
        cout << "Stack empty, cannot peek." << endl;
        return NULL;
    }
}

/*
    compute the requested arithmetic
    @param symbol (string) - symbol of
    @return true/false (bool) - based on success of operataion
*/
bool RPNCalculator::compute(string symbol){
    if(symbol == "+" || symbol == "*" || symbol == "="){
        if(isEmpty()){
            cout << "err: not enough operands" << endl;
            return false;
        }else{
            if(symbol == "+"){
                float total = getStackHead()->number;
                pop();
                if(isEmpty()){
                    cout << "err: not enough operands" << endl;
                    push(total);
                    return false;
                }else{
                    total = total + getStackHead()->number;
                    pop();
                    push(total);
                    return true;
                }
            }else if(symbol == "*"){
                float temp1 = getStackHead()->number;
                pop();
                if(isEmpty()){
                    cout << "err: not enough operands" << endl;
                    push(temp1);
                    return false;
                }else{
                    float temp2 =getStackHead()->number;
                    pop();
                    push((temp1*temp2));
                    return true;
                }
            }else;
        }
    }else{
        cout << "err: invalid operation" << endl;
        return false;
    }
}
