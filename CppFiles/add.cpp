#include <iostream>
#include <vector>
#include <ctime>
#include "../HppFiles/add.hpp"
#include "../HppFiles/structs.hpp"
#include "../HppFiles/enums.hpp"
#include "../HppFiles/helpers.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"
#include "../HppFiles/inputValidations.hpp"
#include "../HppFiles/fileHandlers.hpp"

using namespace std;

void addAnimal(vector<Animal> &animals, int n) {

    for (int i = 0; i < n; i++) {
        Animal newAnimal;
        newAnimal.id = (long) time(NULL);
        setCurrentDate(newAnimal.registration_date);
        cout << CYAN << "Entering details for Animal " << (i + 1) << ":" << RESET << endl;

        do {
            handleGetline("Enter the animal's name (3-15 characters long and may include a single space): ", newAnimal.name);
        } while (!isValidName(newAnimal.name));

        do {
            handleInputNumber("Enter the animal's age (1-120): ", newAnimal.age);
        }while (!isValidAge(newAnimal.age));

        isValid("Enter the animal's habitat (e.g., savannah, desert, rainforest, jungle, tundra, ocean, arctic, tropical, subtropical, temperate, polar): ", validHabitats, newAnimal.habitat);
        
        isValid("Enter the animal's race (e.g., lion, tiger, cheetah, leopard, jaguar, cougar, panther, giraffe, zebra, rhinoceros, elephant, hippopotamus, crocodile, alligator, cobra, viper, python, snake, lizard, iguana, chameleon, lemur, monkey, gorilla, orangutan, baboon, armadillo, platypus, penguin, dolphin, shark, whale, otter, seal, polar bear, panda): ", validRaces, newAnimal.race);

        do {
            handleInputNumber("Enter the animal's weight (0.1kg-1000kg): ", newAnimal.weight);
        } while (!isValidWeight(newAnimal.weight));

        animals.push_back(newAnimal);

    }

    cout << GREEN << "Animals added successfully!" << RESET << endl;

    saveToFile(animals);
}
