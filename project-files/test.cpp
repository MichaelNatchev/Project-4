/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Mark Zhu, Michael Natchev
 * markzhu, mnatchev
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;

void file_check() {

    // open one of the text files that are part of the starter code
    ifstream ins;
    ins.open("lines.txt");

    // if the file was not in the correct directory, the stream state is fail
    if (ins.fail()) {
        cout << "Could not open data1.txt" << endl;
    }
    else {
        cout << "Success! Text files are in the right directory." << endl;
    }
    ins.close();
    
    return;
}

void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    file_check();
    
    test_Point();
    
    // call other test functions here
    
    return;
}





void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
    
    // test of member function: setX()
    p1.setX(923);
    // test of member function: setY()
    p1.setY(-234);
    
    cout << "Expected: (99,0), actual: ";
    cout << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
    
    
    
    
    
    cout << "Expected: (3,9), actual: ";
    cout << "(" << p2.getX()
         << ", " << p2.getY()
         << ")" << endl;
    
    ifstream data;
    data.open("data1.txt");
    p2.read(data);
    
    cout << "Expected: (4,5), actual: ";
    cout << "(" << p2.getX()
         << ", " << p2.getY()
         << ")" << endl;
    
    
    return;
}


