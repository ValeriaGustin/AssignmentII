#ifndef DIAMOND_H
#define DIAMOND_H

#include "geoShapes.h"

class diamond: public geoShapes {
    private:
        float diagonalMayor;
        float diagonalMenor;

    public:
        diamond(float diagonalMayor, float diagonalMenor, string color);
        
        float getDiagonalMayor();
		void setDiagonalMayor(float diagonalMayor);
        
		float getDiagonalMenor();
        void setDiagonalMenor(float diagonalMenor);
        
		float calcArea() override;
        float calcPerimeter() override;
};

#endif // DIAMOND_H