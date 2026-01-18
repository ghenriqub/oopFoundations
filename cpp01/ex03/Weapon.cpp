/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:14:19 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/18 14:13:37 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newType) {
	this->setType =;
}

Weapon::~Weapon(void) {
	std::cout << this->getType() << " dropped to the floor and broke." << std::endl;
}

const std::string	Weapon::getType(void) {
	return this->type;
}

void	Weapon::setType(std::string newType) {
	this->type = newType;
}