/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:05:36 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/22 19:09:19 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class   ScavTrap : public ClapTrap {
    public:
        ScavTrap(void);
        ScavTrap(std::string const &name);
        ScavTrap(ScavTrap const &copy);
        ~ScavTrap(void);

        ScavTrap    &operator=(ScavTrap const &copy);

        void    guardGate(void);
        void    attack(std::string const &target);
};

#endif
