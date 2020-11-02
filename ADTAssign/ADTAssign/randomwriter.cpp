//
//  randomwriter.cpp
//  ADTAssign
//
//  Created by Mark Calvelo on 11/1/20.
//

/*
 Your program is to read a source text, build an order k Markov model for it, and generate random
 output that follows the frequency patterns of the model.
 First, you prompt the user for the name of a file to read for the source text and re-prompt as needed
 until you get a valid name. (And you have a beautiful and correct version you can crib from your
 solution to assignment #1, no?) Now ask the user for what order of Markov model to use (a
 number from 1 to 10). This will control what seed length you are working with.
 Use simple character-by-character reading on the file. As you go, track the current seed and observe
 what follows it. Your goal is to record the frequency information in such a way that it will be easy to
 generate random text later without any complicated manipulations.
 Once the reading is done, your program should output 2000 characters of random text generated
 from the model. For the initial seed, choose the sequence that appears most frequently in the source
 (e.g. if doing an order 4 analysis, the four-character sequence that is most often repeated in the
 source is used to start the random writing). If there are several sequences tied for most frequent, any
 of them can be used as the initial seed. Output the initial seed, then choose the next character based
 on the probabilities of what followed that seed in the source. Output that character, update the seed,
 and the process repeats until you have 2000 characters.
 */

// Need Vector and Map for this application
#include "randomwriter.hpp"
#include <iostream>
#include "genlib.h"
#include <fstream>
#include "simpio.h"
#include "map.h"
#include "vector.h"
#include "random.h"

/*
 Map and Vector are just what you need to store the model information. The keys into the map
 are the possible seeds (e.g. if order is 2, each key is a 2-character sequence found in the source
 text). The associated value is a vector of all the characters that follow that seed in the source
 text. That vector can, and likely will, contain a lot of duplicate entries. Duplicates represent
 higher probability transitions from this Markov state. Explicitly storing duplicates is the easiest
 strategy and makes it simple to choose a random character from the correct frequency
 distribution. A more space-efficient strategy would store each character at most once, with its
 frequency count. However, it's a bit more awkward to code this way. You are welcome to do
 either, but if you choose the latter, please take extra care to keep the code clean.
 • Determining which seed(s) occurs most frequently in the source can be done by iterating or
 mapping over the entries once you have finished the analysis.
 • For reading a file one character at a time, use the get member function for ifstream.
 */

void ParseInputText(ifstream &in); // pass by reference
void CreateSeedMap(string &line); // pass by reference
string GetInitialSeed();
void GenerateRandomText(string seed);

const int MAX_CHARS = 2000;

int orderK; // Markov Order - will be taken from user Input

/*  Define the main function as the Random Writer
    It takes input text file and markov number from user.
    Generates a maximum of characters MAX_CHARS.
*/

void RandomWriter() {
    Randomize();
    ifstream in;
    while (true) {
        std::cout << "Enter the filename of the source text: ";
        string fileName = GetLine();
        in.open(fileName.c_str()); // convert C string to type string
        if (!in.fail()) {
            break; // we will break out of this loop if file opened successfully
        }
        in.clear(); // clear input stream
        std::cout << "File could not be opened" << "\n";
    }
    while (true) {
        std::cout << "What is the order of analysis? Enter a number from 1 to 10: ";
        orderK = GetInteger(); // get integer from 1 to 10
        if (orderK >= 1 && orderK <= 10) {
            break;
        }
        std::cout << "Invalid: Number must be from 1 to 10" << "\n";
    }
    
    ParseInputText(in);
    in.close(); // close the input stream
    string seed = GetInitialSeed(); // return random number
    GenerateRandomText(seed);
    // Clear the containers for later invocations of RandomWriter()
    // seedMap with Map Vector is here
    // seeds with duplicates for finding most common as a Vector of strings here
}
