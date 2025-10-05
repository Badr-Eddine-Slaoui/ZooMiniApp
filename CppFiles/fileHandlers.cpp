#include <iostream>
#include "../HppFiles/fileHandlers.hpp"
#include "../HppFiles/constants.hpp"
#include "../HppFiles/globalVariables.hpp"

using namespace std;

void saveToFile(const Animal *arr){
    FILE *fp = fopen("../Data/animals.dat", "wb");

    if (fp == NULL)
    {
        cout << RED << "ERROR: Unable to save to file!" << RESET << endl;
        return;
    }

    if (animalCount > 0){
        fwrite(arr, sizeof(Animal), animalCount, fp);
    }

    fclose(fp);
}

void loadFromFile(Animal **arr){
    FILE *fp = fopen("../Data/animals.dat", "rb");

    if (fp == NULL)
    {
        cout << YELLOW << "No existing data file found. Starting fresh!" << RESET << endl;
        animalCount = 0;
        *arr = NULL;
        return;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    if (fileSize == 0){
        cout << ORANGE << "Data file is empty. Starting fresh!" << RESET << endl;
        animalCount = 0;
        *arr = NULL;
        fclose(fp);
        return;
    }

    animalCount = fileSize / sizeof(Animal);

    *arr = (Animal*) calloc(animalCount, sizeof(Animal));
    
    if (*arr == NULL){
        cout << RED << "ERROR: Memory allocation failed!" << RESET << endl;
        animalCount = 0;
        fclose(fp);
        return;
    }

    fread(*arr, animalCount, sizeof(Animal), fp);

    cout << ORANGE << "Loaded " << animalCount << " animal from file!" << RESET << endl;

    fclose(fp);
}