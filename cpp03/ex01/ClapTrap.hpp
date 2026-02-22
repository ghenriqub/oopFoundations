/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:43:48 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/22 19:29:45 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>

class   ClapTrap {
    protected:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &copy);
        ~ClapTrap(void);

        ClapTrap    &operator=(ClapTrap const &copy);

        std::string getName(void) const;
        int         getHitPoints(void) const;
        int         getEnergyPoints(void) const;
        int         getAttackDamage(void) const;

        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        bool        isGameOver(void);
};

std::ostream    &operator<<(std::ostream &out, ClapTrap const &trap);

#endif
