#ifndef SQUARE
#define SQUARE
#include "Shape.h"
class Square : public Shape
{
private:
	double mWidth = 0;
public:
	double Area();
	Square(double);
};
#endif