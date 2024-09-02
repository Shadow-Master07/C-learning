#include <iostream>
#include "person.h"
#include "engineer.h"

Engineer::Engineer()
{
}

Engineer::~Engineer()
{
}

std::ostream &operator<<(std::ostream &out, const Engineer &engineer)
{
    out << "Player (" << &engineer << ") :" << std::endl
        << std::tab << "[" << std::endl
        << std::tab << std::tab << "Name : " << engineer.get_fullName() << "," << std::endl
        << std::tab << std::tab << "Age : " << engineer.get_age() << "," << std::endl
        << std::tab << std::tab << "Address : " << engineer.get_address() << std::endl
        << std::tab << "]" << std::endl;
    return out;
}
