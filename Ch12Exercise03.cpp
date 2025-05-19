#include <iostream>
#include <string>
#include <iomanip> // for that nice setprecision

using namespace std;

int main() {
    // Let's figure out how many folks are running in this election.
    int numberOfContestants;
    cout << "Alright, how many candidates are we tracking? ";
    cin >> numberOfContestants;

    // We'll need some space to keep track of each candidate's name and their vote count.
    // Since we don't know the number of candidates until runtime, we'll grab some memory dynamically.
    string* contestantNames = new string[numberOfContestants];
    int* voteTallies = new int[numberOfContestants];

    // Time to get the scoop on each candidate.
    for (int i = 0; i < numberOfContestants; ++i) {
        cout << "\nLet's get the name for candidate #" << (i + 1) << ": ";
        cin.ignore(); // Gotta clear that newline character from the previous input.
        getline(cin, contestantNames[i]);

        cout << "And how many votes did " << contestantNames[i] << " pull in? ";
        cin >> voteTallies[i];
    }

    // Now, let's tally up all the votes to get the grand total.
    int allVotesCast = 0;
    for (int i = 0; i < numberOfContestants; ++i) {
        allVotesCast += voteTallies[i];
    }

    // Time to present the results in a clear and readable format.
    cout << "\n--- Election Results ---\n";
    cout << left << setw(20) << "Candidate" << setw(10) << "Votes" << setw(15) << "Percentage" << endl;
    cout << fixed << setprecision(2); // Let's keep those percentages nice and tidy with two decimal places.

    // Loop through each candidate and display their results.
    for (int i = 0; i < numberOfContestants; ++i) {
        double votePercentage = (static_cast<double>(voteTallies[i]) / allVotesCast) * 100;
        cout << left << setw(20) << contestantNames[i] << setw(10) << voteTallies[i] << votePercentage << "%" << endl;
    }

    // Don't forget to show the total number of votes cast.
    cout << "\nTotal votes counted: " << allVotesCast << endl;

    // Since we grabbed memory dynamically earlier, it's good practice to release it when we're done.
    delete[] contestantNames;
    delete[] voteTallies;

    return 0; // Everything went smoothly!
}
