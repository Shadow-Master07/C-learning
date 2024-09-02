#include "shape.h"

Shape::Shape(std::string_view description, int hp_val)
    : m_description(description)
{
    hP=hp_val;
}

Shape::~Shape()
{
}
