//
//  main.cpp
//  AssignmentOne
//
//  Created by Mark Calvelo on 10/22/20.
//

#include <iostream>
#include <string>
#include <fstream> // for use of the istream file reading
#include "vector.h" // Custom Library for Vectors
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
            result += text[i];
        }
    }
    return result;
}

// void CensorString2 (string &text, string remove) {
//
//}

/* CalculateStatistics()
 * Usage: stats = CalculateStatistics(filename)
 * --------------------------------------------
 * This function keeps track of the running low/high value
 * as it reads the file, as well as a total and a count to compute
 * the average when we're done
 */

// C++ Structure is a collection of different data types.
struct statsT {
    int low;
    int high;
    double average;
};

statsT CalculateStatistics (string filename) {
    statsT stats;
    // statistics are always between percentiles of 0 to 100
    // we set the instance of statsT stats low and high properties accordingly
    stats.low = 101; // exclude this high number from range
    stats.high = -1; // exclude this low number from range
    
    int total = 0;
    int count = 0;
    
    // ifstream is from the std library
    // file open for reading: the internal stream buffer supports input operations.
    ifstream in;
    // std::string::c_str
    // Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
    in.open(filename.c_str());
    // std::ios::fail
    // Returns true if either (or both) the failbit or the badbit error state flags is set for the stream.
    if (in.fail()) {
        throw runtime_error("Cannot read the file called " + filename);
    }
    
    do {
        int num;
        in >> num; // insert the input from in into the integer num
        // We should make sure that the file input is read successfully
        if (in.fail()) {
            break; // break out if the file fails to be read
        }
        // We should update our data as needed
        if (num < stats.low) {
            stats.low = num;
        }
        if (num > stats.high) {
            stats.high = num;
        }
        total += num;
        count += 1; // how many data inputs we have gone through
    } while (true); // if while true is used, ensure you have BREAK conditions set!
    
    stats.average = double(total) / count; // cast the average to a double type
    in.close(); // close all files once finished
    
    return stats;
};



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

const int AlphabetLength = 26; // only have 26 letters

void CountLetters(string filename) {
    // let us open up the filestream first and check it opened correctly
//    ifstream in;
//    in.open(filename.c_str());
//    if (in.fail()) {
//        throw runtime_error("Cannot read file called " + filename);
//    }
//    
//    Vector<int> result;
};

int main(int argc, const char * argv[]) {
    string censorString1Result1 = CensorString1("Stanford University", "nt");
    string censorString1Result2 = CensorString1("Llamas like to laugh" , "la");
    cout << censorString1Result1 << "\n";
    cout << censorString1Result2 << endl;
    return 0;
}
