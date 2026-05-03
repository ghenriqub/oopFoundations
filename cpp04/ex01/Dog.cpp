/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:02:02 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:23:49 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Mirror of Cat's brain management: new Brain() in constructor,
// new Brain(*other._brain) in copy, delete _brain in destructor. Both classes
// follow identical resource management patterns.

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog::~Dog() {
	if (this->_brain)
		delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Woof woof" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->_brain;
}