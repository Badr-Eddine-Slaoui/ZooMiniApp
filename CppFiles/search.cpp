#include <iostream>
#include <vector>
#include <ctime>
#include "../HppFiles/search.hpp"
#include "../HppFiles/structs.hpp"
#include "../HppFiles/enums.hpp"
#include "../HppFiles/helpers.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"
#include "../HppFiles/inputValidations.hpp"
#include "../HppFiles/fileHandlers.hpp"

using namespace std;

void searchAnimalByID(const vector<Animal> &animals) {
    long id;
    handleInputNumber("Enter the animal's ID to search: ", id);
    bool found = false;

    for (const auto &animal : animals) {
        if (animal.id == id) {
            displayAnimal(animal, 1);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << RED << "No animal found with ID: " << id << RESET << endl;
    }
}

void searchAnimalsByName(const vector<Animal> &animals) {
    string name;
    handleGetline("Enter the animal's name to search: ", name);
    bool found = false;
    int count = 0;

    for (const auto &animal : animals) {
        if (animal.name == name) {
            displayAnimal(animal, count++);
            found = true;
        }
    }

    if (!found) {
        cout << RED << "No animals found with name: " << name << RESET << endl;
    }
}

void searchAnimalsByAge(const vector<Animal> &animals) {
    int age;
    handleInputNumber("Enter the animal's age to search: ", age);
    bool found = false;
    int count = 0;

    for (const auto &animal : animals) {
        if (animal.age == age) {
            displayAnimal(animal, count++);
            found = true;
        }
    }

    if (!found) {
        cout << RED << "No animals found with age: " << age << RESET << endl;
    }
}

void searchAnimalsByHabitat(const vector<Animal> &animals) {
    string habitat;
    isValid("Enter the habitat to search: ", validHabitats, habitat);
    bool found = false;
    int count = 0;

    for (const auto &animal : animals) {
        if (animal.habitat == habitat) {
            displayAnimal(animal, count++);
            found = true;
        }
    }

    if (!found) {
        cout << RED << "No animals found in habitat: " << habitat << RESET << endl;
    }
}

void searchAnimalsByRace(const vector<Animal> &animals) {
    string race;
    isValid("Enter the race to search: ", validRaces, race);
    bool found = false;
    int count = 0;

    for (const auto &animal : animals) {
        if (animal.race == race) {
            displayAnimal(animal, count++);
            found = true;
        }
    }

    if (!found) {
        cout << RED << "No animals found of race: " << race << RESET << endl;  
    }
}

void searchAnimalsByWeight(const vector<Animal> &animals) {
    double weight;
    handleInputNumber("Enter the animal's weight to search: ", weight);
    bool found = false;
    int count = 0;

    for (const auto &animal : animals) {
        if (animal.weight == weight) {
            displayAnimal(animal, count++);
            found = true;
        }
    }

    if (!found) {
        cout << RED << "No animals found with weight: " << weight << RESET << endl;
    }
}

void searchAnimalsByAgeRange(const vector<Animal> &animals) {
    int minAge, maxAge;

    do {
        do
        {
            handleInputNumber("Enter the minimum age to search: ", minAge);
        } while (!isValidAge(minAge));

        do
        {
            handleInputNumber("Enter the maximum age to search: ", maxAge);
        } while (!isValidAge(maxAge));
    } while (minAge > maxAge);

    bool found = false;
    int count = 0;

    for (const auto &animal : animals) {
        if (animal.age >= minAge && animal.age <= maxAge) {
            displayAnimal(animal, count++);
            found = true;
        }
    }

    if (!found) {
        cout << RED << "No animals found in age range: " << minAge << " - " << maxAge << RESET << endl;  
    }
    
}

void searchAnimalsByWeightRange(const vector<Animal> &animals) {
    double minWeight, maxWeight;

    do {
        do
        {
            handleInputNumber("Enter the minimum weight to search: ", minWeight);
        } while (!isValidWeight(minWeight));

        do
        {
            handleInputNumber("Enter the maximum weight to search: ", maxWeight);
        } while (!isValidWeight(maxWeight));
    } while (minWeight > maxWeight);

    bool found = false;
    int count = 0;

    for (const auto &animal : animals) {
        if (animal.weight >= minWeight && animal.weight <= maxWeight) {
            displayAnimal(animal, count++);
            found = true;
        }
    }

    if (!found) {
        cout << RED << "No animals found in weight range: " << minWeight << " - " << maxWeight << RESET << endl;  
    }
}