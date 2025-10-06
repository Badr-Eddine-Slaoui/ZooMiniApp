#ifndef FILEHANDLERS_HPP
#define FILEHANDLERS_HPP
#include <vector>
#include "structs.hpp"

void saveToFile(const vector<Animal> &arr);

void loadFromFile(vector<Animal> &arr);

#endif