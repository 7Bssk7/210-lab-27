#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int mainMenu();
void outputDetails(const map<string, tuple<int, string, string>>& );
void addVillager(map<string, tuple<int, string, string>>& );
void deleteVillager(map<string, tuple<int, string, string>>& );
void increaseFriendship(map<string, tuple<int, string, string>>& );
void descreaseFriendship(map<string, tuple<int, string, string>>& );
void searchVillager(map<string, tuple<int, string, string>>& );

int main() {
    map<string, tuple<int, string, string>> villagerData{
        {"Drago",make_tuple(5,"Alligator", "Snap to It!")},
        {"Kyle",make_tuple(10,"Wolf", "Hubba hubba!")},
        {"Raymond",make_tuple(8,"Cat", "Nice fit")}
    };

    outputDetails(villagerData);
    int menu = mainMenu();
    while(menu != 6){
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

int mainMenu(){
    int choice;
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "Choice -> ";
    cin >> choice;
    cout << endl;

    return choice;

}
void outputDetails(const map<string, tuple<int, string, string>>& data){
    cout << "Villager details:" << endl;
    for (const auto& [name,list] : data){
       cout << name << "[" << get<0>(list) << ", " << get<1>(list) << ", " << get<2>(list) << "]" << endl;
    }
    cout << endl;

}

void increaseFriendship(map<string, tuple<int, string, string>>& data){
    for ( auto& [name,list] : data){
        if(get<0>(list) < 10){
            get<0>(list) += 1;
        }
    }

}

void descreaseFriendship(map<string, tuple<int, string, string>>& data){
    for ( auto& [name,list] : data){
        if(get<0>(list) > 0){
            get<0>(list) -= 1;
        }
    }

}

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
        cout << villager << " was not founnd" << endl;
    }

    cout << endl;

    

}