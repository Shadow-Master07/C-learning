#include <iostream>
#include "person.h"

Person::Person(std::string_view fullName, int age, const std::string address)
{
    this->m_fullName = fullName;
    this->m_age = age;
    this->m_address = address;
}

std::ostream &operator<<(std::ostream &out, const Person &person)
{
    out << "Person (" << &person << ") :" << std::endl
        << std::tab << "[" << std::endl
        << std::tab << std::tab << "Name : " << person.get_fullName() << "," << std::endl
        << std::tab << std::tab << "Age : " << person.get_age() << "," << std::endl
        << std::tab << std::tab << "Address : " << person.get_address() << std::endl
        << std::tab << "]" << std::endl;
    
    return out;
}
