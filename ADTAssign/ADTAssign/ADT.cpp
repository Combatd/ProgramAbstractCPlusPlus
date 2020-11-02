//
//  ADT.cpp
//  ADTAssign
//
//  Created by Mark Calvelo on 11/2/20.
// Will contain the main function!

#include "genlib.h"
#include "simpio.h"
#include "randomwriter.hpp"
#include <iostream>

int main() {
    while (true) {
        std::cout << "Abstract Data Type Options" << "\n";
        std::cout << "0. Exit Application" << std::endl;
        std::cout << "1. Random Writer Program" << std::endl;
        std::cout << "2. Maze Program" << std::endl;
        std::cout << "Choose one of the programs with number input: "
        int userChoice = GetInteger(); // get integer input from user
        if (userChoice == 0) {
            exit(0); // exit program while returning 0
        } else if (userChoice == 1) {
            RandomWriter();
        } else if (userChoice == 2) {
            // Maze Runner function invocation will be here
        }
    }
    return 0;
}
