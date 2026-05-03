/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:00:54 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 18:00:56 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(); // needed to avoid leaks when deleting a type Animal* pointer
						  // that poitns to a Dog/Cat object so the Dog/Cat destructor
						  // is called before the Animal destructor 
		
		virtual void	makeSound() const; // allows the specfic sound be decided in execution time
						// regradless of the type of the pointer

		std::string	getType() const;
};

#endif
