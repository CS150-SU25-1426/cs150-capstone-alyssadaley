#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include "plant.h"
#include "garden.h"
using namespace std;

int main() {
  Garden garden = Garden();

  int choice;
  double savings = 50;
  bool isRepeat = true;

  while (isRepeat) {
    cout << "      __/)    ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀    (\\__\n" << setw(49) << left << "   .-(__(=:   ❀" 
        << "❀   :=)__)-." << "\n|\\ |    \\)    ❀   Welcome to the greenhouse!   ❀    (/    | /|\n"
        << setw(49) << left << "\\ ||          ❀" << "❀          || /" << "\n  \\|          ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀          |/\n\n";

    cout << "What would you like to do? :)\n1) Plant something new (-$5.00)\n2) Plant something new but mutable! (try waiting after you plant these)  (-$5.00)\n3) Sell a plant \n4) Check plants + savings\n5) Pass time (1 year)\n6) Pass time (x years)\n";
    cin >> choice;

    switch (choice) {
      case 1: {
        if (savings < 5)
          cout << "\nYou're too broke for that!\n";
        else {

          string flowerChoice;
          cout << "\nWhat is the name of the flower? \n";
          cin >> flowerChoice;

          garden.addPlant(flowerChoice);
          //add plant to list
          savings -= 5;
        }
        break;
      }
      case 2: {
        if (savings < 5)
          cout << "\nYou're too broke for that!\n";
        else {

          string flowerChoice;
          cout << "\nWhat is the name of the flower? \n";
          cin >> flowerChoice;

          garden.addMutablePlant(flowerChoice);
          //add plant to list
          savings -= 5;
        }
        break;
      }
      case 3: {
        int flowerChoice;
        cout << "\nWhat is the id of the flower? \n";
        cin >> flowerChoice;
        if (garden.hasPlant(flowerChoice)) {
          //remove plant from list
          savings += garden.getPlant(flowerChoice)->getPrice();
          garden.removePlant(flowerChoice);
        } else {
          cout << "\nThat plant does not exist \n";
        }
        
        
        break;
      }
      case 4: {
        cout << garden << "Account Balance: $" << fixed << setprecision(2) << savings << "\n\n";
        break;
      }
      case 5: {
        garden ++;
        break;
      }
      case 6: {
        int years;
        cout << "\nHow long do you want to wait? \n";
        cin >> years;

        garden += years;
        break;
      }
      case 7: {
        isRepeat = false;
      }
    }
  }

  return 0;
}