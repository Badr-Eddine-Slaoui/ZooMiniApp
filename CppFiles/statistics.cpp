#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include "../HppFiles/statistics.hpp"
#include "../HppFiles/structs.hpp"
#include "../HppFiles/enums.hpp"
#include "../HppFiles/helpers.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"
#include "../HppFiles/inputValidations.hpp"
#include "../HppFiles/fileHandlers.hpp"

using namespace std;

void displayAnimalsCount(const vector<Animal> &animals) {
    cout << CYAN << "Total number of animals: " << animals.size() << RESET << endl;
}

void displayAverageAge(const vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to calculate average age." << RESET << endl;
        return;
    }
    double totalAge = 0;
    for (const auto &animal : animals) {
        totalAge += animal.age;
    }
    double averageAge = totalAge / animals.size();
    cout << CYAN << "Average age of animals: " << averageAge << " years" << RESET << endl;
}

void displayAverageWeight(const vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to calculate average weight." << RESET << endl;
        return;
    }
    double totalWeight = 0;
    for (const auto &animal : animals) {
        totalWeight += animal.weight;
    }
    double averageWeight = totalWeight / animals.size();
    cout << CYAN << "Average weight of animals: " << averageWeight << " kg" << RESET << endl;
}

void displayCountByHabitat(const vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to count by habitat." << RESET << endl;
        return;
    }
    map<string, int> habitatCount;
    for (const auto &animal : animals) {
        habitatCount[animal.habitat]++;
    }
    cout << CYAN << "Count of animals by habitat:" << RESET << endl;
    for (const auto &entry : habitatCount) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

void displayCountByRace(const vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to count by race." << RESET << endl;
        return;
    }
    map<string, int> raceCount;
    for (const auto &animal : animals) {
        raceCount[animal.race]++;
    }
    cout << CYAN << "Count of animals by race:" << RESET << endl;
    for (const auto &entry : raceCount) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

void displayOldestAnimal(const vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to determine the oldest animal." << RESET << endl;
        return;
    }
    
    Animal oldest = animals[0];
    int oldestIndex = 0;

    for (size_t i = 1; i < animals.size(); i++) {
        if (animals[i].age > oldest.age) {
            oldest = animals[i];
            oldestIndex = i;
        }
    }
    cout << CYAN << "Oldest animal details:" << RESET << endl;
    displayAnimal(oldest, oldestIndex);
}

void displayYoungestAnimal(const vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to determine the youngest animal." << RESET << endl;
        return;
    }
    
    Animal youngest = animals[0];
    int youngestIndex = 0;

    for (size_t i = 1; i < animals.size(); i++) {
        if (animals[i].age < youngest.age) {
            youngest = animals[i];
            youngestIndex = i;
        }
    }
    cout << CYAN << "Youngest animal details:" << RESET << endl;
    displayAnimal(youngest, youngestIndex);
}

void displayHeaviestAnimal(const vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to determine the heaviest animal." << RESET << endl;
        return;
    }
    
    Animal heaviest = animals[0];
    int heaviestIndex = 0;

    for (size_t i = 1; i < animals.size(); i++) {
        if (animals[i].weight > heaviest.weight) {
            heaviest = animals[i];
            heaviestIndex = i;
        }
    }
    cout << CYAN << "Heaviest animal details:" << RESET << endl;
    displayAnimal(heaviest, heaviestIndex);
}

void displayLightestAnimal(const vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to determine the lightest animal." << RESET << endl;
        return;
    }
    
    Animal lightest = animals[0];
    int lightestIndex = 0;

    for (size_t i = 1; i < animals.size(); i++) {
        if (animals[i].weight < lightest.weight) {
            lightest = animals[i];
            lightestIndex = i;
        }
    }
    cout << CYAN << "Lightest animal details:" << RESET << endl;
    displayAnimal(lightest, lightestIndex);
}

