#ifndef MUTATION_H
#define MUTATION_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>

using namespace std;


class Mutation {
  private:
    int id;

  public:
    Mutation(int id);
    
    int getId() { return id; }
    void setId(int id) { this->id = id; }

    string getString() const;

    int getMultiplier() const;

    bool operator==(const Mutation& other);

    friend ostream& operator<<(ostream& os, const Mutation& m);
};

static const int mutationCount = 8;

// chances are given by 1 / <out of #>
static int getChance(int id) {
    switch (id) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 15;
        case 5:
            return 50;
        case 6:
            return 500;
        case 7:
            return 1000;
    }
    return 0;
}

#endif