#include "Triangle.h"

double Triangle::Area()
{
	return mBase * mHeight / 2;
}

Triangle::Triangle(double base, double height)
{
	mHeight = height;
	mBase = base;
}