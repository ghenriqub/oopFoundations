/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:59:21 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:19:15 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Same pattern as Dog but for cats, type = "Cat", makeSound() prints "Meow".
// Demonstrates that multiple derived classes can each provide their own
// polymorphic behavior.

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	private:

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const;
};

#endif