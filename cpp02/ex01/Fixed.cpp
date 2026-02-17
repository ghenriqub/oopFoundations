/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:52:56 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/16 18:56:19 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(Fixed const &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int const value) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = value * (1 << Fixed::_bits);
}

Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << Fixed::_bits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &copy) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_value = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const {
    return (this->_value);
}

void    Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

int Fixed::toInt(void) const {
    return (this->_value / (1 << Fixed::_bits));
}

float   Fixed::toFloat(void) const {
    return ((float)this->_value / (float)(1 << Fixed::_bits));
}

std::ostream    &operator<<(std::ostream &out, Fixed const &copy) {
    out << copy.toFloat();
    return (out);
}

