#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double OPTION1_DELIVERY = 5000.00;
    const double OPTION1_PUBLISHED = 20000.00;
    const double OPTION2_ROYALTY_RATE = 0.125;
    const double OPTION3_ROYALTY_RATE_FIRST = 0.10;
    const double OPTION3_ROYALTY_RATE_OVER = 0.14;
    const int OPTION3_THRESHOLD = 4000;

    double netPrice;
    int estimatedCopies;
    double option1Royalty, option2Royalty, option3Royalty;
    int bestOption = 0; // 0 indicates no best option yet

    cout << "Enter the net price of each copy: $";
    cin >> netPrice;

    cout << "Enter the estimated number of copies to be sold: ";
    cin >> estimatedCopies;

    // Calculate royalties for each option
    option1Royalty = OPTION1_DELIVERY + OPTION1_PUBLISHED;

    option2Royalty = estimatedCopies * netPrice * OPTION2_ROYALTY_RATE;

    if (estimatedCopies <= OPTION3_THRESHOLD) {
        option3Royalty = estimatedCopies * netPrice * OPTION3_ROYALTY_RATE_FIRST;
    } else {
        option3Royalty = OPTION3_THRESHOLD * netPrice * OPTION3_ROYALTY_RATE_FIRST +
                         (estimatedCopies - OPTION3_THRESHOLD) * netPrice * OPTION3_ROYALTY_RATE_OVER;
    }

    // Determine the best option
    double maxRoyalty = option1Royalty;
    bestOption = 1;

    if (option2Royalty > maxRoyalty) {
        maxRoyalty = option2Royalty;
        bestOption = 2;
    }

    if (option3Royalty > maxRoyalty) {
        maxRoyalty = option3Royalty;
        bestOption = 3;
    }

    // Output royalties and best option
    cout << fixed << setprecision(2);
    cout << "\nRoyalties:\n";
    cout << "Option 1: $" << option1Royalty << endl;
    cout << "Option 2: $" << option2Royalty << endl;
    cout << "Option 3: $" << option3Royalty << endl;

    cout << "\nBest Option: ";

    switch (bestOption) {
        case 1:
            cout << "Option 1" << endl;
            break;
        case 2:
            cout << "Option 2" << endl;
            break;
        case 3:
            cout << "Option 3" << endl;
            break;
        default:
            cout << "Cannot determine best option" << endl;
    }

    return 0;
}
