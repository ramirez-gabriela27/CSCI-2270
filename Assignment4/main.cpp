/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

void displayMenu(){
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    string country = "";
    string msgFor = "";
    string previous = "";
    Country* prevIn = new Country;
    string n = "";

    string choice = "";
    while(choice != "8"){
        displayMenu();
        getline(cin,choice);

        switch (stoi(choice)) {
            case 1:     // Build Network
                CountryNet.loadDefaultSetup();
                CountryNet.printPath();
                break;

            case 2:     // Print Network Path
                CountryNet.printPath();
                break;

            case 3:     // Add Country
                cout << "Enter a new country name:"<<endl;
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

            case 4:     // Delete Country
                cout << "Enter a country name:" << endl;
                getline(cin,country);

                CountryNet.deleteCountry(country);
                CountryNet.printPath();
                break;

            case 5:     // Reverse Network
                CountryNet.reverseEntireNetwork();
                CountryNet.printPath();
                break;

            case 6:     // Rotate Network
                cout << "Enter the count of values to be rotated:" << endl;
                getline(cin,n);
                CountryNet.rotateNetwork(stoi(n));
                CountryNet.printPath();
                break;

            case 7:     // Clear Network
                cout << "Network before deletion" << endl;
                CountryNet.printPath();
                CountryNet.deleteEntireNetwork();
                cout << "Network after deletion" << endl;
                CountryNet.printPath();
                break;

            case 8:     // Quit
                cout << "Quitting... cleaning up path: " << endl;
                CountryNet.printPath();
                if(CountryNet.isEmpty() == false){
                    CountryNet.deleteEntireNetwork();
                }
                if(CountryNet.isEmpty()==true){
                    cout << "Path cleaned" << endl;
                }else{
                    cout << "Error: Path NOT cleaned" << endl;
                }
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid input" << endl << endl;
        }
    }
    return 0;
}
