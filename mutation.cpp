#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include "mutation.h"

Mutation::Mutation(int id): id(id) {};

string Mutation::getString() const {
        switch (id) {
            case 0:
                return "Golden";
            case 1:
                return "Wet";
            case 2:
                return "Moonlit";
            case 3:
                return "Chilled";
            case 4:
                return "Sandy";
            case 5:
                return "Frozen";
            case 6:
                return "Shocked";
            case 7:
                return "Celestial";
        }
        return "";
    } 

int Mutation::getMultiplier() const {
        switch (id) {
            case 0:
                return 20;
            case 1:
                return 2;
            case 2:
                return 2;
            case 3:
                return 2;
            case 4:
                return 3;
            case 5:
                return 10;
            case 6:
                return 100;
            case 7:
                return 120;
        }
        return 1;
    }

bool Mutation::operator==(const Mutation& other) {
        return id == other.id;
    }

ostream& operator<<(ostream& os, const Mutation& m) { 
        os << m.getString(); 
        return os; 
    }