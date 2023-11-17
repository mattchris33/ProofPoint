#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isValidSentence(const string& sentence) {
    int numQuote = 0;
    bool lastPeriod = false;

    // Check whether the sentence starts with a capital letter (case-insensitive).
    if (!isupper(sentence.front())) {
        return false;
    }

    // Check through the characters by looping.
    for (int i = 0; i < sentence.size(); ++i) { // you can use an alternative syntax for the loop, which is for (char s : sentence)
        char s = sentence[i];
        if (s == '"') {
            ++numQuote;
        } 
        else if (ispunct(s)) {
            if (s == '.' || s == '?' || s == '!') {
                lastPeriod = true;
            } else {
                lastPeriod = false;
            }
        }
    }

    // Check if the number of quotation marks is even.
    if (numQuote % 2 != 0) {
        return false;
    } 

    // Check if the sentence has the character '1' - '12'
    for(int i = 0; i < sentence.size(); i++){
        char sen = sentence[i];
        if(sen == '1' || sen == '2' || sen == '3' || sen == '4' || sen == '5' || sen == '6' || sen == '7' || sen == '8' || sen == '9' || sen == '10' || sen == '11' || sen == '12'){
            return false;
        } else {
            return true;
        }
    }

    // Check if the last character is a valid sentence termination character.
    if (!lastPeriod) {
        return false;
    }

    return true;
}

int main() {
    // Test cases
    cout << boolalpha; // Print bool values as true/false

    cout << isValidSentence("The quick brown fox said “hello Mr lazy dog”.") << endl; // Valid
    cout << isValidSentence("The quick brown fox said hello Mr lazy dog.") << endl; // Valid
    cout << isValidSentence("One lazy dog is too few, 13 is too many.") << endl; // Valid
    cout << isValidSentence("One lazy dog is too few, thirteen is too many.") << endl; // Valid
    cout << isValidSentence("How many “lazy dogs“ are there?") << endl; // Valid
    cout << isValidSentence("The quick brown fox said \"hello Mr. lazy dog\".") << endl; // Valid
    cout << isValidSentence("the quick brown fox said “hello Mr lazy dog\".") << endl; // Invalid
    cout << isValidSentence("\"the quick brown fox said “hello Mr lazy dog\".") << endl; // Invalid
    cout << isValidSentence("One lazy dog is too few, 12 is too many.") << endl; // Invalid
    cout << isValidSentence("Are there 11, 12, or 13 lazy dogs?") << endl; // Invalid
    cout << isValidSentence("There is no punctuation in this sentence") << endl; // Invalid

    return 0;
}
