/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:43:39 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/22 20:20:56 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    std::cout << "ClapTrap Foo constructor called" << std::endl;
    this->_name = "Foo";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "ClapTrap constructor with parameter called" << std::endl;
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const &copy) {
    if (this == &copy)
        return (*this);
    this->_name = copy.getName();
    this->_hitPoints = copy.getHitPoints();
    this->_energyPoints = copy.getEnergyPoints();
    this->_attackDamage = copy.getAttackDamage();
    return (*this);
}

// getters

std::string	ClapTrap::getName(void) const {return (this->_name);}
int			ClapTrap::getHitPoints(void) const {return (this->_hitPoints);}
int			ClapTrap::getEnergyPoints(void) const {return (this->_energyPoints);}
int			ClapTrap::getAttackDamage(void) const {return (this->_attackDamage);}

// member functions

bool    ClapTrap::isGameOver(void) const {
    if (!this->_energyPoints || !this->_hitPoints) {
        std::cout << "ClapTrap " << this->_name << " is out of action!" << std::endl;
        return (true);
    }
    return (false);
}

void    ClapTrap::attack(const std::string& target) {
    if (this->isGameOver())
        return ;
    std::cout << "ClapTrap " << this->_name << " attacks " << target;
    std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if ((unsigned int)this->_hitPoints <= amount)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= (int)amount;
    std::cout << "ClapTrap " << this->_name << " is attacked with " << amount << " HP!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->isGameOver())
        return ;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " is repaired with " << amount << " HP!" << std::endl;
    this->_energyPoints--;
}

std::ostream    &operator<<(std::ostream &out, ClapTrap const &trap) {
    out << "ClapTrap " << trap.getName() << " has " << trap.getHitPoints() << " HP and ";
    out << trap.getEnergyPoints() << " battery life.";
    return (out);
}

