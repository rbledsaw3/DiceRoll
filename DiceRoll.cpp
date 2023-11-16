 /* This function is used to simulate the rolling of one or several
  * polyhedral dice according to a uniform_int_distribution. Basically,
  * it's Lou Zhocchi Gamescience dice in code form xD
  */

#include <iostream>
#include <random>

struct DiceQty {
    int value;
    explicit DiceQty(int qty) : value(qty) {}
};

struct DiceSides {
    int value;
    explicit DiceSides(int sides) : value(sides) {}
};

int roll(DiceQty diceQty, DiceSides diceSides) {
    std::random_device rDev; //initiates a random device
    
    //set the distribution bounds to the total number of die sides
    std::uniform_int_distribution<int> dist(1, diceSides.value); 

    int results = 0;
    //sum the total number of die rolls
    for(int i = 0; i < diceQty.value; ++i) {
        results += dist(rDev);
    }

    return results;
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
