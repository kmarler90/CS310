#include <iostream>
#include <string>
#include <limits>
#include <ios>

// Thrown when the user enters a negative value
class NegativeNumber : public std::runtime_error {
public:
    NegativeNumber(const std::string& msg) : std::runtime_error(msg) {}
};

// Thrown when the user enters something that isn't a number
class NonNumber : public std::runtime_error {
public:
    NonNumber(const std::string& msg) : std::runtime_error(msg) {}
};

// Generic input helper with basic validation
template <typename T>
T getInput(const std::string& prompt) {
    T input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (std::cin.fail()) {
            throw NonNumber("Oops, that wasn't a number.");
        } else if (input < 0) {
            throw NegativeNumber("No negative values, please.");
        } else {
            return input;
        }
    }
}

int main() {
    const double FEET_TO_CM = 30.48;
    const double INCH_TO_CM = 2.54;

    double feet = 0;
    double inches = 0;
    bool runAgain = true;

    while (runAgain) {
        bool gotValidInput = false;

        while (!gotValidInput) {
            try {
                feet = getInput<double>("Feet: ");
                inches = getInput<double>("Inches: ");
                gotValidInput = true;
            } catch (const NonNumber& err) {
                std::cerr << "Error: " << err.what() << "\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Let's try that again.\n\n";
            } catch (const NegativeNumber& err) {
                std::cerr << "Error: " << err.what() << "\n";
                std::cout << "Try again with a positive number.\n\n";
            } catch (const std::exception& err) {
                std::cerr << "Something went wrong: " << err.what() << "\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Resetting input...\n\n";
            }
        }

        double cmTotal = (feet * FEET_TO_CM) + (inches * INCH_TO_CM);

        std::cout << "\n===========================\n";
        std::cout << feet << " ft + " << inches << " in = " << cmTotal << " cm\n";
        std::cout << "===========================\n\n";

        char again = 'n';
        bool validChoice = false;

        while (!validChoice) {
            std::cout << "Do another conversion? (y/n): ";
            std::cin >> again;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Just type 'y' or 'n'.\n";
            } else {
                again = std::tolower(again);
                if (again == 'y') {
                    validChoice = true;
                } else if (again == 'n') {
                    runAgain = false;
                    validChoice = true;
                } else {
                    std::cerr << "Please enter 'y' or 'n'.\n";
                }
            }
        }

        std::cout << "\n";
    }

    std::cout << "All done. Thanks for using the converter!\n";
    return 0;
}
