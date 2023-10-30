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
 * This is the point class.
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

Point::Point() {
    setX(0);
    setY(0);
}

Point::Point(int xVal, int yVal) {
    setX(xVal);
    setY(yVal);
}

void Point::setX(int xVal) {
    x = checkRange(xVal);
}

int Point::getX() {
    return x;
}

void Point::setY(int yVal) {
    y = checkRange(yVal);
}

int Point::getY() {
    return y;
}

void Point::read(istream& ins) {
    char openParen;
    char comma;
    char closeParen;

    ins >> openParen;

    if (openParen == '(') {
        ins >> x;
        ins >> comma;
        ins >> y;
        ins >> closeParen;
    }
}

void Point::write(ostream& outs) {
    outs << "("  << checkRange(x) << "," << checkRange(y) << ")";
}

int Point::checkRange(int val) {
    if (val >= 0 && val < DIMENSION) {
        return val;
    } else if (val < 0){
        return 0;
    }
    return DIMENSION - 1;
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
