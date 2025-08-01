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
    int id;
    int age;
    string type;
    double height;
    double growSpeed;

  public:
    Plant(string type, int id);
    
    int getAge() const;
    string getType() const;
    double getHeight() const;
    double getGrowSpeed() const;
    int getId() const;

    void setType(string type);

    void virtual grow(int amount);

    virtual double getPrice() const;
    
    virtual Plant& operator++(int);

    virtual Plant& operator+=(int amount);

    virtual string getName() const;

    friend ostream& operator<<(ostream& os, const Plant& p);
};

#endif