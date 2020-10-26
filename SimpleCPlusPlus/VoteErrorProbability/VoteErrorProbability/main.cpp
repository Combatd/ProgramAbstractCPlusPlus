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

// We should run this simulation for 500 trials
const int NUMBER_TRIALS = 500;

double CalculateVoteError(int voters, double spread, double error);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

// # CalculateVoteError will take input from terminal input
// parameters will be encapsulated into this function as we may reuse variable names locally
double CalculateVoteError(int v, double s, double e) {
    double invalidElections = 0; // number of trials an election result was invalid
    int spread = v * s;
    for (int i = 0; i < NUMBER_TRIALS; i++) { // we need to do this for 2 candidates
        int candidateA = 0; // first candidate
        int candidateB = 0; // second candidate
        
        for (int j = 0; j < NUMBER_TRIALS; j++) { // nested loop runs vote trial
            bool vote = randomChance(1.0 - e); // cast votes subtracting the margin of error
            if (j < (v / 2) + spread) { // apply error votes according to spread across both candidates
                if (vote) {
                    candidateA++; // truthy casts vote for candidateA
                } else {
                    candidateB++; // falsey casts vote for candidateB
                }
            }
        }
        if (candidateB > candidateA) {
            invalidElections++; // candidate B winning is an erroneous election
        }
    }
    return double(invalidElections / NUMBER_TRIALS * 100); // Order of Operations applies to the formula, so no need for extra parenthesis
}
