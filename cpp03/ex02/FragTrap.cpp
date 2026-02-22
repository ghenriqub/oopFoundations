/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:49:59 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/22 20:03:38 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
    std::cout << "FragTrap constructor with parameter called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap    &FragTrap::operator=(FragTrap const &copy) {
    if (this == &copy)
        return (*this);
    this->_name = copy.getName();
    this->_hitPoints = copy.getHitPoints();
    this->_energyPoints = copy.getEnergyPoints();
    this->_attackDamage = copy.getAttackDamage();
    return (*this);
}

void    FragTrap::attack(std::string const &target) {
    if (!this->_energyPoints || !this->_hitPoints) {
        std::cout << "FragTrap " << this->_name << " is out of action!" << std::endl;
        return ;
    }
	std::cout << "FragTrap " << this->_name << " bombs " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void    highFiveGuys(void) {
    std::cout << "FragTrap " << this->_name << " high five everyone!" << std::endl;
}

