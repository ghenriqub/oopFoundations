/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:01:53 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:23:19 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Now owns a Brain* allocated with new. Copy constructor deep-copies the brain,
// operator= deletes old brain before allocating new one. Destructor frees the
// brain to prevent leaks.

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif