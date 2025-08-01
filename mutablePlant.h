#ifndef MUTABLEPLANT_H
#define MUTABLEPLANT_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include "plant.h"
#include "mutation.h"
using namespace std;

class MutablePlant : public Plant {
  private:
    vector<Mutation> mutations;

  public:
    MutablePlant(string type, int id);

    void roll();

    double getPrice() const override;

    Plant& operator++(int) override;

    Plant& operator+=(int amount) override;

    string getName() const override;
};

#endif