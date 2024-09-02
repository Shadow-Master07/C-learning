#include <iostream>

typedef struct coordinates
{
    float x;
    float y;
} xy;

typedef struct check
{
    int a, b, c;

} check;

int main()
{
    xy locus = {5, 6};
    xy locus2{.x = 10, .y = 20};

    auto move1 = [locus]()
    {
        std::cout << "(x,y) : (" << locus.x << "," << locus.y << ")" << std::endl;
    }; // Capture by value

    auto move2 = [&locus]()
    {
        std::cout << "(x,y) : (" << locus.x << "," << locus.y << ")" << std::endl;
    }; // Capture by reference

    // auto move3 = [*locus]()
    // {
    //     std::cout << "(x,y) : (" << locus->x << "," << locus->y << ")" << std::endl;
    // };

    auto allVal = [=]()
    {
        std::cout << "Captured all" << std::endl;
        std::cout << "locus1: (" << locus.x << "," << locus.y << ")" << std::endl;
        std::cout << "locus2: (" << locus2.x << "," << locus2.y << ")" << std::endl;
    }; // Capturing all values by value

    auto allRef = [&]()
    {
        std::cout << "Captured all" << std::endl;
        std::cout << "locus1: (" << locus.x << "," << locus.y << ")" << std::endl;
        std::cout << "locus2: (" << locus2.x << "," << locus2.y << ")" << std::endl;
    }; // Capturing all values by reference

    // Showing what moving might look like
    for (int i = 0; i < 20; i++)
    {
        move1();
        allVal();
        move2();
        locus.x += 2;
        locus.y += 5;
        // std::cout << "=========================" << std::endl;
        allRef();
        locus2.x += 2;
        locus2.y += 5;
        std::cout << "=========================" << std::endl;
    }

    // Checking lambda to get to limit and increment values accordingly
    check lambda, limit{.a{10}, .b{20}, .c{30}};
    lambda.a = 0;
    lambda.b = 0;
    lambda.c = 0;

    auto addition = [&lambda](int a, int b, int c) -> bool
    {
        if (lambda.a != a)
        {
            (lambda.a)++;
        }
        if (lambda.b != b)
        {
            (lambda.b)++;
        }
        if (lambda.c != c)
        {
            (lambda.c)++;
        }
        std::cout << "(" << lambda.a << "," << lambda.b << "," << lambda.c << ")" << std::endl;

        return ((lambda.a == a) && (lambda.b == b) && (lambda.c == c));
    };

    bool truth = false;

    std::cout << "=========================" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "=========================" << std::endl;

    while (!truth)
    {
        truth = addition(limit.a, limit.b, limit.c);
    };

    std::cout << "=========================" << std::endl;

    return 0;
}