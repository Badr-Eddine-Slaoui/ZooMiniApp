#include <iostream>
#include <string>
#include <limits>
#include <regex>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "../HppFiles/helpers.hpp"
#include "../HppFiles/structs.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"
#include "../HppFiles/enums.hpp"

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printMenu(string menu[], int size) {
    cout << RED << menu[0] << RESET << endl;
    for (int i = 1; i <= size; i++) {
        cout << "Enter " << i << " to " << menu[i] << endl;
    }
}

void stringToLower(string &str) {
    for (char &c : str) {
        c = tolower(c);
    }
}

void handleGetline(const string &prompt, string &input) {
    do{
        cout << CYAN << prompt << RESET;
        getline(cin, input);
        stringToLower(input);
    } while (input.empty());
}

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

void setCurrentDate(string &date) {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm local = *localtime(&now_c);
    stringstream ss;
    ss << put_time(&local, "%Y-%m-%d %H:%M:%S");
    date = ss.str();
}

void displayAnimal(const Animal animal, const int index) {
    cout << "------------------------" << endl;
    cout << YELLOW << "Animal " << index << ":" << RESET << endl;
    cout << GREEN << "ID: " << RESET << animal.id << endl;
    cout << GREEN << "Name: " << RESET << animal.name << endl;
    cout << GREEN << "Age: " << RESET << animal.age << endl;
    cout << GREEN << "Habitat: " << RESET << animal.habitat << endl;
    cout << GREEN << "Race: " << RESET << animal.race << endl;
    cout << GREEN << "Weight: " << RESET << animal.weight << endl;
    cout << GREEN << "Registration Date: " << RESET << animal.registration_date << endl;
    cout << "------------------------" << endl;
}

void displayAnimals(const Animal animals[]) {
    if (animalCount == 0){
        cout << ORANGE << "No animals to display." << RESET << endl;
        return;
    }
    

    for (int i = 0; i < animalCount; i++) {
        displayAnimal(animals[i], i + 1);
    }
} 

bool checkRegex(const string &input, const string &pattern) {
    regex regexPattern(pattern);
    return regex_match(input, regexPattern);
}

