#include <iostream>
#include <thread>
#include <cmath>

int multiCalci(int a, int b, int c)
{
    int power = static_cast<int>(pow(b, c));
    if (a == power)
    {
        return power;
    }

    a++;
    std::cout << a << " " << b << " " << c << " " << std::endl;
    return multiCalci(a, b, c);
}

void threadFunction()
{
    int result = multiCalci(1, 8, 3);
    std::cout << "Result: " << result << std::endl;
}


int main()
{
    std::thread repeater(threadFunction);
    repeater.join();

    return 0;
}