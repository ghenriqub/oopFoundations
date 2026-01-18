/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:51:12 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/17 17:59:55 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB (std::string _name);
		~HumanB (void);
		void	setWeapon(Weapon &_weapon);
		void	attack(void);
};

#endif
