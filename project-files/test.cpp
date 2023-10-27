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
    test_Circle();
    test_Color();
    test_Line();
    test_Triangle();
    test_Rectangle();
    
    return;
}


void test_Point() {
    
    cout << "Now Testing Point" << endl;
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
    
    p2.read(data);
    
    cout << "Expected: (34,54), actual: ";
    cout << "(" << p2.getX()
         << ", " << p2.getY()
         << ")" << endl;
    
    
    return;
}


void test_Circle() {
    cout << "Now Testing Circle" << endl;
    
    Point p1(2, 4);
    Color c(123, 52, 35);
    
    
    // test of default constructor
    Circle cir1;
    cout << "Expected: nothing, actual: " << cir1 << endl;
    
    // test of the non-default constructor
    Circle cir2(p1, 3, c);
    cout << "Expected: center (2, 4), radius 3, color (123, 52, 35), actual: " << cir2 << endl;

    // test of member function: setCenter()
    cir1.setCenter(p1);
    // test of member function: setRadius()
    cir1.setRadius(45);
    // test of member function: setColor()
    cir1.setColor(c);
    
    // test of member functions getCenter(), getRadius, and getColor()
    cout << "Expected: Center (2, 4), Radius 45, Color (123, 52, 35) actual: ";
    cout << cir1.getCenter() << " " << cir1.getRadius() << " " << cir1.getColor() << endl;
    
    
//    ifstream data;
//    data.open("data1.txt");
//    p2.read(data);
//    
//    cout << "Expected: (4,5), actual: ";
//    cout << "(" << p2.getX()
//         << ", " << p2.getY()
//         << ")" << endl;
//    
//    p2.read(data);
//    
//    cout << "Expected: (34,54), actual: ";
//    cout << "(" << p2.getX()
//         << ", " << p2.getY()
//         << ")" << endl;
    
    
    // testing 123456789
    
    return;
}

void test_Color() {
    cout << "Now Testing Color" << endl;
    
//    Point p1(2, 4);
//    Color c(123, 52, 35);
    
    
    // test of default constructor
    Color c1;
    cout << "Expected: (0,0) (0,0) 0 0 0, actual: " << c1 << endl;
    
    // test of the non-default constructor
    Color c2(124, 35, 234);
    cout << "Expected: 124, 35, 234), actual: " << c2 << endl;

    c1.setRed(20);
    c1.setGreen(30);
    c1.setBlue(40);
    
    // test of member functions getCenter(), getRadius, and getColor()
    cout << "Expected: 20 30 40, actual: ";
    cout << c1.getRed() << " " << c1.getGreen() << " " << c1.getBlue() << endl;
    
    Color c3;
    
    ifstream data;
    data.open("data1.txt");
    
    c3.read(data);
    cout << "Expected: 23 52 255, actual: ";
    cout  << c3.getRed() << " " << c3.getGreen() << " " << c3.getBlue() << endl;

    c3.read(data);
    cout << "Expected: 4 185 39, actual: ";
    cout  << c3.getRed() << " " << c3.getGreen() << " " << c3.getBlue() << endl;
    
    return;
}

void test_Line() {
    cout << "Now Testing Line" << endl;
    
    Point p1(2, 4);
    Point p2(5, 6);
    Color c1(50, 60, 70);
    
    
    Point p3(1, 2);
    Point p4(3, 9);
    Color c2(22, 33, 44);
    
    // test of default constructor
    Line L1;
    cout << "Expected: 0 0 0, actual: " << L1 << endl;
    
    // test of the non-default constructor
    Line L2(p1, p2, c1);
    cout << "Expected: (2, 4) (5, 6) 50 60 70, actual: " << L2 << endl;

    L1.setStart(p3);
    L1.setEnd(p4);
    L1.setColor(c2);
    
    // test of member functions getStart(), getEnd, and getColor()
    cout << "Expected: (1, 2) (3, 9) 22 33 44 actual: ";
    cout << L1.getStart() << " " << L1.getEnd() << " " << L1.getColor() << endl;
    
    Line L3;
    
    ifstream data;
    data.open("data1.txt");
    
    L3.read(data);
    cout << "Expected: (4, 5) (6, 7) 66 77 88, actual: ";
    cout << L3 << endl;

    L3.read(data);
    cout << "Expected: (1, 2) (3, 4) 12 34 56, actual: ";
    cout << L3 << endl;
    
    return;
}

