#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
using namespace std;

class Plant {
  private:
    int age;
    string type;
    int height;
    double growSpeed;

  public:
    Plant(string type);
    
    int getAge();
    string getType();
    int getHeight();
    double getGrowSpeed();

    void setType(string type);

    Plant operator++(int);

    Plant operator+=(int amount);

    friend ostream& operator<<(ostream& os, const Plant& p);
};

#endif