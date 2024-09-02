#include <memory>
#include <iostream>

// -----------------------------------------------------------
class Friends
{
    public:
        Friends(std::string name);
        ~Friends();
        void setBestFriend(std::shared_ptr<Friends> &otherFriend);
    
    private:
        std::shared_ptr<Friends> m_bestFriend;
        std::string m_name;
};

// -----------------------------------------------------------
Friends::Friends(std::string name)
{
    m_name = name;
    std::cout << "Called the constructor of Friends, that sound good" << std::endl;
}

Friends::~Friends()
{
    std::cout << "Called the destroyer of Friends, that sound good" << std::endl;
}

void Friends::setBestFriend(std::shared_ptr<Friends> &otherFriend)
{
    m_bestFriend = otherFriend;
}
// -----------------------------------------------------------

class Person
{
    public:
        Person(std::string name);
        ~Person();
        void setBestFriend(const std::weak_ptr<Person> &otherFriend);
    
    private:
        std::weak_ptr<Person> m_bestFriend;
        std::string m_name;
};

// -----------------------------------------------------------
Person::Person(std::string name)
{
    m_name = name;
    std::cout << "Called the constructor of Person, that sound good" << std::endl;
}

Person::~Person()
{
    std::cout << "Called the destroyer of Person, that sound good" << std::endl;
}

void Person::setBestFriend(const std::weak_ptr<Person> &otherFriend)
{
    m_bestFriend = otherFriend;
}
// -----------------------------------------------------------


void update_unique_ptr_value_using_reference(std::unique_ptr<int> &referingThis)
{
    *referingThis += 5;
}

std::unique_ptr<int> update_unique_ptr_value_using_move(std::unique_ptr<int> referingThis)
{
    *referingThis += 5;
    return std::move(referingThis);
}
// -----------------------------------------------------------

int main()
{
    std::unique_ptr<int> p_unique_data = std::make_unique<int>(18);
    std::unique_ptr<int> p_unique_data_new(new int(20));

    // Using pointers in function calls
    update_unique_ptr_value_using_reference(p_unique_data);
    p_unique_data_new = update_unique_ptr_value_using_move(std::move(p_unique_data_new));

    std::shared_ptr<int> p_share_data = std::make_shared<int>(21);
    std::shared_ptr<int> p_share_data_new(new int(22));

    std::shared_ptr<Friends> friend1(new Friends("Priyanshu"));
    std::shared_ptr<Friends> friend2(new Friends("Angad"));
    friend1->setBestFriend(friend2);
    friend2->setBestFriend(friend1);


    std::weak_ptr<int> p_weak_data = p_share_data_new; // Takes in the address stored in p_share_data_new and also as it is using the address, it gets the value at that location in memory
    std::shared_ptr<Person> person1(new Person("Priyanshu"));
    std::shared_ptr<Person> person2(new Person("Angad"));
    person1->setBestFriend(person2);
    person2->setBestFriend(person1);

    return 0;
}