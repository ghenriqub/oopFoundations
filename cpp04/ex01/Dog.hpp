/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:02:10 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:23:56 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Mirror of Cat's brain management: new Brain() in constructor,
// new Brain(*other._brain) in copy, delete _brain in destructor. Both classes
// follow identical resource management patterns.

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif