/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:59:12 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:19:22 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Same pattern as Dog but for cats, type = "Cat", makeSound() prints "Meow".
// Demonstrates that multiple derived classes can each provide their own
// polymorphic behavior.

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Meow meow" << std::endl;
}
