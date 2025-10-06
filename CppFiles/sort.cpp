#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "../HppFiles/sort.hpp"
#include "../HppFiles/structs.hpp"
#include "../HppFiles/enums.hpp"
#include "../HppFiles/helpers.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"
#include "../HppFiles/inputValidations.hpp"
#include "../HppFiles/fileHandlers.hpp"

using namespace std;

void sortAnimalsByName(vector<Animal> &animals) {
    string order;

    isValid("Choose sorting order (asc/desc): ", {"asc", "desc"}, order);

    if (order == "asc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.name < b.name;
        });
    } else if (order == "desc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.name > b.name;
        });
    }
}

void sortAnimalsByAge(vector<Animal> &animals) {
    string order;

    isValid("Choose sorting order (asc/desc): ", {"asc", "desc"}, order);

    if (order == "asc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.age < b.age;
        });
    } else if (order == "desc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.age > b.age;
        });
    }
}

void sortAnimalsByHabitat(vector<Animal> &animals) {
    string order;

    isValid("Choose sorting order (asc/desc): ", {"asc", "desc"}, order);

    if (order == "asc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.habitat < b.habitat;
        });
    } else if (order == "desc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.habitat > b.habitat;
        });
    }
}

void sortAnimalsByRace(vector<Animal> &animals) {
    string order;

    isValid("Choose sorting order (asc/desc): ", {"asc", "desc"}, order);

    if (order == "asc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.race < b.race;
        });
    } else if (order == "desc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.race > b.race;
        });
    }
}

void sortAnimalsByWeight(vector<Animal> &animals) {
    string order;

    isValid("Choose sorting order (asc/desc): ", {"asc", "desc"}, order);

    if (order == "asc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.weight < b.weight;
        });
    } else if (order == "desc") {
        sort(animals.begin(), animals.end(), [](const Animal &a, const Animal &b) {
            return a.weight > b.weight;
        });
    }
}