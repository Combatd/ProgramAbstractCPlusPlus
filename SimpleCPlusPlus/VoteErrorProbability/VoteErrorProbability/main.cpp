//
//  main.cpp
//  VoteErrorProbability
//
//  Created by Mark Calvelo on 10/25/20.
//

#include <iostream>
#include "genlib.h"
#include "simpio.h"
#include "random.h"

/*
 With a little knowledge of statistics, it is not hard to calculate the exact probability of an invalid
 outcome, but it is even easier to simulate this process. Generate a sequence of 505 votes for
 candidate A and 495 for candidate B where each vote has a 8% chance of being inverted when
 recorded. Do the vote totals result in B defeating A, despite the original intentions of the voters?
 This outcome represents one trial in the simulation. If you repeat this trial many times and keep
 track of the results, the ratio
 
 number of trials in which election result was invalid / total number of trials * 100
 
 provides an estimate of the percentage chance of an invalid election result.
 Write a program that prompts the user to enter the voting simulation parameters, then performs 500
 simulation trials and reports the ratio calculated above.
 
 Sample Terminal
 
 Enter number of voters: 10000
 Enter percentage spread between candidates: .005
 Enter voting error percentage: .15
 Chance of an invalid election result after 500 trials = 13.4%
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
