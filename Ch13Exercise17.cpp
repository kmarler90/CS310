#include <iostream>   
#include <random>     
#include <iomanip>    

                        // Not explicitly using 'using namespace std;' here, as some folks prefer
                        // to keep the 'std::' prefix for clarity, especially in larger projects.
                        // But for a small demo like this, it's often used. Let's stick with explicit std:: for now.

int main() {
                         // Alright, let's get our random number generator ready.  This wishes it was as random as i am lol.
                         // Think of 'random_device' as a super-duper random seed provider,
                         // getting truly unpredictable bits from the system if possible. the only thing more unpredictable is my ex wooo boy that was not fun.
    std::random_device trulyRandomSource;
                         // 'mt19937' is a Mersenne Twister engine, a really good quality
                        // pseudo-random number generator. We seed it with our 'trulyRandomSource'.
    std::mt19937 numberGenerator(trulyRandomSource());
                        // And finally, 'uniform_real_distribution' ensures our numbers
                        // are spread evenly across a specific range. We want them between 10.0 and 100.0 (exclusive of 100.0).
    std::uniform_real_distribution<> distributionRange(10.0, 100.0);

                         // Let's set up our output so the numbers look nice and tidy, unlike my mental health kidding,
                        // always showing two decimal places.
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Time to whip up 25 random decimal numbers, somewhere between 10 and 100 (not including 100, mind you):\n\n";

                        // Now for the main event: cranking out those numbers!  i feel like the boxer announcer with the lets get ready to rumble lol.
    for (int i = 1; i <= 25; ++i) {
                        // Generate a single random number using our setup.
        double aRandomNumber = distributionRange(numberGenerator);
                        // Print it out, making sure each number takes up 8 spaces for neat alignment.
        std::cout << std::setw(8) << aRandomNumber;

                        // A little formatting touch: print 5 numbers, then start a new line.
                        // Makes the output much easier on the eyes.  and im already half blind well i wear glasses so lets not kill me with more eye strain.
        if (i % 5 == 0) {
            std::cout << std::endl;
        }
    }

                        // All done!
    return 0;
}
