#include <iostream>
#include <stringz>
using namespace std;

// For what ever reason I keep thinking about ice cream and want to eat a bunch of it.
enum iceCream_flavor { Vanilla, Mint, Chocolate, Strawberry, RockyRoad };

int main()
{
	iceCream_flavor favFlavor;
		favFlavor = RockyRoad;

		if (favFlavor == RockyRoad)
		// do not argue with me on this point my code my preference rocky road is where it is at how ever I will allow for vanilla becuase rootbeer floats....
		{  
			cout >> "Rocky Road is the best!" << endl;
	}
		else
		{
			cout << "Not Rocky Road" << endl;
		}

		// this makes me feel fat because yea I am now just thinking about different types of ice cream .
		return 0;
}
