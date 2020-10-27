//
//  main.cpp
//  ChaosGame
//
//  Created by Mark Calvelo on 10/27/20.
//

/*
 For this problem, you will use the graphics library to explore an interesting phenomenon known as
 the "Chaos Game."
 Prompt the user to click three points within the graphics window. We'll refer to these points as A, B,
 C. Draw a triangle connecting A, B, and C. Now, follow these steps to fill in the triangle with points:
 1. Randomly choose one vertex (A, B, or C) as the current point
 2. Draw a small filled circle around the current point
 3. Randomly choose one vertex (A, B, or C) and move the current point half of the distance
 toward that vertex
 4. Repeat steps 2 & 3 (stop when the user clicks the mouse)
 After many iterations, you might expect this random process to produce nothing but an odd
 mishmash or that the points will eventually fill the entire triangle. Without giving too much away, I'll
 tell you that the resulting image never varies and will likely surprise you with its beauty and
 symmetry.
 
 CS106B uses a simple paint-based drawing library that operates on a Cartesian coordinate system
 where dimensions are expressed in inches. The graphics.h and extgraph.h header files give
 details on the individual functions. For this program, you'll use the functions for handling mouse
 events (WaitForMouseDown, GetMouseX, etc.) and pen-drawing (MovePen, DrawArc,
 StartFilledRegion, etc). You may also need to call UpdateDisplay in your loop to flush
 drawing to the screen without delay.
 */

#include <iostream>
#include "lib/graphics.h"
#include "lib/extgraph.h"
#include "lib/genlib.h"
#include "lib/random.h"

const double CIRCLE_SIZE = .05; // we need a small circle for this animation

// struct stores a collection of user defined data types
// This project relies on a Cartesian Plane, so we will need X, Y coordinates.
struct Point {
    double X;
    double Y;
};

// Randomly Choose one vertex with 3 points A, B, C
Point firstVertex; // A
Point secondVertex; // B
Point thirdVertex; // C

Point RandomPoint(); // One random vertex will be set as the current point
void CreateTriangle(); // We need to draw the triangle connecting A, B, C
void SetFirstCircle(); // Draw a small filled circle around the current point
void DrawLoop(); // Randomly choose one vertex and move the current point half of the distnace toward that vertex
// the DrawLoop() will continue as the user clicks the mouse

int main() {
    return 0;
}
