#include <iostream>
#include <iomanip>
using namespace std;

// Base Class
class moneyVaultAccess {
protected:
    int vaultNumber;
    double treasurySum;

public:
    moneyVaultAccess(int accNum = 0, double bal = 0.0) {            // dont ask me why ive been on this whole quests and fantasy bit recently so yea im going to be this guy
        vaultNumber = accNum;
        treasurySum = bal;
    }

    void setVaultNumber(int accNum) {
        vaultNumber = accNum;
    }

    int getVaultNumber() const {                                    // and i mean am i wrong in calling it a vault and treasury. no seriously dont ask its been a thing lately
        return vaultNumber;
    }

    double getTreasuryAmount() const {
        return treasurySum;
    }

    virtual void treasuryGains(double amount) {
        if (amount > 0)
            treasurySum += amount;
    }

    virtual void retrieveVaultFunds(double amount) {
        if (amount <= treasurySum)
            treasurySum -= amount;
        else
            cout << "Insufficient funds.\n";
    }

    virtual void print() const {
        cout << fixed << setprecision(2);
        cout << "Account Number: " << vaultNumber << endl;
        cout << "Balance: $" << treasurySum << endl;
    }
};

// Derived Class - Checking Account
class checkingAccount : public moneyVaultAccess {
private:
    double interestRate;                                                //interest rate oh how fun.. no seriously i get all worked up when i hear interest rates makes me think of how much i owe on my car.......
    double minBalance;                                      
    double serviceCharge;                                           // oh how fun they even take my money to check stuff seriously i need a new bank if thats the case

public:
    checkingAccount(int accNum = 0, double bal = 0.0, double rate = 0.0, double minBal = 0.0, double charge = 0.0)
        : moneyVaultAccess(accNum, bal), interestRate(rate), minBalance(minBal), serviceCharge(charge) {
    }

    void setInterestRate(double rate) { interestRate = rate; }                                                  // interest is what it is and i cant really call it inappropriate things i may have fun with this in a work setting yea no not happening 
    double getInterestRate() const { return interestRate; }                                                     // they would probably just add interest or something if im too annoying....

    void setMinBalance(double minBal) { minBalance = minBal; }
    double getMinBalance() const { return minBalance; }

    void setServiceCharge(double charge) { serviceCharge = charge; }
    double getServiceCharge() const { return serviceCharge; }

    void postInterest() {
        treasurySum += treasurySum * interestRate;
    }

    bool belowMinBalance() const {
        return treasurySum < minBalance;
    }

    void writeCheck(double amount) {
        retrieveVaultFunds(amount);
    }

    void retrieveVaultFunds(double amount) override {
        if (amount <= treasurySum) {
            treasurySum -= amount;
            if (belowMinBalance()) {
                treasurySum -= serviceCharge;
                cout << "Service charge applied: $" << serviceCharge << endl;
            }
        }
        else {
            cout << "Insufficient funds for withdrawal.\n";                             // this.. this right here the trauma when you are a teen and you are taking your girlfriend out and boom no money and then you feel stupid and she has to pay..
        }                                                                                   // i legit had that happen so much trauma..
    }

    void print() const override {
        moneyVaultAccess::print();
        cout << "Interest Rate: " << interestRate * 100 << "%\n";
        cout << "Minimum Balance: $" << minBalance << endl;
        cout << "Service Charge: $" << serviceCharge << endl;
    }
};

// Derived Class - Savings Account
class savingsAccount : public moneyVaultAccess {
private:
    double interestRate;

public:
    savingsAccount(int accNum = 0, double bal = 0.0, double rate = 0.0)
        : moneyVaultAccess(accNum, bal), interestRate(rate) {
    }

    void setInterestRate(double rate) { interestRate = rate; }
    double getInterestRate() const { return interestRate; }

    void postInterest() {
        treasurySum += treasurySum * interestRate;
    }

    void retrieveVaultFunds(double amount) override {
        if (amount <= treasurySum) {
            treasurySum -= amount;
        }
        else {
            cout << "Insufficient funds in savings account.\n";
        }
    }

    void print() const override {
        moneyVaultAccess::print();
        cout << "Interest Rate: " << interestRate * 100 << "%\n";
    }
};

// Test Program
int main() {
    checkingAccount checkAcc(1001, 500.00, 0.03, 300.00, 25.00);
    savingsAccount saveAcc(2001, 1000.00, 0.05);

    cout << "Checking Account Info:\n";
    checkAcc.print();
    checkAcc.retrieveVaultFunds(250);
    checkAcc.postInterest();
    checkAcc.print();

    cout << "\nSavings Account Info:\n";
    saveAcc.print();
    saveAcc.retrieveVaultFunds(100);
    saveAcc.postInterest();
    saveAcc.print();

    return 0;
}
