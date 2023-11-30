/* This function is used to simulate the rolling of one or several
 * polyhedral dice according to a uniform_int_distribution. Basically,
 * it's Lou Zhocchi Gamescience dice in code form xD
 */

#include "DiceRoll.hpp"

int roll(DiceQty diceQty, DiceSides diceSides) {
  if (diceQty.value < 1) {
    std::cerr << "Error: dice quantity cannot be less than 1. Defaulting to 1." << std::endl;
    diceQty.value = 1;
  }
  if (diceSides.value < 2) {
    std::cerr << "Error: dice sides cannot be less than 2. Defaulting to 2." << std::endl;
    diceSides.value = 2;
  }

  std::random_device rDev;  // initiates a random device

  // set the distribution bounds to the total number of die sides
  std::uniform_int_distribution<int> dist(1, diceSides.value);

  int results = 0;
  // sum the total number of die rolls
  for (int i = 0; i < diceQty.value; ++i) {
    results += dist(rDev);
  }

  return results;
}

std::ostream& operator<<(std::ostream& out, const RollResultProxy& roll) {
  out << "Rolled" << roll.diceQty.value << "d" << roll.diceSides.value << ": " << roll.result;
  return out;
}

int main() {
  for (int i = 4; i <= 12; i += 2) {
    for (int j = 1; j <= 4; ++j) {
      std::cout << "Rolling " << j << "d" << i << ": " << roll(DiceQty(j), DiceSides(i)) << "\n";
    }
  }
  for (int i = 20; i <= 100; i += 80) {
    for (int j = 1; j <= 4; ++j) {
      std::cout << "Rolling " << j << "d" << i << ": " << roll(DiceQty(j), DiceSides(i)) << "\n";
    }
  }

  return 0;
}
