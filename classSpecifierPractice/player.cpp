#include <iostream>
#include "player.h"
#include "person.h"

Player::Player()
{
}

Player::~Player()
{
}

std::ostream &operator<<(std::ostream &out, const Player &player)
{
    out << "Player (" << &player << ") :" << std::endl
        << std::tab << "[" << std::endl
        << std::tab << std::tab << "Name : " << player.get_fullName() << "," << std::endl
        << std::tab << std::tab << "Age : " << player.get_age() << "," << std::endl
        << std::tab << std::tab << "Address : " << player.get_address() << std::endl
        << std::tab << "]" << std::endl;
    return out;
}
