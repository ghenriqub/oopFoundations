/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:40:58 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/17 17:36:12 by ghenriqu         ###   ########.fr       */
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
        Fixed operator+(Fixed const &copy) const;
        Fixed operator-(Fixed const &copy) const;
        Fixed operator*(Fixed const &copy) const;
        Fixed operator/(Fixed const &copy) const;

        bool operator>(Fixed const &copy) const;
        bool operator>=(Fixed const &copy) const;
        bool operator<(Fixed const &copy) const;
        bool operator<=(Fixed const &copy) const;
        bool operator==(Fixed const &copy) const;
        bool operator!=(Fixed const &copy) const;

        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int a);
        Fixed operator--(int a);

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static Fixed const &min(Fixed const &a, Fixed const &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream    &operator<<(std::ostream &out, Fixed const &copy);

#endif
