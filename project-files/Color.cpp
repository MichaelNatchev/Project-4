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
 * <#Description#>
 *
 */

#include "Color.h"

// TODO: implement first checkRange, then two constructors, setRed, getRed,
//       setGreen, getGreen, setBlue, getBlue, read, write.

/**
 * Requires: Nothing.
 * Modifies: red, green, blue.
 * Effects:  Default contructor. Sets color to black (0,0,0).
 */
Color::Color() {
    setRed(0);
    setGreen(0);
    setBlue(0);
}

/**
 * Requires: Nothing.
 * Modifies: red, green, blue.
 * Effects:  Constructor that sets RGB values. If values are ouside of
 *           [0,255], assigns to the closest of 0 and 255.
 * NOTE: you should implement the 'private' member funtion
 *     checkRange() before you implement this function
 */
Color::Color(int redVal, int greenVal, int blueVal) {
    setRed(redVal);
    setGreen(greenVal);
    setBlue(blueVal);
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns val if val is in range [0,255],
 *           otherwise returns the closest of 0 and 255.
 */
int Color::checkRange(int val) {
    if (val >= 0 && val <= 255) {
        return val;
    } else if (val < 0){
        return 0;
    }
    return 255;
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

/**
 * Requires: ins is in good state.
 * Modifies: ins, red, green, blue.
 * Effects:  Reads color in form red green blue.
 *     format of a color is:  red  green  blue
 *     Example:  100  255  125
 */
void Color::read(istream& ins) {
    // fix me
    return;
}

/**
 * Requires: outs is in good state.
 * Modifies: outs.
 * Effects:  Writes color in form red  green  blue
 * Example:  100  255  125
 */
void Color::write(ostream& outs) {
    // fix me
    outs << checkRange(red) << " " << checkRange(green) << " " << checkRange(blue);
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
