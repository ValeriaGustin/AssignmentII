#ifndef GEOSHAPES_H
#define GEOSHAPES_H

#include <iostream>
#include <string.h>

using namespace std;

class geoShapes {
	protected:
		string color;
		float area;
		float perimeter;
	
	public:
		geoShapes() = default;
		
	    geoShapes(string color, float area, float perimeter);
	    
		string getColor();
		
		float getArea();
		
		float getPerimeter();
		
		void setColor(string color);
		
		void setArea(float area);
		
		void setPerimeter(float perimeter);
			    
		virtual float calcArea();
		
		virtual float calcPerimeter();

};
	
#endif 