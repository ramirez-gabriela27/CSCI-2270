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
 */
Country* CountryNetwork::searchNetwork(string countryName){
    Country* ptr = head;
    while(ptr != NULL && ptr->name != countryName){
        ptr = ptr->next;
    }
    return ptr;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message){
    Country* ptr = head;
    if(ptr == NULL){
        cout << "Empty list" << endl;
    }else if(searchNetwork(receiver) == NULL){
        cout << "Country not found" << endl;
    }else if(ptr->name == receiver){
        ptr->message = message;
        ptr->numberMessages++;
        cout << ptr->name << " [# messages received: " << ptr->numberMessages << "] received: " << ptr->message << endl;
    }else{
        while(ptr!= NULL && ptr->name != receiver){
            ptr->message = message;
            ptr->numberMessages++;
            cout << ptr->name << " [# messages received: " << ptr->numberMessages << "] received: " << ptr->message << endl;
            ptr = ptr->next;
        }
        ptr->message = message;
        ptr->numberMessages++;
        cout << ptr->name << " [# messages received: " << ptr->numberMessages << "] received: " << ptr->message << endl;
    }
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
