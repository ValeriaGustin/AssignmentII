#include "circle.h"
#include <cmath> 


circle::circle(float radio, string color) : geoShapes(color, 0, 0), radio(radio) {}


float circle::getRadio() {
    return this->radio;
}


void circle::setRadio(float radio) {
    this->radio = radio;
}


float circle::calcArea() {
    return M_PI * this->radio * this->radio;
}


float circle::calcPerimeter() {
    return 2 * M_PI * this->radio;
}