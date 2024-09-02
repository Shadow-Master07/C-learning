#include <iostream>

#include "shape.h"
#include "oval.h"
#include "circle.h"

void drawShapes(Shape *collection[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        (collection[i])->draw();
    }
}

int main()
{
    Shape shape1("Shape", 101);
    Oval oval1(2.4, 5.2, "Oval");
    Circle circle1(5, "Circle");

    Shape *shared_ptr[] = {&shape1, &oval1, &circle1};

    for (Shape *sptr : shared_ptr)
    {
        sptr->draw();
    }

    
    std::cout << std::endl;

    drawShapes(shared_ptr, sizeof(shared_ptr) / sizeof(&shape1));

    return 0;
}
