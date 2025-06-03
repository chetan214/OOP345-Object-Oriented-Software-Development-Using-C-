/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Date	   : 14 Feb 2025
 
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H

#include "character.h"
#include <iostream>

namespace seneca {

template <typename T> class CharacterTpL : public Character {
  int m_healthMax;
  T m_health;

public:
  // Constructor initializing character name and health
  CharacterTpL(const char *name, int healthMax)
      : Character(name), m_healthMax(healthMax) {
    m_health = (int)m_healthMax;
  }

  // Copy constructor
  CharacterTpL(const CharacterTpL &other)
      : Character(other.getName().c_str()), m_healthMax(other.m_healthMax) {
    m_health = (int)other.m_healthMax;
  }

  void takeDamage(int dmg) override {
    m_health -= dmg;
    if (m_health < 0) {
      m_health = 0;
    }

    if (Character::isAlive() == false) {
      std::cout << "    " << Character::getName() << " has been defeated!\n";
    } else {
      std::cout << "    " << Character::getName() << " took " << dmg
                << " damage, " << getHealth() << " health remaining.\n";
    }
  }

  int getHealth() const override { return static_cast<int>(m_health); }

  int getHealthMax() const override { return m_healthMax; }

  void setHealth(int health) override { m_health = health; }

  void setHealthMax(int health) override { m_healthMax = health; }
};

} // namespace seneca

#endif