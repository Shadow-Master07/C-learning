#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

// Using syntax of std::tab, it does what it says
namespace std
{
    template <typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits> &
    tab(basic_ostream<_CharT, _Traits> &__os)
    {
        return flush(__os.put(__os.widen('\t')));
    }
}


class Person
{
    private:
        friend std::ostream& operator<<(std::ostream& out, const Person& person);

    public:
        Person() = default;
        Person(std::string_view fullName, int age, const std::string address);


    // Getters
    public:
        std::string get_fullName() const
        {
            return m_fullName;
        }
        
        int get_age() const
        {
            return m_age;
        }

        std::string get_address() const
        {
            return m_address;
        }
    
    public:
        std::string m_fullName{"None"};

    protected:
        int m_age{0};

    private:
        std::string m_address{"None"};

};

#endif