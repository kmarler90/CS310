//steps tracker per day.

#include <Iostream>

using namespace ;

int main()
{
	int stepWalkedDay1, stepWalkedDay2, stepWalkedDay3,
		stepWalkedDay4, stepWalkedDay5, stepWalkedDay6,
		stepWalkedDay7;
	int stepWalkedInAWeek;

	cout << "Please enter the number of steps for day 1:";
	cin >> stepWalkedDay1;
	cout << endl;

	cout << "Please enter the number of steps for day 2:";
	cin >> stepWalkedDay2;
	cout << endl;

	cout << "Please enter the number of steps for day 3:";
	cin >> stepWalkedDay3;
	cout << endl;

	cout << "Please enter the number of steps for day 4:";
	cin >> stepWalkedDay4;
	cout << endl;

	cout << "Please enter the number of steps for day 5:";
	cin >> stepWalkedDay5;
	cout << endl;

	cout << "Please enter the number of steps for day 6:";
	cin >> stepWalkedDay6;
	cout << endl;
	cout << "Please enter the number of steps for day 7:";
	cin >> stepWalkedDay7;
	cout << endl;

	stepWalkedInAWeek = stepWalkedDay1 + stepWalkedDay2 + stepWalkedDay3
					  + stepWalkedDay4 + stepWalkedDay5 + stepWalkedDay6
					  + stepWalkedDay7;

	cout << "Average number of steps every day: "
		 << stepWalkedInAWeek / 7 << endl;

	return 0;
}
