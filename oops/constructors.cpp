#include <iostream>
#include <string>

class Person
{
    public:
        std::string Name;
        std::string Work;
        float Salary;
        int Age;

    public:
        Person(std::string Name, std::string Work, float Salary, int Age)
        {
            this->Name = Name;
            this->Work = Work;
            this->Salary = Salary;
            this->Age = Age;
        }

    public:
        void introduction()
        {
            std::cout << "Hello my name is " << Name << ". I am a " << Work << ". My salary is " << Salary << ". My age is " << Age << std::endl;
        }


};

int main()
{
    Person person1 = Person ("Priyanshu", "Student", -138000, 19);
    person1.introduction();

    return 0;
}