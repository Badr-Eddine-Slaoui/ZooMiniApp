#ifndef HELPERS_HPP
#define HELPERS_HPP
#include <string>
#include <vector>
#include "structs.hpp"
#include "constants.hpp"

using namespace std;

void clearInputBuffer();

void printMenu(vector<string> menu);

void stringToLower(string &str);

void handleGetline(const string &prompt, string &input);

template <typename T>
void handleInputNumber(const string &prompt, T &var) {
    while (true) {
        cout << CYAN << prompt << RESET;
        cin >> var;
        if (cin.fail()) {
            clearInputBuffer();
            cout << YELLOW << "Invalid input. Please enter a valid number." << RESET << endl;
        } else {
            clearInputBuffer();
            break;
        }
    }
}

void setCurrentDate(string &date);

void displayAnimal(const Animal animal, const int index);

void displayAnimals(const vector<Animal> animals);

bool checkRegex(const string &input, const string &pattern);

#endif