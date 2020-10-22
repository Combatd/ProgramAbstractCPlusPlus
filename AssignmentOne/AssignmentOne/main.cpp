//
//  main.cpp
//  AssignmentOne
//
//  Created by Mark Calvelo on 10/22/20.
//

#include <iostream>
#include <string>
using namespace std;

/* Function: CensorString
 * Usage: s = CensorString(input, remove);
 * ----------------------------------------------
 * This function takes two strings and returns the first string with
 * all the occurrences of letters in the second string removed.
 * It uses a double for loop to iterate through the string testing each
 * character to see if it matches any of the letters to remove, and
 * building the resultant string character by character.
 */

string CensorString1(string text, string remove) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        bool secondStringFound = false;
        for (int j = 0; j < remove.length(); j++) {
            if (text[i] == remove[j]) {
                secondStringFound = true;
                break; // break out before we add to the result string
            }
        }
        if (!secondStringFound) {
            // concatenate to the result if the string remove is not found
            result += text;
        }
    }
    return result;
}

/* CalculateStatistics()
 * Usage: stats = CalculateStatistics(filename)
 * --------------------------------------------
 * This function keeps track of the running low/high value
 * as it reads the file, as well as a total and a count to compute
 * the average when we're done
 */

//void CensorString2 (string &text, string remove) {
//
//}

/*
 Write a function CountLetters that takes a filename and prints the number of times
 each letter of the alphabet appears in that file. Because there are 26 numbers to be
 printed, CountLetters needs to create a Vector. For example, if the file is:
 Abcd K..
 ijk;;
 cab-Bage
 fad
 CountLetters should print the following:
 a: 4
 b: 3
 c: 2
 d: 2
 ...
 z: 0
 When you really print this out, it should be 26 elements long, but we couldn't easily
 display that on the page. Note that there may be upper case letters, lower case letters, and
 non-letter characters in the file. All letters should be counted regardless of case (so “Aa”
 is two a’s), and non-alphabetic characters should be ignored. You should use the
 following prototype.
 void CountLetters(string filename);
 */

int main(int argc, const char * argv[]) {
//    string censorString1Result1 = CensorString1("Stanford University", "nt");
//    string censorString1Result2 = CensorString1("Llamas like to laugh" , "la");
//    cout << censorString1Result1 << "\n";
//    cout << censorString1Result2 << endl;
    return 0;
}
