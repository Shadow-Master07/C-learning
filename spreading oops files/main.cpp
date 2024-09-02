#include "structLocus.h"
#include "playerClass.h"

int main()
{
    Player player;
    player.set_Name("John");
    player.set_type("Warrior");
    player.set_ID(1);
    player.set_hex("#FF5733");


    std::cout << "Player Name: " << player.get_name() << std::endl;
    std::cout << "Player Type: " << player.get_type() << std::endl;
    std::cout << "Player ID: " << player.get_ID() << std::endl;
    std::cout << "Player Hex: " << player.get_hex() << std::endl;

    std::string movementKeysToUse;
    std::cout << "Enter movements\n";
    std::cin >> movementKeysToUse;

    int sizeOfMovementString = movementKeysToUse.length();
    for (int i = 0; i < sizeOfMovementString; i++){
        switch (movementKeysToUse[i])
        {
        case 'w':
            player.set_movement(Player::w);
            break;
        case 's':
            player.set_movement(Player::s);
            break;
        case 'a':
            player.set_movement(Player::a);
            break;
        case 'd':
            player.set_movement(Player::d);
            break;
        }
    }
    s_location loc = player.get_movement();
    std::cout << "Player Location: (" << loc.x << ", " << loc.y << ")" << std::endl;
    return 0;
}