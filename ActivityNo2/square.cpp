#include <iostream>
#include <string>

#include "square.h"

square::square(float side, std::string color) : geoShapes(color, 0, 0) {
    this->side = side;
}

float square::getSide() {
    return this->side;
}

void square::setSide(float side) {
    this->side = side;
}

float square::calcArea() {
    return this->side * this->side;
}

float square::calcPerimeter() {
    return 4 * this->side;
}