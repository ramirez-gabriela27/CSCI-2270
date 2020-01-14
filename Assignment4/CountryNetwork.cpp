/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork(){
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty(){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName){
    if(head == NULL){
        head = new Country;
        head->name = countryName;
        head->message = "";
        head->numberMessages = 0;
        head->next = NULL;
        cout << "adding: " << countryName << " (HEAD)"<< endl;
    }else if(previous == NULL){
        Country* temp = new Country;
        temp->name = countryName;
        temp->message = "";
        temp->numberMessages = 0;
        temp->next = head;
        head = temp;
        cout << "adding: " << countryName << " (HEAD)"<< endl;
    }else{
        Country* temp = new Country;
        temp->name = countryName;
        temp->message = "";
        temp->numberMessages = 0;
        Country* oldPrevPoint = previous->next;
        previous->next = temp;
        if(oldPrevPoint == NULL){
            temp->next = NULL;
        }else{
            temp->next = oldPrevPoint;
        }
        cout << "adding: " << countryName << " (prev: "<< previous->name << ")" << endl;
    }
}

/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName){
    Country* ptr = searchNetwork(countryName);
    if(ptr == NULL){
        cout << "Country does not exist." << endl;
    }else{
        if(ptr == head){
            Country *temp = head;
            head = head->next;
            delete temp;
        }else{
            Country* pres = head;
            Country* prev = NULL;
            while(pres->name != countryName){
                prev = pres;
                pres = pres->next;
            }
            prev->next = pres->next;
            delete pres;
        }
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup(){

    string initialList[6] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};

    Country* previous = new Country;
    insertCountry(NULL,initialList[0]);

    for(int i = 1; i < 6; i++){
        previous = searchNetwork(initialList[i-1]);
        insertCountry(previous,initialList[i]);
    }
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName){
    Country* ptr = head;
    while(ptr != NULL && ptr->name != countryName){
        ptr = ptr->next;
    }
    return ptr;
}

/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork(){
    Country* pres = head;
    Country* prev = NULL;
    while(pres != NULL){
        cout << "deleting: " << pres->name << endl;
        prev = pres;
        prev->next = pres->next;
        delete pres;

        pres = pres->next;
    }
    head = NULL;
    cout << "Deleted network" << endl;
}

/*
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */
void CountryNetwork :: rotateNetwork(int n){
    Country* temp = head;
    int listCount = 0;

    while(temp != NULL){    // used to count through
        listCount++;
        temp = temp->next;
    }

    if(head == NULL){
        cout << "Linked List is Empty" << endl;
    }else if(n < 1 || n > listCount){
        cout << "Rotate not possible" << endl;
    }else{
        Country* prev = new Country;
        prev = head;
        Country* current = new Country;
        current = head;
        Country* last = new Country;
        last = head;

        for(int i = 0; i < n; i++){     // find nth node
            current = current->next;
        }

        for(int i = 0; i < (n-1); i++){ // find n-1
            prev = prev->next;
        }

        while(last->next != NULL){      // find last node
            last = last->next;
        }

        last->next = head;
        head = current;
        prev->next = NULL;

        cout << "Rotate Complete" << endl;
    }
}

/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork(){
    Country* previous = new Country;
    Country* current = new Country;
    Country* next = new Country;

    previous = NULL;
    current = head;

    while(current != NULL){
        next = current ->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath(){
    Country* temp = head;
    cout << "== CURRENT PATH ==" << endl;

    if(temp == NULL){
        cout << "nothing in path" << endl;
        cout << "===" << endl;
    }else{
        while(temp != NULL){
            cout << temp->name<< " -> ";
            temp = temp->next;
        }
        cout << "NULL"<< endl;
        cout << "===" << endl;
    }
}
