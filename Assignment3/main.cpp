/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
// you may include more libraries as needed

/*
 * Purpose; displays a menu with options
 */
void displayMenu(){
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

int main(int argc, char* argv[]){
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;

    string choice = "";
    string country = "";
    string msgFor = "";
    string previous = "";
    Country* prevIn = new Country;

    while(choice != "5"){
        displayMenu();
        getline(cin,choice);

        switch(stoi(choice)){
            case 1:     // Build Network
                CountryNet.loadDefaultSetup();
                CountryNet.printPath();
                break;

            case 2:     // Print Network Path
                CountryNet.printPath();
                break;

            case 3:     // Transmit Message
                cout << "Enter name of the country to receive the message:" << endl;
                getline(cin,country);

                cout << "Enter the message to send:" << endl << endl;
                getline(cin,msgFor);

                CountryNet.transmitMsg(country,msgFor);
                break;

            case 4:     // Add Country
                cout << "Enter a new country name:" << endl;
                getline(cin,country);

                cout << "Enter the previous country name (or First):" << endl;
                getline(cin,previous);

                while(CountryNet.searchNetwork(previous) == NULL && previous != "First"){
                    cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                    getline(cin,previous);
                }
                prevIn = CountryNet.searchNetwork(previous);
                CountryNet.insertCountry(prevIn,country);
                CountryNet.printPath();
                break;

            case 5:     // Quit
                cout << "Quitting..." << endl;
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid input" << endl << endl;
        }
    }
    return 0;
}
