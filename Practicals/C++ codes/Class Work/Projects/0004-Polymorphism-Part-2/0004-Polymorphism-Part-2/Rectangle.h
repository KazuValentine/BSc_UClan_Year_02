#ifndef RECTANGLE
#define RECTANGLE
#include "Shape.h"
class Rectangle : public Shape
{
private:
	double mWidth = 0;
	double mHeight = 0;
public:
	double Area();
	Rectangle(double, double);
};
#endif