/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Michael Natchev, Mark Zhu   
 * mnatchev, markzhu
 *
 * <#Description#>
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// TODO: implement two constructors, setX, getX, setY, getY, read, write, checkRange.

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int xVal, int yVal) {
    x = xVal;
    y = yVal;
}

void Point::setX(int xVal) {
    x = xVal;
}

int Point::getX() {
    return x;
}

void Point::setY(int yVal) {
    y = yVal;
}

int Point::getY() {
    return y;
}

void Point::read(istream& ins) {
    
}

void Point::write(ostream& outs) {


}

int Point::checkRange(int val) {

    return 0;
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
