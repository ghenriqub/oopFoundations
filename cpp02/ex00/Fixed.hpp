/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:27:06 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/17 17:32:14 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {
    private:
        int                 _value;
        static const int    _bits = 8;

    public:
        Fixed();
        Fixed(Fixed const &copy);
        ~Fixed();

        Fixed &operator=(Fixed const &copy);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
