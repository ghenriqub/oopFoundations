/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:59:32 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:15:53 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Inherits from Animal, sets type = "Dog", overrides makeSound() with "Woof".
// Copy assignment delegates to Animal::operator= so the base type field is
// properly copied.

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Woof woof" << std::endl;
}

