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

#include "randomwriter.hpp"
