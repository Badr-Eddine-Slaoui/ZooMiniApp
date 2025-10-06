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

        isValid("Enter the animal's habitat (savannah, desert, rainforest, jungle, tundra, ocean, arctic, tropical, subtropical, temperate, polar): ", validHabitats, MAX_HABITATS, newAnimal.habitat);

        isValid("Enter the animal's race (e.g., lion, tiger, bear, elephant, giraffe, zebra, kangaroo, panda, wolf, fox, deer, rabbit, monkey, chimpanzee, gorilla, orangutan, crocodile, alligator, snake, lizard, turtle, tortoise, eagle, hawk, falcon, owl, parrot, penguin): ", validRaces, MAX_RACES, newAnimal.race);

        do {
            handleInputNumber("Enter the animal's weight (0.1kg-1000kg): ", newAnimal.weight);
        } while (!isValidWeight(newAnimal.weight));

        animals.push_back(newAnimal);

    }

    cout << GREEN << "Animals added successfully!" << RESET << endl;

    saveToFile(animals);
}
