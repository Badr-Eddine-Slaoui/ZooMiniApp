#include <iostream>
#include <fstream>
#include "../HppFiles/fileHandlers.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"

using namespace std;

void saveToFile(const Animal arr[]) {
    ofstream file("../Data/animals.dat", ios::binary);
    if (!file) {
        cout << RED << "Error opening file for writing." << RESET << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(animalCount), sizeof(int));

    for (int i = 0; i < animalCount; i++) {
        file.write(reinterpret_cast<const char*>(&arr[i].id), sizeof(arr[i].id));
        size_t nameLen = arr[i].name.size();
        file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        file.write(arr[i].name.c_str(), nameLen);
        file.write(reinterpret_cast<const char*>(&arr[i].age), sizeof(arr[i].age));
        size_t habitatLen = arr[i].habitat.size();
        file.write(reinterpret_cast<const char*>(&habitatLen), sizeof(habitatLen));
        file.write(arr[i].habitat.c_str(), habitatLen);
        size_t raceLen = arr[i].race.size();
        file.write(reinterpret_cast<const char*>(&raceLen), sizeof(raceLen));
        file.write(arr[i].race.c_str(), raceLen);
        file.write(reinterpret_cast<const char*>(&arr[i].weight), sizeof(arr[i].weight));
        size_t dateLen = arr[i].registration_date.size();
        file.write(reinterpret_cast<const char*>(&dateLen), sizeof(dateLen));
        file.write(arr[i].registration_date.c_str(), dateLen);
    }

    file.close();

    if (file.good()) {
        cout << GREEN << "Data saved successfully." << RESET << endl;
    } else {
        cout << RED << "Error occurred while writing to file." << RESET << endl;
    }
}

void loadFromFile(Animal arr[]) {
    ifstream file("../Data/animals.dat", ios::binary);
    if (!file) {
        cout << RED << "Error opening file for reading." << RESET << endl;
        return;
    }

    file.read(reinterpret_cast<char*>(&animalCount), sizeof(int));
    for (int i = 0; i < animalCount; i++) {
        file.read(reinterpret_cast<char*>(&arr[i].id), sizeof(arr[i].id));
        size_t nameLen = 0;
        file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        arr[i].name.resize(nameLen);
        file.read(&arr[i].name[0], nameLen);
        file.read(reinterpret_cast<char*>(&arr[i].age), sizeof(arr[i].age));
        size_t habitatLen = 0;
        file.read(reinterpret_cast<char*>(&habitatLen), sizeof(habitatLen));
        arr[i].habitat.resize(habitatLen);
        file.read(&arr[i].habitat[0], habitatLen);
        size_t raceLen = 0;
        file.read(reinterpret_cast<char*>(&raceLen), sizeof(raceLen));
        arr[i].race.resize(raceLen);
        file.read(&arr[i].race[0], raceLen);
        file.read(reinterpret_cast<char*>(&arr[i].weight), sizeof(arr[i].weight));
        size_t dateLen = 0;
        file.read(reinterpret_cast<char*>(&dateLen), sizeof(dateLen));
        arr[i].registration_date.resize(dateLen);
        file.read(&arr[i].registration_date[0], dateLen);
    }

    file.close();

    if (file.good()) {
        cout << GREEN << "Data loaded successfully." << RESET << endl;
    } else {
        cout << RED << "Error occurred while reading from file." << RESET << endl;
    }
}