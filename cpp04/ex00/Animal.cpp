/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:11:59 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:14:57 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implements Orthodox Canonical Form: default/copy constructors, destructor,
// and operator=. makeSound and getType provide default behavior that derived
// classes override.

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "I don't know what I am";
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = other.type;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void	Animal::makeSound(void) const {
	std::cout << "I don't know what I sound like" << std::endl;
}

std::string	Animal::getType() const {
	return (this->type);
}

