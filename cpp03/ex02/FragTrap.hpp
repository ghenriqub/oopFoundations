/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:46:30 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/22 20:24:12 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(std::string const &name);
        FragTrap(FragTrap const &copy);
        ~FragTrap(void);

        FragTrap    &operator=(FragTrap const &trap);

        void    attack(const std::string& target);
        void    highFiveGuys(void);
};

#endif
