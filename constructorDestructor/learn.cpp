#include <iostream>
#include <string>
#include <string_view>

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
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Constructor called for " << name << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Destructor called for " << name << std::endl;
}

void doggy(Dog dog)
{
    Dog dog1 = dog;
}

void p_doggy(Dog *dog)
{
    Dog *dog1 = new Dog;
    dog1 = dog;
}

void r_doggy(Dog &dog)
{
    Dog dog1 = dog;
}

int main()
{
    Dog dog1 = Dog("Baghira1", "Rottweiler", 1);
    Dog *dog2 = new Dog("Baghira2", "Rottweiler", 2);

    Dog dog3 = Dog("Baghira3", "Rottweiler", 3);
    doggy(dog3);
    Dog dog4 = Dog("Baghira4", "Rottweiler", 4);
    p_doggy(&dog4);
    Dog dog5 = Dog("Baghira5", "Rottweiler", 5);
    r_doggy(dog5);

    return 0;
}
