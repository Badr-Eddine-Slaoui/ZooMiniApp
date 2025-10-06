#include <iostream>
#include <vector>
#include <fstream>
#include "../HppFiles/fileHandlers.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"

using namespace std;

void saveToFile(const vector<Animal> &arr) {
    ofstream file("../Data/animals.dat", ios::binary);
    if (!file) {
        cout << RED << "Error opening file for writing." << RESET << endl;
        return;
    }

    int animalCount = arr.size();
    file.write(reinterpret_cast<const char*>(&animalCount), sizeof(animalCount));

    for (int i = 0; i < arr.size(); i++) {
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

void loadFromFile(vector<Animal> &arr) {
    ifstream file("../Data/animals.dat", ios::binary);
    if (!file) {
        cout << RED << "Error opening file for reading." << RESET << endl;
        return;
    }

    int animalCount = 0;
    file.read(reinterpret_cast<char*>(&animalCount), sizeof(animalCount));

    if (animalCount <= 0) {
        arr.clear();
        cout << YELLOW << "No animals found in file." << RESET << endl;
        file.close();
        return;
    }

    arr.resize(animalCount);

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
        cout << GREEN << "Data loaded successfully. Loaded " << animalCount << " animals." << RESET << endl;
    } else {
        cout << RED << "Error occurred while reading from file." << RESET << endl;
    }
}

void saveFakeDataToFile(){
    vector<Animal> fakeAnimals = {
        {1, "Leo", 5, "savannah", "lion", 190.5, "2022-01-15 09:30:00"},
        {2, "Stripes", 3, "jungle", "tiger", 220.3, "2021-11-20 14:45:00"},
        {3, "Spot", 4, "savannah", "cheetah", 150.0, "2023-03-10 11:20:00"},
        {4, "Manny", 10, "tundra", "mammoth", 600.0, "2020-05-25 11:20:00"},
        {5, "Ellie", 8, "savannah", "elephant", 500.0, "2019-07-30 11:20:00"},
        {6, "Zara", 2, "desert", "zebra", 300.0, "2023-06-01 11:20:00"},
        {7, "Rex", 6, "jungle", "leopard", 180.0, "2021-09-12 11:20:00"},
        {8, "Coco", 1, "rainforest", "parrot", 1.5, "2024-02-14 11:20:00"},
        {9, "Gerry", 7, "savannah", "giraffe", 800.0, "2018-12-05 11:20:00"},
        {10, "Hippie", 9, "swamp", "hippopotamus", 900.0, "2017-08-22 11:20:00"}
    };

    saveToFile(fakeAnimals);
}