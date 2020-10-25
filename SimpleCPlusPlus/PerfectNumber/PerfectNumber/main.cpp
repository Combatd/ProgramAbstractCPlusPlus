//
//  main.cpp
//  PerfectNumber
//
//  Created by Mark Calvelo on 10/25/20.
//

/*
 Greek mathematicians took a special interest in numbers that are equal to the sum of their proper
 divisors (a proper divisor of N is any divisor less than N itself). They called such numbers perfect
 numbers. For example, 6 is a perfect number because it is the sum of 1, 2, and 3, which are the
 integers less than 6 that divide evenly into 6. Similarly, 28 is a perfect number because it is the sum
 of 1, 2, 4, 7, and 14.
 
 Write a predicate function IsPerfect that takes an integer n and returns true if n is perfect, and
 false otherwise. Test your implementation by writing a main program that uses the IsPerfect
 function to check for perfect numbers in the range 1 to 10000 by testing each number in turn.
 When a perfect number is found, your program should print it. The first two perfect numbers are 6
 and 28, there are two others in the range to 10000.
 
 */

#include <iostream>
#include "libgen.h"
#include "simpio.h"

const int MAX_NUMBER = 10000; // 4 perfect numbers exist!

bool isPerfect(int number); // define this predicate function (returns boolean)

bool isPerfect(int number) {
    int sum = 0;
    for (int i = 0; i < number; i++) {
        // sum of all proper divisors leading up to the number
        if (i > 0 && number % i == 0) {
            sum += i;
        }
    }
    return (number > 0 && sum == number);
}

int main(int argc, const char * argv[]) {
    // We should print out all our perfect numbers!
    for (int i = 0; i < MAX_NUMBER; i++) {
        if (isPerfect(i)) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
