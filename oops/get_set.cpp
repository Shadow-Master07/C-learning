#include <iostream>
#include <string>

typedef struct worldLocation
{
    int x;
    int y;
} s_location;


class Player
{
    private:
        std::string Name;
        std::string type;
        int ID;
        std::string hex;
        s_location locus;

    public:
        enum movementEnum{w, s, a, d};
        movementEnum movement;
        Player()
        {
            locus.x = 0;
            locus.y = 0;
        }


    public: // Complete this part
        void set_Name(std::string name)
        {
            Player::Name = name;
        }
        void set_type(std::string type)
        {
            Player::type = type;
        }
        void set_ID(int id)
        {
            Player::ID = id;
        }
        void set_hex(std::string hexaVal)
        {
            Player::hex = hexaVal;
        }
        void set_movement(movementEnum movementKey)
        {
            Player::movement = movementKey;
            

            switch(this->movement)
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

    public:
        std::string get_name()
        {
            return this->Name;
        }
        std::string get_type()
        {
            return this->type;
        }
        int get_ID()
        {
            return this->ID;
        }
        std::string get_hex()
        {
            return this->hex;
        }
        s_location get_movement()
        {
            return locus;
        }
};


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