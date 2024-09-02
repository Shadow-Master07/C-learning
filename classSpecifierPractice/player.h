#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"

// Inheriting from person class into player class
class Player : public Person
{
    private:
        friend std::ostream& operator<< (std::ostream& out, const Player& player);

    public:
        Player();
        ~Player();
    
    public:
        void play()
        {
            m_fullName = "John Wick"; // OK as public
            m_age = 52; // OK as protected
            // m_address = "Does not work"; // Not working as private
        }
    
    private:
        int m_careerStartYear{0};
        double m_salary{0.0};
        int m_healthFactor{0};
        
};

#endif