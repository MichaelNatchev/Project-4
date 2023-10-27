/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Mark Zhu, Michael Natchev
 * markzhu, mnatchev
 *
 * <#Description#>
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// TODO: implement three constructors, setStart, getStart, setEnd, getEnd,
//       setColor, setColorTopLeft, getColorTopLeft, setColorTopRight,
//       getColorTopRight, setColorBottomRight, getColorBottomRight,
//       setColorBottomLeft, getColorBottomLeft, read, write.

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Default contructor.
 */
Rectangle::Rectangle() {
    Point pt1;
    setStart(pt1);
    Point pt2;
    setEnd(pt2);
    Color color;
    setColor(color);
}

/**
 * Requires: Nothing.
 * Modifies: start, end, colorTopLeft, colorTopRight, colorBottomRight,
 *           colorBottomLeft.
 * Effects:  Overloaded contructor. Sets start, end and single color.
 */
Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    setStart(pt1);
    setEnd(pt2);
    setColor(color);
}

/**
 * Requires: Nothing.
 * Modifies: start, end, colorTopLeft, colorTopRight, colorBottomRight,
 *           colorBottomLeft.
 * Effects:  Overloaded contructor. Sets start, end and four colors.
 */
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft) {
    setStart(pt1);
    setEnd(pt2);
    setColorTopLeft(cTopLeft);
    setColorTopRight(cTopRight);
    setColorBottomRight(cBottomRight);
    setColorBottomLeft(cBottomLeft);
}

/**
 * Requires: Nothing.
 * Modifies: start.
 * Effects:  Sets start point (top left) of rectangle.
 */
void Rectangle::setStart(Point pt) {
    start = pt;
    return;
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns start point of rectangle.
 */
Point Rectangle::getStart() {
    return start;
}

/**
 * Requires: Nothing.
 * Modifies: end.
 * Effects:  Sets end point (bottom right) of rectangle.
 */
void Rectangle::setEnd(Point pt) {
    end = pt;
    return;
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns end point of rectangle.
 */
Point Rectangle::getEnd() {
    return end;
}

/**
 * Requires: Nothing.
 * Modifies: colorTopLeft, colorTopRight, colorBottomRight, colorBottomLeft.
 * Effects:  Sets the four colors of rectangle to color.
 */
void Rectangle::setColor(Color color) {
    setColorTopLeft(color);
    setColorTopRight(color);
    setColorBottomLeft(color);
    setColorBottomRight(color);
    return;
}

/**
 * Requires: Nothing.
 * Modifies: colorTopLeft.
 * Effects:  Sets top left color of rectangle.
 */
void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
    return;
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns top left color of rectangle.
 */
Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

/**
 * Requires: Nothing.
 * Modifies: colorTopRight.
 * Effects:  Sets top right color of rectangle.
 */
void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
    return;
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns top right color of rectangle.
 */
Color Rectangle::getColorTopRight() {
    return colorTopRight;
    
}

/**
 * Requires: Nothing.
 * Modifies: colorBottomRight.
 * Effects:  Sets bottom rihgt color of rectangle.
 */
void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
    return;
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns bottom right color of rectangle.
 */
Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
    
}

/**
 * Requires: Nothing.
 * Modifies: colorBottomLeft.
 * Effects:  Sets bottom left color of rectangle.
 */
void Rectangle::setColorBottomLeft(Color c) {
    colorBottomLeft = c;
    return;
    
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns bottom left color of rectangle.
 */
Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

/**
 * Requires: ins is in good state.
 * Modifies: ins, start, end, colorTopLeft, colorTopRight,
 *           colorBottomRight, colorBottomLeft.
 * Effects:  Reads rectangle in forms
 *           start end color
 *           start end cTopLeft cTopRight cBottomRight cBottomLeft
 */
void Rectangle::read(istream& ins) {
    start.read(ins);
    end.read(ins);
    cout << " ";
    colorTopLeft.read(ins);
    cout << " ";
    colorTopRight.read(ins);
    cout << " ";
    colorBottomRight.read(ins);
    cout << " ";
    colorBottomLeft.read(ins);
    return;
}

/**
 * Requires: outs is in good state.
 * Modifies: outs.
 * Effects:  Writes rectangle in form
 *           start end cTopLeft cTopRight cBottomRight cBottomLeft
 */
void Rectangle::write(ostream& outs) {
    outs << start << " " << end << " " << colorTopLeft << " "
        << colorTopRight << " " << colorBottomRight
        << colorBottomLeft << endl;
    return;
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
