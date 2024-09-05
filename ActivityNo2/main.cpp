#include "circle.h"
#include "square.h"
#include "diamond.h"
#include <cmath> 


int main(){
    circle circle1(2.2, "dorado");
    square square1(5.0, "verde");
    diamond diamond1(2.0, 2.8, "rojo");
    
    std::cout << "Square 1:" << std::endl;
    std::cout << "Area: " << square1.calcArea() << std::endl;
    std::cout << "Perimeter: " << square1.calcPerimeter() << std::endl;
    std::cout << "Color: " << square1.getColor() << std::endl << std::endl;
    
    std::cout << "Diamond 1:" << std::endl;
    std::cout << "Area: " << diamond1.calcArea() << std::endl;
    std::cout << "Perímetro: " << diamond1.calcPerimeter() << std::endl;
    std::cout << "Color: " << diamond1.getColor() << std::endl << std::endl;
    
    std::cout << "Cicle 1:" << std::endl;
    std::cout << "Area: " << circle1.calcArea() << std::endl;
    std::cout << "Perimeter: " << circle1.calcPerimeter() << std::endl;
    std::cout << "Color: " << circle1.getColor() << std::endl << std::endl;
    
    return 0;
}