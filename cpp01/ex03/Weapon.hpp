/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:59:22 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/18 14:04:30 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon {
	private:
		std::string	_type;
	public:
		Weapon(std::string _type);
		~Weapon(void);
		const std::string	getType(void);
		void				setType(std::string _type);
};

#endif