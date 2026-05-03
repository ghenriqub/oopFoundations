/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:03:21 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:25:00 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Only change from ex01: makeSound() becomes = 0 (pure virtual). This makes
// Animal abstract — compiler now forbids new Animal(), enforcing that only
// concrete subclasses can exist.

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(); 
		
		virtual void	makeSound() const = 0;

		std::string	getType() const;
};

#endif

