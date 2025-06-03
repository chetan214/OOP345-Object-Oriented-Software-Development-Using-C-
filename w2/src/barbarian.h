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
#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include "characterTpl.h"
#include <iostream>

namespace seneca {

template <typename T, typename Ability_t, typename Weapon_t>
class Barbarian : public CharacterTpL<T> {

  int m_baseAttack;
  int m_baseDefense;

  Ability_t m_ability;
  Weapon_t m_weapon[2];

public:
  // Constructor to initialize Barbarian with health, attack, defense, ability, and weapon
  Barbarian(const char *name, int healthMax, int baseAttack, int baseDefense,
            Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
      : CharacterTpL<T>(name, healthMax), m_baseAttack(baseAttack),
        m_baseDefense(baseDefense) {
    m_weapon[0] = primaryWeapon;
    m_weapon[1] = secondaryWeapon;
  }

  // Copy constructor
  Barbarian(const Barbarian &other) : CharacterTpL<T>(other) {
    m_baseAttack = other.m_baseAttack;
    m_baseDefense = other.m_baseDefense;
    m_weapon[0] = other.m_weapon[0];
    m_weapon[1] = other.m_weapon[1];
    m_ability = other.m_ability;
  }

  int getAttackAmnt() const override {
    return m_baseAttack + (double)m_weapon[0] / 2 + (double)m_weapon[1] / 2;
  }

  int getDefenseAmnt() const override { return m_baseDefense; }
  
  // Clone method for duplicating a Barbarian
  Character *clone() const override { return new Barbarian(*this); }

  // Barbarian attacking an enemy character
  void attack(Character *target) override {
    std::cout << CharacterTpL<T>::getName() << " is attacking "
              << target->getName() << ".\n";
    m_ability.useAbility(this);
    int dmg = getAttackAmnt();
    m_ability.transformDamageDealt(dmg);
    std::cout << "    Barbarian deals " << dmg << " melee damage!\n";
    target->takeDamage(dmg);
  }

  // Take damage and reduce it by defense value
  void takeDamage(int dmg) override {
    std::cout << CharacterTpL<T>::getName() << " is attacked for " << dmg
              << " damage.\n";
    std::cout << "    Barbarian has a defense of " << getDefenseAmnt()
              << ". Reducing damage received.\n";

    dmg -= getDefenseAmnt();
    if (dmg < 0) {
      dmg = 0;
    }

    m_ability.transformDamageReceived(dmg);
    CharacterTpL<T>::takeDamage(dmg);
  }
};

} // namespace seneca

#endif