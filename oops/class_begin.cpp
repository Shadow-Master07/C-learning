#include <iostream>

class Cylinder
{
    private:
        const double PI{3.141592};

    private:
        double square(double val)
        {
            return val * val;
        }

    public:
        double radius;
        double height;

    public:
        double volume()
        {
            return (PI * square(radius) * height);
        }
};

int main()
{
    Cylinder cy1;
    cy1.radius = 1.0;
    cy1.height = 1.0;

    std::cout << cy1.volume() << std::endl;

    return 0;
}

