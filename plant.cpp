#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include "plant.h"

Plant::Plant(string type, int id) : age(0), type(type), height(rand() % 12 + 1), growSpeed(rand() % 24 / 8 + 1), id(id) {}

int Plant::getAge() const { return age; }
string Plant::getType() const { return type; }
double Plant::getHeight() const { return height; }
double Plant::getGrowSpeed() const { return growSpeed; }
int Plant::getId() const { return id; }

void Plant::setType(string type) { this->type = type; }

void Plant::grow(int amount) {
    age += amount;
    height += growSpeed * amount;
}

double Plant::getPrice() const {
    return 5;
}

Plant& Plant::operator++(int) {
    grow(1);
    return *this;
}

Plant& Plant::operator+=(int amount) {
    grow(amount);
    return *this;
}

string Plant::getName() const {
    return getType();
}

ostream& operator<<(ostream& os, const Plant& p) {
    os << "Id: " << p.id << ", Price: $" << fixed << setprecision(2) << p.getPrice() << ", Plant name: " << p.getName() << ", Age: " << p.age << " years, Height: " << p.height << " in., Growth speed: " << p.growSpeed << " in./year\n";
    return os;
}