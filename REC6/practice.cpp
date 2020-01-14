#include <iostream>

using namespace std;

Node *deleteKey(Node *head, int key){
    Node *prev = NULL;
    Node *temp = head;
    while (temp != NULL){
        if (temp->key = key){
            if (temp == head){
                head = head->next;
                delete temp;
                temp = head;
            }else{
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}




int main(){




}
