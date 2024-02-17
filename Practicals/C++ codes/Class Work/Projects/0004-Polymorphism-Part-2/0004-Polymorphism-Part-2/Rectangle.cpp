#include "Rectangle.h"

double Rectangle::Area()
{
	return mHeight * mWidth;
}

Rectangle::Rectangle(double height, double width)
{
	mHeight = height;
	mWidth = width;
}