void test_Triangle() {
    cout << "Now Testing Triangle" << endl;
    
    Point v1(1, 2);
    Point v2(4, 3);
    Point v3(3, 5);
    Color c1(10, 20, 40);
    
    
    Point v4(12, 15);
    Point v5(19, 13);
    Point v6(15, 25);
    
    Color c4(33, 44, 55);
    Color c5(66, 77, 88);
    Color c6(150, 180, 20);
    
    Color c7(10, 20, 40);
    Color c8(20, 40, 80);
    Color c9(30, 60, 120);
    
    // test of default constructor
    Triangle T1(v1, v2, v3, c1);
    cout << "Expected: (1,2) (4,3) (3,5) 10 20 40, actual: " << T1 << endl;
    
    // test of the non-default constructor
    Triangle T2(v4, c4, v5, c5, v6, c6);
    cout << "Expected: (12,15) 33 44 55 (19,13) 66 77 88 (15,25) 150 180 20, actual: " << T2 << endl;

    // Test setters
    T1.setVertexOneColor(c7);
    T1.setVertexTwoColor(c8);
    T1.setVertexThreeColor(c9);
    
    // Test getters
    cout << "Expected: (1,2) 10 20 40 (4,3) 20 40 80 (3,5) 30 60 120, actual: ";
    cout << T1.getVertexOne() << " " << T1.getVertexOneColor() << " " << T1.getVertexTwo() << " " << T1.getVertexTwoColor() << " " << T1.getVertexThree() << " " << T1.getVertexThreeColor() << endl;
    
    cout << endl;
    Triangle T3;
    
    cout << "Testing read and write:" << endl;
    
    ifstream data;
    data.open("data1.txt");
    
    T3.read(data);
    cout << "Expected: T (5,10) (15,20) (10,30)  0 140 20, actual: ";
    cout << T3 << endl;

    T3.read(data);
    cout << "Expected: T (10,20)   0 0 255  (40,25)   0 255 0  (35, 45)  255 0 0, actual: ";
    cout << T3 << endl;
    
    return;
}

void test_Rectangle() {
    cout << "Now Testing Rectangle" << endl;

    Point s1(0, 1);
    Point e1(2, 3);
    Color c1(10, 20, 30);
    Color c2(20, 30, 40);
    Color c3(30, 40, 50);
    Color c4(40, 50, 60);

    Point s2(10, 11);
    Point e2(22, 33);
    Color c5(0, 255, 0);

    Color c6(100, 0, 100);
    Color c7(200, 0, 200);
    Point p1(24, 78);

    // test of default constructor
    Rectangle r1;
    cout << "Expected: (0, 0) (0, 0)  0 0 0   0 0 0   0 0 0     0 0 0, actual: " << r1 << endl;

    // test of the non-default constructor
    Rectangle r2(s2, e2, c5);
    cout << "Expected: (10, 11) (22, 33)  0 255 0   0 255 0   0 255 0     0 255 0, actual: " << r2 << endl;

    Rectangle r3(s1, e1, c1, c2, c3, c4);
    cout << "Expected: (0, 1) (2, 3)  10 20 30   20 30 40   30 40 50   40 50 60, actual: " << r3 << endl;

    // Test setters
    r1.setColorTopLeft(c6);
    r1.setColorBottomRight(c7);
    r1.setStart(p1);

    // Test getters
    cout << "Expected: (24, 78) (0, 0)  100 0 100  0 0 0  200 0 200  0 0 0, actual: ";
    cout << r1.getStart() << " " << r1.getEnd() << " " << r1.getColorTopLeft() << " " << r1.getColorTopRight() << " " << r1.getColorBottomRight() << " " << r1.getColorBottomLeft() << endl;
    cout << endl;

    Rectangle r4;

    cout << "Testing read and write:" << endl;

    ifstream data;
    data.open("data1.txt");

    r4.read(data);
    cout << "Expected: R (20,40)  (40,80)  0 100 200, actual: ";
    cout << r4 << endl;

    r4.read(data);
    cout << "Expected: R (20,11)  (24,57)  24 98 67   100 50 150  110 15 235  120 205 15, actual: ";
    cout << r4 << endl;

    return;
}
