/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:51:12 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/17 17:59:41 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanA {
	private:
		std::string	_name;
		Weapon		&_weapon;
	public:
		HumanA (std::string _name, Weapon &_weapon);
		~HumanA(void);
		void	attack(void);
};

#endif
