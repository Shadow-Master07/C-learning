#include "playerClass.h"

// Constructor
Player::Player()
{
    locus.x = 0;
    locus.y = 0;
}

// Method definition Setters
void Player::set_Name(std::string name)
{
    Player::Name = name;
}
void Player::set_type(std::string type)
{
    Player::type = type;
}
void Player::set_ID(int id)
{
    Player::ID = id;
}
void Player::set_hex(std::string hexaVal)
{
    Player::hex = hexaVal;
}
void Player::set_movement(Player::movementEnum movementKey)
{
    Player::movement = movementKey;

    switch (Player::movement)
    {
    case w:
        locus.y += 5;
        break;
    case s:
        locus.y -= 5;
        break;
    case d:
        locus.x += 5;
        break;
    case a:
        locus.x -= 5;
        break;
    }
}

// Method definition Getters
std::string Player::get_name()
{
    return Name;
}
std::string Player::get_type()
{
    return type;
}
int Player::get_ID()
{
    return ID;
}
std::string Player::get_hex()
{
    return hex;
}
s_location Player::get_movement()
{
    return locus;
}
