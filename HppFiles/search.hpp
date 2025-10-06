#ifndef SEARCH_HPP
#define SEARCH_HPP
#include <vector>
#include "structs.hpp"

using namespace std;

void searchAnimalByID(const vector<Animal> &animals);

void searchAnimalsByName(const vector<Animal> &animals);

void searchAnimalsByAge(const vector<Animal> &animals);

void searchAnimalsByHabitat(const vector<Animal> &animals);

void searchAnimalsByRace(const vector<Animal> &animals);

void searchAnimalsByWeight(const vector<Animal> &animals);

void searchAnimalsByAgeRange(const vector<Animal> &animals);

void searchAnimalsByWeightRange(const vector<Animal> &animals);

#endif