/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:23:36 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/17 17:33:00 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
    return ;
}

Fixed::Fixed(Fixed const &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
    return ;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed &Fixed::operator=(Fixed const &copy) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_value = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void    Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

