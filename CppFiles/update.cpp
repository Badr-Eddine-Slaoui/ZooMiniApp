#include <iostream>
#include <vector>
#include <ctime>
#include "../HppFiles/update.hpp"
#include "../HppFiles/structs.hpp"
#include "../HppFiles/enums.hpp"
#include "../HppFiles/helpers.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"
#include "../HppFiles/inputValidations.hpp"
#include "../HppFiles/fileHandlers.hpp"

using namespace std;

void updateAnimalName(vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to update." << RESET << endl;
        return;
    }

    long id;
    handleInputNumber("Enter the ID of the animal to update: ", id);

    for (auto &animal : animals) {
        if (animal.id == id) {
            string newName;
            do {
                handleGetline("Enter the new name (3-15 characters long and may include a single space): ", newName);
            } while (!isValidName(newName));
            animal.name = newName;
            cout << GREEN << "Animal name updated successfully!" << RESET << endl;
            saveToFile(animals);
            return;
        }
    }

    cout << ORANGE << "Animal with ID " << id << " not found." << RESET << endl;
}

void updateAnimalAge(vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to update." << RESET << endl;
        return;
    }

    long id;
    handleInputNumber("Enter the ID of the animal to update: ", id);

    for (auto &animal : animals) {
        if (animal.id == id) {
            int newAge;
            do {
                handleInputNumber("Enter the new age (1-120): ", newAge);
            } while (!isValidAge(newAge));
            animal.age = newAge;
            cout << GREEN << "Animal age updated successfully!" << RESET << endl;
            saveToFile(animals);
            return;
        }
    }

    cout << ORANGE << "Animal with ID " << id << " not found." << RESET << endl;
}

void updateAnimalHabitat(vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to update." << RESET << endl;
        return;
    }

    long id;
    handleInputNumber("Enter the ID of the animal to update: ", id);

    for (auto &animal : animals) {
        if (animal.id == id) {
            string newHabitat;
            isValid("Enter the new habitat (e.g., savannah, desert, rainforest, jungle, tundra, ocean, arctic, tropical, subtropical, temperate, polar): ", validHabitats, newHabitat);
            animal.habitat = newHabitat;
            cout << GREEN << "Animal habitat updated successfully!" << RESET << endl;
            saveToFile(animals);
            return;
        }
    }

    cout << ORANGE << "Animal with ID " << id << " not found." << RESET << endl;
}

void updateAnimalRace(vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to update." << RESET << endl;
        return;
    }

    long id;
    handleInputNumber("Enter the ID of the animal to update: ", id);
    for (auto &animal : animals) {
        if (animal.id == id) {
            string newRace;
            isValid("Enter the new race (e.g., lion, tiger, cheetah, leopard, jaguar, cougar, panther, giraffe, zebra, rhinoceros, elephant, hippopotamus, crocodile, alligator, cobra, viper, python, snake, lizard, iguana, chameleon, lemur, monkey, gorilla, orangutan, baboon, armadillo, platypus, penguin, dolphin, shark, whale, otter, seal, polar bear, panda): ", validRaces, newRace);
            animal.race = newRace;
            cout << GREEN << "Animal race updated successfully!" << RESET << endl;
            saveToFile(animals);
            return;
        }
    }
    cout << ORANGE << "Animal with ID " << id << " not found." << RESET << endl;
}

void updateAnimalWeight(vector<Animal> &animals) {
    if (animals.empty()) {
        cout << YELLOW << "No animals available to update." << RESET << endl;
        return;
    }

    long id;
    handleInputNumber("Enter the ID of the animal to update: ", id);

    for (auto &animal : animals) {
        if (animal.id == id) {
            double newWeight;
            do {
                handleInputNumber("Enter the new weight (0.1kg-1000kg): ", newWeight);
            } while (!isValidWeight(newWeight));
            animal.weight = newWeight;
            cout << GREEN << "Animal weight updated successfully!" << RESET << endl;
            saveToFile(animals);
            return;
        }
    }

    cout << ORANGE << "Animal with ID " << id << " not found." << RESET << endl;
}