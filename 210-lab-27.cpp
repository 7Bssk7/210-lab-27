#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int mainMenu();
void outputDetails(const map<string, tuple<int, string, string>>& );

int main() {
    map<string, tuple<int, string, string>> villagerData{
        {"Drago",make_tuple(5,"Alligator", "Snap to It!")},
        {"Kyle",make_tuple(10,"Wolf", "Hubba hubba!")},
        {"Raymond",make_tuple(8,"Cat", "Nice fit")}
    };

    int menu = mainMenu();
    while(menu != 4){
        outputDetails(villagerData);
        menu = mainMenu();
    }
    /*
    // Increase each villager's friendship level by 1
    for ( auto& [name,list] : villagerData){
        get<0>(list) += 1;
    }
    // Print the updated map
    for (const auto& [name,list] : villagerData)
        cout << name << " has a friendship level of " << get<0>(list) << endl;
    */
    return 0;
}

int mainMenu(){
    int choice;
    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;
    cout << "Choice -> ";
    cin >> choice;

    return choice;

}
void outputDetails(const map<string, tuple<int, string, string>>& data){
    cout << "Villager details:" << endl;
    for (const auto& [name,list] : data){
       cout << name << "[" << get<0>(list) << ", " << get<1>(list) << ", " << get<2>(list) << "]" << endl;
    }

}