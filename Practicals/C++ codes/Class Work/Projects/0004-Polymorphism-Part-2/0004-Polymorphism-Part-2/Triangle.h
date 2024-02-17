#ifdef _MSC_VER
#pragma once
#endif
#ifndef TRIANGLE
#define TRIANGLE
#include "Shape.h"

class Triangle : public Shape
{
private:
	double mBase = 0;
	double mHeight = 0;
public:
	double Area();
	Triangle(double, double);
};
#endif