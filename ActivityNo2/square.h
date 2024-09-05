#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string.h>
#include "geoShapes.h"

class square : public geoShapes {
    private:
        float side;

    public:
        
        square() = default;
        square(float side, string color);

        float getSide();

        void setSide(float side);

        
        float calcArea() override;
        
    	float calcPerimeter() override;
};


#endif