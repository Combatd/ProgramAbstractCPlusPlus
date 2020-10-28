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

int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
