#include <iostream>
#include <string>

template <typename Something>
class Checker
{
    private:
        Something m_data;
    
    public:
        void m_setData(Something m_data);
        Something m_getData();
};

template <typename Something>
void Checker<Something>::m_setData(Something m_data)
{
    this->m_data = m_data;
}

template <typename Something>
Something Checker<Something>::m_getData()
{
    return this->m_data;
}

int main()
{
    Checker<int> i_data;
    i_data.m_setData(55);
    std::cout << i_data.m_getData() << std::endl;

    std::cout << "------------------------" << std::endl;

    Checker<std::string> str_data;
    str_data.m_setData("Humba lila, Humba lilo, Humba lile");
    std::cout << str_data.m_getData() << std::endl;
    return 0;
}