#ifndef ENGINEER_H
#define ENGINEER_H

#include <iostream>
#include "person.h"

class Engineer : private Person
{
    private:
        friend std::ostream& operator<<(std::ostream& out, const Engineer& engineer);

    public:
        Engineer();
        ~Engineer();

        void buildSomething()
        {
            // remaining 2 are now private to this class
            m_fullName = "Brock Lessnar";
            m_age = 21;
            // m_address = "Some address" // this line fails as it is private in person class
        }

    private:
        int contractCount{0};

};

#endif