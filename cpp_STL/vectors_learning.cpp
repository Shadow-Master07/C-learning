#include <iostream>
#include <vector>
#include <string>

typedef struct newDataType
{
    int count;
    float cash;
    std::string name;
    bool truth;
    char simpleChar;

} d_type;

// template <typename T>
void printing(std::vector<int> vect)
{
    std::cout << "Entering" << std::endl;
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // std::vector<datatype> vectorName;
    std::vector<int> list;
    for (int i = 0; i < 10; i++)
    {
        list[i] = (i + 1) * 2;
    }
    std::cout << "Running" << std::endl;
    printing(list);

    return 0;
}