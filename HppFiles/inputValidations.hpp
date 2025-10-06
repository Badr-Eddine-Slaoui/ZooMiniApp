#ifndef INPUTVALIDATIONS_HPP
#define INPUTVALIDATIONS_HPP
#include <string>
#include <vector>
#include "structs.hpp"

using namespace std;

void isValid(const string &prompt, vector<string> validList, string &var);

bool isValidName(const string &name);

bool isValidAge(const int &age);

bool isValidWeight(const double &weight);


#endif