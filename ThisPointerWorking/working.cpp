#include <iostream>
#include <string>
#include <string_view>

// std::endl like thing but for std::tab
namespace std
{
    template <typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits> &
    tab(basic_ostream<_CharT, _Traits> &__os)
    {
        return __os.put(__os.widen('\t'));
    }
}

/* Source code taken from original endl definition

// namespace std
// {
//     template<typename _CharT, typename _Traits>
//     inline basic_ostream<_CharT, _Traits>&
//     endl(basic_ostream<_CharT, _Traits>& __os)
//     {
//         return flush(__os.put(__os.widen('\n')));
//     }
// }

*/

class Dog
{
    public:
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int age_param);
        ~Dog();

    private:
        std::string name;
        std::string breed;
        int *p_age{nullptr};

    public:
        void printInfo();
        Dog* set_dogName(std::string name);
        Dog* set_dogBreed(std::string breed);
        Dog* set_dogAge(int age);
};

/*
// This makes the code go through default declaration and definition

// Dog::Dog()
// {
//     name = "none";
//     breed = "none";
//     p_age = new int;
//     *p_age = 0;

//     std::cout << "Dog " << name << " constructed at location in memory at " << this << std::endl;
// }
*/

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Constructor called for " << name << " at " << this << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Destructor called for " << name <<  " at " << this << std::endl;
}

Dog* Dog::set_dogName(std::string name)
{
    this->name = name;
    return this;
}

Dog* Dog::set_dogBreed(std::string breed)
{
    this->breed = breed;
    return this;
}

Dog* Dog::set_dogAge(int age)
{
    *(this->p_age) = age;
    return this;
}

void Dog::printInfo()
{
    std::cout << "Dog (" << this
    << ") : " << std::endl << std::tab
    << "[" << std::endl << std::tab << std::tab
    << "Name : " << name << ", " << std::endl << std::tab << std::tab
    << "Breed : " << breed << ", " << std::endl << std::tab << std::tab
    << "Age : " << *p_age << std::endl << std::tab
    << "]" << std::endl;
}

int main()
{
    Dog dog1("Fluffy", "Shepherd", 7);

    // dog1.set_dogName("Baghira");
    // dog1.set_dogBreed("Rottweiler");
    // dog1.set_dogAge(10);
    
    dog1.set_dogName("Baghira")->set_dogBreed("Rottweiler")->set_dogAge(10);
    dog1.printInfo();

    std::cout << "Done " << std::endl;
    return 0;
}