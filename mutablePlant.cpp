#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include "mutablePlant.h"


MutablePlant::MutablePlant(string type, int id) : Plant(type, id) {};

void MutablePlant::roll() {
      for (int i = 0; i < mutationCount; i++) {
        if ((rand() % getChance(i)) == 0) {
          Mutation newMutation = Mutation(i);
          cout << "Your " << getType() << " got a " << newMutation.getString() << " mutation!!\n";
          mutations.push_back(newMutation);
        }
      }
    }

double MutablePlant::getPrice() const {
    double price = getHeight();
    for (int i = 0; i < mutations.size(); i++) {
        price *= mutations[i].getMultiplier();
    }
    return price;
}

Plant& MutablePlant::operator++(int) {
    Plant::grow(1);
    roll();
    return *this;
}

Plant& MutablePlant::operator+=(int amount) {
    Plant::grow(amount);
    for (int i = 0; i < amount; i++) {
    roll();
    }
    return *this;
}

string MutablePlant::getName() const {
    string s = "";
    for (int i = 0; i < mutations.size(); i++) {
        s += mutations[i].getString() + " ";
    }
    s += getType();
    return s;
}