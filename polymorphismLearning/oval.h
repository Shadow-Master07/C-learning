#ifndef OVAL_H
#define OVAL_H

#include "shape.h"

class Oval : public Shape
{
    public:
        Oval() = default;
        Oval(double xRadius, double yRadius, std::string_view description);
        ~Oval();

        virtual void draw() const override
        {
            std::cout << "Drawing from Oval::draw(). Drawing " << m_description << " with side a radius: " << m_xRadius << " and side of b radius: " << m_yRadius << std::endl;
        }
    
    protected:
        double get_xRadius() const;
        double get_yRadius() const;

    private:
        double m_xRadius{};
        double m_yRadius{};

};


#endif