#include <iostream>
#include <string.h>
#include <math.h>
#include "geoShapes.h"

using namespace std;

geoShapes::geoShapes(string color, float area, float perimeter) {
	this->color = color;
	this->area = area;
	this->perimeter = perimeter;
}


string geoShapes::getColor() {
    return this->color;
}

float geoShapes::getArea() {
    return this->area;
}

float geoShapes::getPerimeter() {
    return this->perimeter;
}

void geoShapes::setColor(string color) {
    this->color = color;
}

void geoShapes::setArea(float area) {
    this->area = area;
}

void geoShapes::setPerimeter(float perimeter) {
    this->perimeter = perimeter;
}


float geoShapes::calcArea() {
    return 0;
}


float geoShapes::calcPerimeter() {
    return 0;
}