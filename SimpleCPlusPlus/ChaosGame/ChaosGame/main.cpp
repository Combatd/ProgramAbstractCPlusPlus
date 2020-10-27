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

void CreateTriangle() {
    int count = 0; // keep track of the mouse clicks of the user
    while (count < 3) {
        WaitForMouseDown();
        WaitForMouseUp();
        double X = GetMouseX(); // Get X value of specified Mouse Pointer
        double Y = GetMouseY(); // Get Y value of specified Mouse Pointer
        // log the 3 vertices
        if (count == 0) {
            MovePen(X, Y); // This procedure moves the current point to the position (x, y), without drawing a line. The model is that of the pen being lifted off the graphics window surface and then moved to its new position.
            firstVertex.X = X;
            firstVertex.Y = Y;
        } else if (count == 1) {
            secondVertex.X = X;
            secondVertex.Y = Y;
            DrawLine(secondVertex.X - firstVertex.X, secondVertex.Y - firstVertex.Y);
        } else {
            thirdVertex.X = X;
            thirdVertex.Y = Y;
            DrawLine(thirdVertex.X - secondVertex.X, thirdVertex.Y - secondVertex.Y);
            // close the triangle by drawing line from first to third vertex
            DrawLine(firstVertex.X - thirdVertex.X , firstVertex.Y - thirdVertex.Y);
        }
        count++; // iterate at every mouse click
    }
}

// We need to draw an initial circle at a random point in the Triangle.
void SetFirstCircle() {
    Point currentPoint = RandomPoint();
    MovePen(currentPoint.X, currentPoint.Y);
    StartFilledRegion(1); // Starts defining a region that will be filled with the current color. Any line segments drawn between now and the matching call to endFilledRegion will be used to create a polygon that is then filled.
    DrawArc(CIRCLE_SIZE, 0, 360); // Draws an elliptical arc inscribed in a rectangle. The parameters x, y, width, and height (or, equivalently, the GRectangle bounds) specify the coordinates and dimensions of the bounding rectangle. The start parameter indicates the angle at which the arc begins and is measured in degrees counterclockwise from the +x axis. Thus, a start angle of 0 indicates an arc that begins along the line running eastward from the center, a start angle of 135 begins along the line running northwest, and a start angle of -90 begins along the line running south. The sweep parameter indicates the extent of the arc and is also measured in degrees counterclockwise. A sweep angle of 90 defines a quarter circle extending counterclockwise from the start angle, and a sweep angle of -180 defines a semicircle extending clockwise.
    EndFilledRegion();
}

// DrawLoop() will draw circles to fill the triangle.
void DrawLoop() {
    UpdateDisplay(); // This function initiates an immediate update of the graphics window and is necessary for animation. Ordinarily, the graphics window is only updated when the program waits for user input.
}
