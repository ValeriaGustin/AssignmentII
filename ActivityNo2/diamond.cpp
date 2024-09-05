#include "diamond.h"
#include <cmath>

diamond::diamond(float diagonalMayor, float diagonalMenor, string color) : geoShapes(color, 0, 0) {
    this->diagonalMayor = diagonalMayor;
    this->diagonalMenor = diagonalMenor;
}

float diamond::getDiagonalMayor() {
    return this->diagonalMayor;
}

void diamond::setDiagonalMayor(float diagonalMayor) {
    this->diagonalMayor = diagonalMayor;
}

float diamond::getDiagonalMenor() {
    return this->diagonalMenor;
}

void diamond::setDiagonalMenor(float diagonalMenor) {
    this->diagonalMenor = diagonalMenor;
}

float diamond::calcArea() {
    return (this->diagonalMayor * this->diagonalMenor) / 2.0;
}

float diamond::calcPerimeter() {
    float lado = sqrt(pow(this->diagonalMayor / 2.0, 2) + pow(this->diagonalMenor / 2.0, 2));
    return 4 * lado;
}