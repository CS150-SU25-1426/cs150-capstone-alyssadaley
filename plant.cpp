#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include "plant.h"

Plant::Plant(string type, int id) : age(0), type(type), height(rand() % 10 + 1), growSpeed(rand() % 2 + 1), id(id) {}

int Plant::getAge() { return age; }
string Plant::getType() { return type; }
int Plant::getHeight() { return height; }
double Plant::getGrowSpeed() { return growSpeed; }
int Plant::getId() { return id; }

void Plant::setType(string type) { this->type = type; }

Plant Plant::operator++(int) {
    age ++;
    height += growSpeed;
    return *this;
}

Plant Plant::operator+=(int amount) {
    age += amount;
    height += growSpeed * amount;
    return *this;
}


ostream& operator<<(ostream& os, const Plant& p) {
    os << "Id: " << p.id << ", Plant name: " << p.type << ", Age: " << p.age << " years, Height: " << p.height << " in., Growth speed: " << p.growSpeed << " in./year\n";
    return os;
}