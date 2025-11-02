#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map<string, tuple<int, string, string>> villagerData{
        {"Drago",make_tuple(5,"Alligator", "Snap to It!")},
        {"Kyle",make_tuple(10,"Wolf", "Hubba hubba!")},
        {"Raymond",make_tuple(8,"Cat", "Nice fit")}
    };

    // Increase each villager's friendship level by 1
    for ( auto& [name,list] : villagerData){
        get<0>(list) += 1;
    }
    // Print the updated map
    for (const auto& [name,list] : villagerData)
        cout << name << " has a friendship level of " << get<0>(list) << endl;

    return 0;
}