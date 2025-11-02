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
    for_each(villagerData.begin(), villagerData.end(),
                  [](pair<const string, int>& villager) {
                      villager.second += 1; // You can modify the value part of the pair
                  });

    // Print the updated map
    for (const auto& [name, level] : villagerData)
        cout << name << " has a friendship level of " << level << endl;

    return 0;
}