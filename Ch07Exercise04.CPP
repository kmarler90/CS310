#include <iostream>
#include <string>
#include <cctype> // for islower

using namespace std;

// time to check for vowels, "a" "e" "i" "o" "u" need them to be banished
bool isVwl(char ch) {
    // Convert to lowercase for ease of comparison 
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Function to remove vowels from a string after it is entered to be expunged
string remvVwls(const string& inputStr) {
    string result = ""; // start a fresh string for input
    // Iterate through each character of the input string 
    for (char ch : inputStr) {
        // look for a vowel, and append it to the result string, banish any vowel to the shadows
        if (!isVwl(ch)) {
            result += ch; // if there is not a vowel append the character
        }
    }
    // Return the string with vowels taken out 
    return result;
}

int main() {
    string inputStr;

    cout << "Enter a string to banish vowels: ";
    getline(cin, inputStr); // Use getline to handle spaces in input

    // Check for empty input 
    if (inputStr.empty()) {
        cout << "Error: you need to enter a string for this dude." << endl;
        return 1; // if there is an error even if there shouldnt be
    }

    // Banish vowels from the input string
    string modifiedStr = remvVwls(inputStr);

    // Output the modified string
    cout << "String without vowels rejoice: " << modifiedStr << endl;

    return 0; // successful in exiling the vowels
}
