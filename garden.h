#ifndef GARDEN_H
#define GARDEN_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include "plant.h"
using namespace std;

class Garden {
  private:
    int counter; 
    vector<Plant*> plants;

  public:
    Garden();
    
    void addPlant(string type);
    void addMutablePlant(string type);
    int removePlant(int id);
    bool hasPlant(int id);
    Plant* getPlant(int id);
    vector<Plant*> getPlantList();

    Garden operator++(int);
    Garden operator+=(int amount);


    friend ostream& operator<<(ostream& os, const Garden& p);
};

#endif