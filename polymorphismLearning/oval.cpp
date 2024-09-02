#include "oval.h"

Oval::Oval(double xRadius, double yRadius, std::string_view description)
    : Shape(description, 20), m_xRadius(xRadius), m_yRadius(yRadius)
{
    // hP=20;
}

Oval::~Oval()
{
}


double Oval::get_xRadius() const
{
    return m_xRadius;
}


double Oval::get_yRadius() const
{
    return m_yRadius;
}


