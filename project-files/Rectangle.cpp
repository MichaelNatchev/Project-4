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
 * This is the rectangle class
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

Rectangle::Rectangle() {

}

Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    setStart(pt1);
    setEnd(pt2);
    setColor(color);
}

Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft) {
    setStart(pt1);
    setEnd(pt2);
    setColorTopLeft(cTopLeft);
    setColorTopRight(cTopRight);
    setColorBottomRight(cBottomRight);
    setColorBottomLeft(cBottomLeft);
}

void Rectangle::setStart(Point pt) {
    start = pt;
    return;
}

Point Rectangle::getStart() {
    return start;
}

void Rectangle::setEnd(Point pt) {
    end = pt;
    return;
}

Point Rectangle::getEnd() {
    return end;
}

void Rectangle::setColor(Color color) {
    setColorTopLeft(color);
    setColorTopRight(color);
    setColorBottomLeft(color);
    setColorBottomRight(color);
    return;
}

void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
    return;
}

Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
    return;
}

Color Rectangle::getColorTopRight() {
    return colorTopRight;
    
}

void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
    return;
}

Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
    
}

void Rectangle::setColorBottomLeft(Color c) {
    colorBottomLeft = c;
    return;
    
}

Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

void Rectangle::read(istream& ins) {
    start.read(ins);
    end.read(ins);
    colorTopLeft.read(ins);
    
    ins >> ws;
    char nextChar = ins.peek();
    
    if (!isdigit(nextChar)) {
        setColor(colorTopLeft);
        return;
    } else if (isdigit(nextChar)){
        colorTopRight.read(ins);
        colorBottomRight.read(ins);
        colorBottomLeft.read(ins);
    }
    return;
}

void Rectangle::write(ostream& outs) {
    outs << start << " " << end << " " << colorTopLeft << " "
        << colorTopRight << " " << colorBottomRight << " "
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
