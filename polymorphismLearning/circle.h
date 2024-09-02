#ifndef CIRCLE_H
#define CIRCLE_H

#include "oval.h"

class Circle : public Oval
{
    public:
        Circle() = default;
        Circle(double radius, std::string_view description);
        ~Circle();

        virtual void draw() const override
        {
            std::cout << "Calling Circle::draw(). Drawing " << m_description << " with radius " << get_xRadius() << std::endl;
        }
};

#endif