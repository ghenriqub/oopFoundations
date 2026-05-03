/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:25:51 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:15:46 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Inherits from Animal, sets type = "Dog", overrides makeSound() with "Woof".
// Copy assignment delegates to Animal::operator= so the base type field is
// properly copied.

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private:

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const;
};

#endif