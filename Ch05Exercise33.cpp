#include <iostream>

int main() {
    int a, b, t;

    
    std::cout << "Enter the cooking time for the first dish (a): ";
    std::cin >> a;

    std::cout << "Enter the additional cooking time for each subsequent dish (b): ";
    std::cin >> b;

    std::cout << "Enter the total time available to cook (t): ";
    std::cin >> t;

    int numDishes = 0;
    int currentTime = 0;
    int timeForDish = a;

    while (currentTime + timeForDish <= t) {
        currentTime += timeForDish;
        numDishes++;
        timeForDish += b;
    }

    std::cout << "Bianca can cook " << numDishes << " dishes." << std::endl;

    return 0;
}
