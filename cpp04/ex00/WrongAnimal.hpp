/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:00:01 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:17:31 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Identical to Animal except makeSound() is NOT virtual (no dynamic dispatch).
// Exists as a counter-example to prove that without virtual, the base version
// always runs.

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();
		
		void makeSound() const;
		std::string getType() const;
};

#endif