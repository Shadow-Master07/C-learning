#include <iostream>
#include "person.h"
#include "nurse.h"

// namespace std
// {
//     template <typename _CharT, typename _Traits>
//     inline basic_ostream<_CharT, _Traits> &
//     tab(basic_ostream<_CharT, _Traits> &__os)
//     {
//         return flush(__os.put(__os.widen('\t')));
//     }
// }


Nurse::Nurse()
{

}


Nurse::~Nurse()
{
    
}

std::ostream& operator<<(std::ostream& out, const Nurse& nurse)
{
    out << "Nurse (" << &nurse << ") :" << std::endl
        << std::tab << "[" << std::endl
        << std::tab << std::tab << "Name : " << nurse.get_fullName() << "," << std::endl
        << std::tab << std::tab << "Age : " << nurse.get_age() << "," << std::endl
        << std::tab << std::tab << "Address : " << nurse.get_address() << std::endl
        << std::tab << "]" << std::endl;
    
    return out;
}
