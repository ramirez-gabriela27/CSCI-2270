/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu(){
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[]){
	ProducerConsumer list;

	int itemCount = 0;
 	string itemIn, itemOut = "";
	string choice, item = "";

	while(choice != "3"){
		menu();
		getline(cin,choice);

		switch (stoi(choice)) {
			case 1:		//Producer (produce items into the queue)
				cout << "Enter the number of items to be produced:" << endl;
				getline(cin,itemIn);

				for (int i = 1; i <= stoi(itemIn); i++){
					cout << "Item" << i << ":" << endl;
					getline(cin, item);
					list.enqueue(item);
				}
				break;

			case 2:		//Consumer (consume items form the queue)
				cout << "Enter the number of items to be consumed:" << endl;
				getline(cin, itemOut);

				if(stoi(itemOut) > list.queueSize()){
					while(!list.isEmpty()){
						cout << "Consumed: " << list.peek() << endl;
						list.dequeue();
					}
					cout << "No more items to consume from queue" << endl;
				}else{
					for(int i = 0; i < stoi(itemOut); i++){
						cout << "Consumed: " << list.peek() << endl;
						list.dequeue();
					}
				}

				break;

			case 3:		//Return queue size and exit
				itemCount = list.queueSize();
				cout << "Number of items in the queue:" << itemCount;
				break;

			default:
				cout << "Invalid input" << endl;
		}
	}
	return 0;
}
