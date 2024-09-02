#ifndef NURSE_H
#define NURSE_H

#include "person.h"

class Nurse : protected Person
{
    private:
        friend std::ostream& operator<<(std::ostream& out, const Nurse& nurse);

    public:
        Nurse();
        ~Nurse();

        void treatPatientsWell()
        {
            m_fullName = "Brock Lessnar";
            m_age = 21;
            // m_address = "Some address" // this line fails as it is private in person class
        }

    private:
        int practiceTrainingCertificate{0};

};

#endif