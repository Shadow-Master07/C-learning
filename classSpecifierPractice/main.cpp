#include <iostream>

#include "person.h"
#include "player.h"
#include "nurse.h"
#include "engineer.h"

int main()
{
    Person person1("Super man is batman is my name", 132, "Manhattan and New York");
    std::cout << "person1 : " << person1 << std::endl;

    Player player1;
    player1.m_fullName = "Michael Jackson";
    player1.play();
    std::cout << "player1 : " << player1 << std::endl;

    Nurse nurse1;
    // nurse1.m_fullName = "Samuel Jackson"; // Compiler error as it is set to protected by our access modifier in nurse.h
    nurse1.treatPatientsWell();
    std::cout << "nurse1 : " << nurse1 << std::endl;

    Engineer engineer1;
    // engineer1.m_fullName = "James Bond"; // Compiler error as it is set private by our access modifier in engineer.h
    engineer1.buildSomething();
    std::cout << "engineer1 : " << engineer1 << std::endl;

    player1.play();
    return 0;
}