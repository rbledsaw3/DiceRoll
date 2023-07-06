 /* This function is used to simulate the rolling of one or several
  * polyhedral dice according to a uniform_int_distribution. Basically,
  * it's Lou Zhocchi Gamescience dice in code form xD
  */

#include <iostream>
#include <random>

int roll(int diceQty, int diceSides) {
    std::random_device rDev; //initiates a random device
    
    //set the distribution bounds to the total number of die sides
    std::uniform_int_distribution<int> dist(1, diceSides); 

    int results = 0;
    //sum the total number of die rolls
    for(int i = 0; i < diceQty; ++i) {
        results += dist(rDev);
    }

    return results;
}

int main() {
    std::cout << "Rolling 1d4: " << roll(1, 4) << "\n";
    std::cout << "Rolling 2d4: " << roll(2, 4) << "\n";
    std::cout << "Rolling 3d4: " << roll(3, 4) << "\n";
    std::cout << "Rolling 4d4: " << roll(4, 4) << "\n";
    std::cout << "Rolling 1d6: " << roll(1, 6) << "\n";
    std::cout << "Rolling 2d6: " << roll(2, 6) << "\n";
    std::cout << "Rolling 3d6: " << roll(3, 6) << "\n";
    std::cout << "Rolling 4d6: " << roll(4, 6) << "\n";
    std::cout << "Rolling 1d8: " << roll(1, 8) << "\n";
    std::cout << "Rolling 2d8: " << roll(2, 8) << "\n";
    std::cout << "Rolling 3d8: " << roll(3, 8) << "\n";
    std::cout << "Rolling 4d8: " << roll(4, 8) << "\n";
    std::cout << "Rolling 1d10: " << roll(1, 10) << "\n";
    std::cout << "Rolling 2d10: " << roll(2, 10) << "\n";
    std::cout << "Rolling 3d10: " << roll(3, 10) << "\n";
    std::cout << "Rolling 4d10: " << roll(4, 10) << "\n";
    std::cout << "Rolling 1d12: " << roll(1, 12) << "\n";
    std::cout << "Rolling 2d12: " << roll(2, 12) << "\n";
    std::cout << "Rolling 1d20: " << roll(1, 20) << "\n";
    std::cout << "Rolling 1d100: " << roll(1, 100) << "\n";

    return 0;
}
