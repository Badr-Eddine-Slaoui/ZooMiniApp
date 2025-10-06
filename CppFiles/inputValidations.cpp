#include <iostream>
#include <string>
#include "../HppFiles/helpers.hpp"
#include "../HppFiles/structs.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"
#include "../HppFiles/enums.hpp"

using namespace std;

void isValid(const string &prompt, string validList[], int listSize, string &var) {
    bool valid = false;
    do {
        handleGetline(prompt, var);

        for (int i = 0; i < listSize; i++) {
            if (var == validList[i]) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << YELLOW << "Invalid input. Please enter a valid option." << RESET << endl;
        }
    } while (!valid);
}

bool isValidName(const string &name) {
    string namePattern = "^[A-Za-z]{3,15}( [A-Za-z]{3,15}){0,1}$";

    if (!checkRegex(name, namePattern)) {
        cout << YELLOW << "Invalid name. Name should be 3-15 characters long and may include a single space." << RESET << endl;
        return false;
    }

    return true;
}

bool isValidAge(const int &age) {
    if (age < 1 || age > 120) {
        cout << YELLOW << "Invalid age. Age should be between 1 and 120." << RESET << endl;
        return false;
    }
    return true;
}

bool isValidWeight(const double &weight) {
    if (weight < 0.1 || weight > 1000.0) {
        cout << YELLOW << "Invalid weight. Weight should be between 0.1kg and 1000kg." << RESET << endl;
        return false;
    }
    return true;
}