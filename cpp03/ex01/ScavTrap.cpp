/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:05:27 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/22 20:32:37 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
  	std::cout << "ScavTrap Foo constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
  	std::cout << "ScavTrap constructor with parameter called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &copy) {
    if (this == &copy)
        return (*this);
    ClapTrap::operator=(copy);
    return(*this);
}

void    ScavTrap::attack(std::string const &target) {
    if (!this->getHitPoints() || !this->getEnergyPoints()) {
        std::cout << "ScavTrap " << this->_name << " is out of action!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " bombs " << target;
    std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void    ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->_name << " has entered in gatekeeper mode" << std::endl;
}

