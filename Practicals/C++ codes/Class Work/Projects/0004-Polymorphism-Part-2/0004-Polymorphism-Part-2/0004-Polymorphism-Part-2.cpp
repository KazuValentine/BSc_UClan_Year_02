#include <iostream>
#include <crtdbg.h>
#include <typeinfo>
#include "Rectangle.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

int main()
{
#ifdef _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    Shape* Shapes[] = { new Rectangle(2, 3), new Square(5), new Triangle(2, 3) };

    for (int i = 0; i < sizeof(Shapes) / sizeof(Shapes[0]); i++)
    {
        std::cout << "Area of the ";
        if (typeid(*Shapes[i]) == typeid(Square))
        {
            std::cout << "Square";
        }
        else if (typeid(*Shapes[i]) == typeid(Rectangle))
        {
            std::cout << "Rectangle";
        }
        else if (typeid(*Shapes[i]) == typeid(Triangle))
        {
            std::cout << "Triangle";
        }
        //if (Square* pSquare = dynamic_cast<Square*>(Shapes[i]))
        //{
        //    std::cout << "Square";
        //}
        //else if (Rectangle* pRectangle = dynamic_cast<Rectangle*>(Shapes[i]))
        //{
        //    std::cout << "Rectangle";
        //}
        //else if (Triangle* pTriangle = dynamic_cast<Triangle*>(Shapes[i]))
        //{
        //    std::cout << "Triangle";
        //}
        else
        {
            std::cout << "Shape";
        }
        std::cout << ": " << Shapes[i]->Area() << '\n';
        delete Shapes[i];
        Shapes[i] = nullptr;
    }
#ifdef _MSC_VER
    _CrtDumpMemoryLeaks();
#endif
    return 0;
}
