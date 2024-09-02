#include <iostream>
#include <typeinfo>

int main() {
    int myInt = 5;
    double myDouble = 5.5;
    std::string myString = "Hello";

    std::cout << "myInt is of type: " << typeid(myInt).name() << std::endl;
    std::cout << "myDouble is of type: " << typeid(myDouble).name() << std::endl;
    std::cout << "myString is of type: " << typeid(myString).name() << std::endl;

    return 0;
}
