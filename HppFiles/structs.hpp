#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include <string>

using namespace std;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    long id;
    string name;
    int age;
    string habitat;
    string race;
    double weight;
    Date registration_date;
} Animal;

#endif