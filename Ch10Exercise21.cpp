#include <iostream>
#include <string>
#include <iomanip>

class bnkAcnt {
private:
    std::string acntHldrNme;
    int accntNum;
    std::string acntTyp; // what type of account type are we working with
    double blnce;
    double intrstRte; // stored as a decimal for intrest (e.g., 0.05 for 5%)

    static int nxtAcntNum; // static member to auto-assign account numbers

public:
    // Constructor
    bnkAcnt(std::string name = "", std::string type = "checking", double initialBalance = 0.0, double rate = 0.0)
        : acntHldrNme(name), acntTyp(type), blnce(initialBalance), intrstRte(rate) {
        accntNum = nxtAcntNum++;
    }

    // this is the function for deposits
    void deposit(double amount) {
        if (amount > 0) {
            blnce += amount;
        }
    }

    // this function is for withdrawing funds
    void withdraw(double amount) {
        if (amount > 0 && amount <= blnce) {
            blnce -= amount;
        }
        else {
            std::cout << "Insufficient funds or invalid amount.\n";
        }
    }

    // this function is to apply interest
    void aplyIntrst() {
        blnce += (blnce * intrstRte);
    }

    // Function to display account details
    void displAccnt() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Account Holder: " << acntHldrNme << "\n"
            << "Account Number: " << accntNum << "\n"
            << "Account Type: " << acntTyp << "\n"
            << "Balance: $" << blnce << "\n"
            << "Interest Rate: " << intrstRte * 100 << "%\n"
            << "-------------------------\n";
    }
};

// Initialize static member variable for accounts
int bnkAcnt::nxtAcntNum = 1001;

int main() {
    const int NUM_CUSTOMERS = 10;
    bnkAcnt customers[NUM_CUSTOMERS] = {
        {"Amanda", "checking", 1500.0, 0.02},
        {"Bobby", "saving", 3000.0, 0.03},
        {"Juanita", "checking", 2200.0, 0.01},
        {"Hans", "saving", 5000.0, 0.04},
        {"Erika", "checking", 1000.0, 0.015},
        {"Franky", "saving", 7000.0, 0.05},
        {"Freya", "checking", 800.0, 0.01},
        {"Hill", "saving", 2000.0, 0.025},
        {"Harleen", "checking", 600.0, 0.01},
        {"Jackie", "saving", 10000.0, 0.035}
    };

    // Apply interest and display all customer accounts becuase money now
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        customers[i].aplyIntrst();
        customers[i].displAccnt();
    }

    return 0;
}
