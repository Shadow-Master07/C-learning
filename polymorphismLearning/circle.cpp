#include "circle.h"

Circle::Circle(double radius, std::string_view description)
    : Oval(radius, radius, description)
{
    hP = 11111;
}

Circle::~Circle()
{
}
