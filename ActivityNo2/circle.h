#ifndef CIRCLE_H
#define CIRCLE_H

#include "geoShapes.h"

class circle : public geoShapes {
    private:
        float radio;

    public:
        circle(float radio, string color);

        
        float getRadio();
        void setRadio(float radio);

        
        float calcArea() override;
        float calcPerimeter() override;
};

#endif