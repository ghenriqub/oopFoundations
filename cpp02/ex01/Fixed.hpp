/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:55:34 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/16 19:00:42 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
    private:
        int                 _value;
        static const int    _bits = 8;

    public:
        Fixed();
        Fixed(Fixed const &copy);
        Fixed(int const value);
        Fixed(float const value);
        ~Fixed();

        Fixed &operator=(Fixed const &copy);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;

};

std::ostream    &operator<<(std::ostream &out, Fixed const &copy);

#endif

