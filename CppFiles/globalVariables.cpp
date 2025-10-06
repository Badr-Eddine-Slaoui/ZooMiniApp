#include <iostream>
#include <string>
#include <vector>
#include "../HppFiles/globalVariables.hpp"
#include "../HppFiles/structs.hpp"

using namespace std;

vector<string> mainMenu = {
    "=== Zoo Management System ===",
    "Add an animal",
    "Display animals",
    "Sort animals",
    "Update an animal",
    "Delete an animal",
    "Search animals",
    "Display statistics",
    "Exit"
};

vector<string> addMenu = {
    "=== Add Animal Menu ===",
    "Add one animal",
    "Add multiple animals",
    "Return to Main Menu"
};

vector<string> displayMenu = {
    "=== Display Animals Menu ===",
    "Display all animals",
    "Display animals by habitat",
    "Display animals by race",
    "Return to Main Menu"
};

vector<string> sortMenu = {
    "=== Sort Animals Menu ===",
    "Sort by name",
    "Sort by age",
    "Sort by habitat",
    "Sort by race",
    "Sort by weight",
    "Return to Main Menu"
};

vector<string> updateMenu = {
    "=== Update Animal Menu ===",
    "Update animal name",
    "Update animal age",
    "Update animal habitat",
    "Update animal race",    
    "Update animal weight",
    "Return to Main Menu"
};

vector<string> searchMenu = {
    "=== Search Animals Menu ===",
    "Search by ID",
    "Search by name",
    "Search by age",
    "Search by habitat",
    "Search by race",
    "Search by weight",
    "Search by age range",
    "Search by weight range",
    "Return to Main Menu"
};

vector<string> statisticsMenu = {
    "=== Statistics Menu ===",
    "Count of animals",
    "Average age of animals",
    "Average weight of animals",
    "Count of animals by habitat",
    "Count of animals by race",
    "Oldest animal",
    "Youngest animal",
    "Heaviest animal",
    "Lightest animal",
    "Return to Main Menu"
};

vector<string> validHabitats = {
    "savannah",
    "desert",
    "rainforest",
    "jungle",
    "tundra",
    "ocean",
    "arctic",
    "tropical",
    "subtropical",
    "temperate",
    "polar"
};

vector<string> validRaces = {
    "lion",
    "tiger",
    "cheetah",
    "leopard",
    "jaguar",
    "cougar",
    "panther",
    "giraffe",
    "zebra",
    "rhinoceros",
    "elephant",
    "hippopotamus",
    "crocodile",
    "alligator",
    "cobra",
    "viper",
    "python",
    "snake",
    "lizard",
    "iguana",
    "chameleon",
    "lemur",
    "monkey",
    "gorilla",
    "orangutan",
    "baboon",
    "armadillo",
    "platypus",
    "penguin",
    "dolphin",
    "shark",
    "whale",
    "otter",
    "seal",
    "polar bear",
    "panda"
};

vector<Animal> animals;