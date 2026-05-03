/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:00:19 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:20:24 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Inherits from WrongAnimal and overrides makeSound(), but the override is
// invisible through a WrongAnimal* pointer because there's no vtable lookup —
// static binding wins.

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	protected:
	
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		virtual ~WrongCat();
		
		void makeSound() const;
};

#endif