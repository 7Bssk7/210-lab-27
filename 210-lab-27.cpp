// COMSC-210 | Lab 27 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

// Constant
const int MAX_F = 10, MIN_F = 0;

// Function prototypes
int mainMenu();
void outputDetails(const map<string, tuple<int, string, string>>& );
void addVillager(map<string, tuple<int, string, string>>& );
void deleteVillager(map<string, tuple<int, string, string>>& );
void increaseFriendship(map<string, tuple<int, string, string>>& );
void descreaseFriendship(map<string, tuple<int, string, string>>& );
void searchVillager(map<string, tuple<int, string, string>>& );

int main() {
    // Initial villager data
    map<string, tuple<int, string, string>> villagerData{
        {"Drago",make_tuple(5,"Alligator", "Snap to It!")},
        {"Kyle",make_tuple(10,"Wolf", "Hubba hubba!")},
        {"Raymond",make_tuple(8,"Cat", "Nice fit")}
    };

    outputDetails(villagerData);
    int menu = mainMenu();
    while(menu != 6){ //menu loop 
        if(menu == 1){
            addVillager(villagerData);
        }
        else if(menu == 2){
            deleteVillager(villagerData);
        }
        else if(menu == 3){
            increaseFriendship(villagerData);
        }
        else if(menu == 4){
            descreaseFriendship(villagerData);
        }
        else if(menu == 5){
            searchVillager(villagerData);
        }
        outputDetails(villagerData);
        menu = mainMenu();
    }

    return 0;
}

// mainMenu() displays the menu and returns user's choice
// arguments: none
// returns: int representing menu selection
int mainMenu(){
    int choice;
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice -> ";
    cin >> choice;
    while(choice < 1 || choice > 6){
        cout << "Invalid input, please enter your choice again(1-6):";
        cin >> choice;
    }
    cout << endl;

    return choice;

}

// outputDetails() prints all villager data
// arguments: const reference to villager map
// returns: none
void outputDetails(const map<string, tuple<int, string, string>>& data){
    cout << "Villager details:" << endl;
    for (const auto& [name,list] : data){
       cout << name << "[" << get<0>(list) << ", " << get<1>(list) << ", " << get<2>(list) << "]" << endl;
    }
    cout << endl;

}

// addVillager() adds a new villager to the map
// arguments: reference to villager map
// returns: none
void addVillager(map<string, tuple<int, string, string>>& data){
    string name, s, c;
    int f;
    cout << "Villager name: ";
    cin >> name;
    cout << "Friendship level: ";
    cin >> f;
    cout << "Species: ";
    cin >> s;
    cout << "Catchphrase: ";
    cin.ignore();
    getline(cin, c);

    data[name] = {f, s, c};
    
    cout << name << " added" << endl;
    cout << endl;

}

// deleteVillager() removes a villager by name
// arguments: reference to villager map
// returns: none
void deleteVillager(map<string, tuple<int, string, string>>& data){
    string villager;
    cout << "What is the name of the villager you would like to remove?"<< endl;
    cin >> villager;
    auto it = data.find(villager);
    if(it != data.end()){
        data.erase(it);
        cout << villager << " removed" << endl;
    }
    else{
        cout << villager << " is not on the list" << endl;
    }

    cout << endl;

}

// increaseFriendship() adds 1 to each villager's friendship level (max 10)
// arguments: reference to villager map
// returns: none
void increaseFriendship(map<string, tuple<int, string, string>>& data){
    for ( auto& [name,list] : data){
        if(get<0>(list) < MAX_F){
            get<0>(list) += 1;
        }
    }

}

// decreaseFriendship() subtracts 1 from each villager's friendship level (min 0)
// arguments: reference to villager map
// returns: none
void descreaseFriendship(map<string, tuple<int, string, string>>& data){
    for ( auto& [name,list] : data){
        if(get<0>(list) > MIN_F){
            get<0>(list) -= 1;
        }
    }

}

// searchVillager() finds and prints a villager's details
// arguments: reference to villager map
// returns: none
void searchVillager(map<string, tuple<int, string, string>>& data){
    string villager;
    cout << "What is the name of the villager you are trying to find?"<< endl;
    cin >> villager; 

    auto it = data.find(villager);
    if(it != data.end()){
        cout << "\nFound " << villager << endl;
        cout << "Friendship Level: " << get<0>(it->second) << endl;
        cout << "Species: " << get<1>(it->second) << endl;
        cout << "Catchphrase: " << get<2>(it->second) << endl;
    }
    else{
        cout << villager << " was not found" << endl;
    }

    cout << endl;

    

}