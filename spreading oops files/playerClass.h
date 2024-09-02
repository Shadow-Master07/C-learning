#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <iostream>
#include <string>
#include "structLocus.h"

class Player
{
    private:
        std::string Name;
        std::string type;
        int ID;
        std::string hex;
        s_location locus;

    public:
        enum movementEnum
        {
            w,s,a,d
        };

        movementEnum movement;

        Player();

    public: 
        void set_Name(std::string name);
        void set_type(std::string type);
        void set_ID(int id);
        void set_hex(std::string hexaVal);
        void set_movement(movementEnum movementKey);

    public:
        std::string get_name();
        std::string get_type();
        int get_ID();
        std::string get_hex();
        s_location get_movement();
};

#endif