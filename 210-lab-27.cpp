#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map<string, int> villagerData{
        {"Alice", 5},
        {"Bob", 7},
        {"Cindy", 9}
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