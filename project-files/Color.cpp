/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Mark Zhu, Michael Natchev
 * markzhu, mnatchev
 *
 * This is the color class.
 *
 */

#include "Color.h"

Color::Color() {
    setRed(0);
    setGreen(0);
    setBlue(0);
}

Color::Color(int redVal, int greenVal, int blueVal) {
    setRed(redVal);
    setGreen(greenVal);
    setBlue(blueVal);
}

int Color::checkRange(int val) {
    const int MAX_COLOR_VAL = 255;
    
    if (val >= 0 && val <= MAX_COLOR_VAL) {
        return val;
    } else if (val < 0){
        return 0;
    }
    return MAX_COLOR_VAL;
}

void Color::setRed(int redVal) {
    red = checkRange(redVal);
    return;
}

int Color::getRed() {
    return red;
}

void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
    return;
}

int Color::getGreen() {
    return green;
}

void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
    return;
}

int Color::getBlue() {
    return blue;
}

void Color::read(istream& ins) {
    
    int r;
    int g;
    int b;
    
    ins >> r;
    ins >> g;
    ins >> b;
    
    red = checkRange(r);
    green = checkRange(g);
    blue = checkRange(b);
    
    return;
}

void Color::write(ostream& outs) {
    outs << checkRange(red) << " " 
         << checkRange(green) << " " 
         << checkRange(blue);
    return;
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
