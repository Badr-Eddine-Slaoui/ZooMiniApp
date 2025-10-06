#ifndef HELPERS_HPP
#define HELPERS_HPP
#include <string>
#include "structs.hpp"

using namespace std;

void clearInputBuffer();

void printMenu(string menu[], int size);

void stringToLower(string &str);

void handleGetline(const string &prompt, string &input);

template <typename T>
void handleInputNumber(const string &prompt, T &var);

void setCurrentDate(string &date);

void displayAnimal(const Animal animal, const int index);

void displayAnimals(const Animal animals[]);

bool checkRegex(const string &input, const string &pattern);

#endif