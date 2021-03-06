//
//  main.cpp
//  SoundexStrings
//
//  Created by Mark Calvelo on 10/28/20.
//

/*
 All Soundex codes have the same format (an uppercase letter followed by three digits e.g. Z452 or
 V200). The Soundex algorithm converts a surname to a code using these steps:
 1. Keep the first letter of the surname (convert to uppercase if necessary)
 2. Convert all other letters in the surname to a digit using the table below (discard any nonletter characters: dashes, spaces, and so on)
 
 
 0 A E I O U H W Y
 1 B F P V
 2 C G J K Q S X Z
 3 D T
 4 M N
 5 L
 6 R
 
 
 3. Remove any consecutive duplicate digits (e.g. A122235 becomes A1235)
 4. Remove any zeros
 5. Make resulting code exactly length 4 by truncating or padding with zeros
 
 Write a program that allows the user to enter a name and prints its Soundex code as determined by
 the above algorithm. It should operate in a loop that allows the user to get codes for as many names
 as desired before exiting. A sample run of the program is shown below:
 
 Enter surname (RETURN to quit): Vaska
 Soundex code for Vaska is V200
 Enter surname (RETURN to quit): Zelenski
 Soundex code for Zelenski is Z452
 Enter surname (RETURN to quit):
 */

#include <iostream>
#include "lib/genlib.h"
#include "lib/simpio.h"
#include <string>
#include "lib/strutils.h"
#include <ctype.h>

const int CODE_LENGTH = 4; // Soundex Code is uppercase letter followed by 3 digits

string ParseName(string name); // we need to output the Soundex String
char ParseChar(char c); // we will encode each character based on the table given above

int main() {
    // get name to encode from the user's input
    while(true) {
        std::cout << "Enter the surname (or press ENTER/RETURN to quit): ";
        string surname = GetLine(); // imported library method for reading strings from cin
        if (surname == "") { // allow user to exit program if empty C-string
            exit(0); // exits program and returns 0
        }
        std::cout << "The Soundex code for " << surname << " is " << ParseName(surname) << "\n"; // ParseName will convert the C-string into type string!
    }
    return 0;
}

// #ParseName(string name) returns an encoded string according to the Soundex algorithm
string ParseName(string name) {
    string code;
    name = ConvertToUpperCase(name);
    // get the first letter and convert the rest of the characters to numerals
    for (int i = 0; i < name.length(); i++) {
        if (i == 0) {
            code += name[i]; // save the first character, which will be the upper case letter
        }
        if (i > 0 && isalpha(name[i])) {
            code += ParseChar(name[i]); // convert the character to a number according to Soundex Algorithm
        }
    }
    
    // remove duplicate integers from variable code
    for (int j = 0; j < code.length(); j++) {
        if (j > 0 && code[j] == code[j - 1]) {
            code.erase(j, 1); // delete any duplicate characters, as some letters share the same encoded chnumber
        } else if (code[j] == '0') {
            code.erase(j, 1); // delete any 0s
        }
    }
    
    // All Soundex Strings must have 4 characters!
    if (code.length() < CODE_LENGTH) {
        int zeros = CODE_LENGTH - int(code.length()); // try to keep integer precision
        for (int k = 0; k < zeros; k++) {
            code += '0'; // add zeros to the SoundexString if less than 4 characters
        }
    } else if (code.length() > CODE_LENGTH){
        code = code.substr(0, CODE_LENGTH); // remove characters after character index 3
    }
    
    return code; // we will return the 4 character code here
}

// We can use conditionals to control converting alphanumeric characters into the Soundex encoded characters.
char ParseChar(char c) {
    if (c == 'A' || c == 'E'|| c == 'I' || c == 'O' || c == 'U' || c == 'H' || c == 'W' || c == 'Y') {
        return '0';
    } else if (c == 'B' || c == 'F' || c == 'P' || c == 'V') {
        return '1';
    } else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' ||
        c == 'Q' || c == 'S' || c == 'X' || c == 'Z') {
        return '2';
    } else if (c == 'D' || c == 'T') {
        return '3';
    } else if (c == 'M' || c == 'N') {
        return '4';
    } else if (c == 'L') {
        return '5';
    } else {
        return '6';
    }
}
