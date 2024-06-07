#include "Square.h"

double Square::Area()
{
	return mWidth * mWidth;
}

Square::Square(double width)
{
	mWidth = width;
}