#include <iostream>

using namespace std;

// function to calculate service fees based on the customers income and the time spent.  sadly no annoying customer fees!
double calculateServiceCharge(double hFee, int svcTime, bool isLowInc) {
	double serviceCharge = 0.0;

	// if the customer is low income and consultaion is more than 30 minutes. then bring in the big bucks
	if (isLowInc) {
		if (svcTime > 30) {
			serviceCharge = hFee * 0.40 * ((svcTime - 30.0) / 60.0);
		}
	}
	else {
		if (svcTime > 20) {
			serviceCharge = hFee * 0.70 * ((svcTime - 20.0) / 60.0);
		}
	}

	return serviceCharge;
}

int main() {
	double hFee;
	int svcTime;
	bool isLowInc;

	// user inputs for calculations to hopefully get the right results
	cout << "Please input current hourly fee: ";
	cin >> hFee;

	cout << "Please input the total service time in minutes: ";
	cin >> svcTime;

	cout << "Is this customer low income (y/n)? ";
	cin >> isLowInc;

	// calculate for the time over 30 minutes and charge the fee
	double serviceCharge = calculateServiceCharge(hFee, svcTime, isLowInc);

	// output total results and pray for good news!
	cout << "The total bill for service is: $" << serviceCharge << endl;

	return 0;
}
