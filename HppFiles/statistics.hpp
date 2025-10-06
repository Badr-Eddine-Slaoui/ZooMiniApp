#ifndef STATISTICS_HPP
#define STATISTICS_HPP
#include <vector>
#include "structs.hpp"

using namespace std;

void displayAnimalsCount(const vector<Animal> &animals);

void displayAverageAge(const vector<Animal> &animals);

void displayAverageWeight(const vector<Animal> &animals);

void displayCountByHabitat(const vector<Animal> &animals);

void displayCountByRace(const vector<Animal> &animals);

void displayOldestAnimal(const vector<Animal> &animals);

void displayYoungestAnimal(const vector<Animal> &animals);

void displayHeaviestAnimal(const vector<Animal> &animals);

void displayLightestAnimal(const vector<Animal> &animals);

#endif