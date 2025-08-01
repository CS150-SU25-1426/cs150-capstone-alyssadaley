#include "garden.h"
#include "plant.h"
#include "mutablePlant.h"

Garden::Garden(): counter(0), plants(vector<Plant*>()) {};
    
void Garden::addPlant(string type) {
    plants.push_back(new Plant(type, counter));
    counter++;
};

void Garden::addMutablePlant(string type) {
    plants.push_back(new MutablePlant(type, counter));
    counter++;
};

int Garden::removePlant(int id) {
    for (int i = 0; i < plants.size(); i++) {
        if (plants[i]->getId() == id) {
            plants.erase(plants.begin() + i);
            return 1;
        }
    }
    return 0;
};

bool Garden::hasPlant(int id) {
    for (int i = 0; i < plants.size(); i++) {
        if (plants[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

Plant* Garden::getPlant(int id) {
    for (int i = 0; i < plants.size(); i++) {
        if (plants[i]->getId() == id) {
            return plants[i];
        }
    }
    return nullptr;
};

vector<Plant*> Garden::getPlantList() { 
    return plants; 
};

Garden Garden::operator++(int) {
    for (int i = 0; i < plants.size(); i++) {
        (*plants[i])++;
    }
    return *this;
};

Garden Garden::operator+=(int amount) {
    for (int i = 0; i < plants.size(); i++) {
        (*plants[i]) += amount;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Garden& g) {
            //       __/)
            //    .-(__(=:
            // |\ |    \)
            // \ ||
            //  \||
            //   \|
            //    |

        //     (\__
        //    :=)__)-.
        //     (/    | /|
        //           || /
        //           ||/
        //           |/
        //           |


    os << "      __/)    ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀    (\\__\n" << setw(49) << left << "   .-(__(=:   ❀" 
        << "❀   :=)__)-." << "\n|\\ |    \\)    ❀   Welcome to the greenhouse!   ❀    (/    | /|\n"
        << setw(49) << left << "\\ ||          ❀" << "❀          || /" << "\n  \\|          ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀          |/\n\n";

    for (int i = 0; i < g.plants.size(); i++) {
        os << *g.plants[i];
    }
    os << "\n\n";
    return os;
};