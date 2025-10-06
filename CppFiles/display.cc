#include <iostream>
#include <vector>
#include <ctime>
#include "../HppFiles/display.hpp"
#include "../HppFiles/structs.hpp"
#include "../HppFiles/enums.hpp"
#include "../HppFiles/helpers.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"
#include "../HppFiles/inputValidations.hpp"
#include "../HppFiles/fileHandlers.hpp"

using namespace std;

void displayAnimalsByHabitat(const vector<Animal> &animals) {
    
    cout << YELLOW << "Animals Grouped by Habitat:" << RESET << endl;
    
    for (const string &habitat : validHabitats) {
        
        cout << CYAN << "Habitat: " << habitat << RESET << endl;

        for (const Animal &animal : animals) {
            if (animal.habitat == habitat) {
                displayAnimal(animal, animal.id);
            }
        }

        cout << "------------------------" << endl;
    }
}

void displayAnimalsByRace(const vector<Animal> &animals) {
    
    cout << YELLOW << "Animals Grouped by Race:" << RESET << endl;
    
    for (const string &race : validRaces) {
        
        cout << CYAN << "Race: " << race << RESET << endl;

        for (const Animal &animal : animals) {
            if (animal.race == race) {
                displayAnimal(animal, animal.id);
            }
        }

        cout << "------------------------" << endl;
    }
}