#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include "plant.h"
using namespace std;

int main() {
  int choice, savings = 50;

  cout << "❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀\n" << setw(35) << left << "❀" << "❀" << "\n❀   Welcome to the greenhouse!   ❀\n"
       << setw(35) << left << "❀" << "❀" << "\n❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀  ❀\n\n";

  cout << "What would you like to do? :)\n1) Plant something new (-$5.00)\n2) Sell a plant (+ $5.00)\n3) Check plants + savings\n4) Pass time (1 year)\n5) Pass time (x years)\n";
  cin >> choice;

  switch (choice) {
    case 1: {
      if (savings <= 0)
        cout << "\nYou're too broke for that!\n";
      else {
      //add plant to list
      savings -= 5;
      }
      break;
    }
    case 2: {
      //remove plant from list
      savings += 5;
      break;
    }
    case 3: {
      //display list
      break;
    }
    case 4: {
      //add year to all plants
      break;
    }
    case 5: {
      //add x years to all plants
      break;
    }
  }

  Plant plant1 = Plant("Hibiscus");
  cout << plant1;
  plant1++;
  cout << plant1;

  Plant plant2 = Plant("Daisy");
  cout << plant2;
  plant2 += 2;
  cout << plant2;

  return 0;
}