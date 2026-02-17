/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:40:44 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/02/17 15:31:08 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    this->_value = 0;
}

Fixed::Fixed(Fixed const &copy) {
    *this = copy;
}

Fixed::Fixed(int const value) {
    this->_value = value * (1 << Fixed::_bits);
}

Fixed::Fixed(float const value) {
    this->_value = roundf(value * (1 << Fixed::_bits));
}

Fixed::~Fixed() {}

// arithmetic operators

Fixed   &Fixed::operator=(Fixed const &copy) {
    if (this == &copy)
        return (*this);
    this->_value = copy.getRawBits();
    return  (*this);
}

Fixed   Fixed::operator+(Fixed const &copy) const {
    return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed   Fixed::operator-(Fixed const &copy) const {
    return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed   Fixed::operator*(Fixed const &copy) const {
    return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed   Fixed::operator/(Fixed const &copy) const {
    return (Fixed(this->toFloat() / copy.toFloat()));
}

// comparison operators

bool    Fixed::operator>(Fixed const &copy) const {
    return (this->getRawBits() > copy.getRawBits());
}

bool    Fixed::operator<(Fixed const &copy) const {
    return (this->getRawBits() < copy.getRawBits());
}

bool    Fixed::operator>=(Fixed const &copy) const {
    return (this->getRawBits() >= copy.getRawBits());
}

bool    Fixed::operator<=(Fixed const &copy) const {
    return (this->getRawBits() <= copy.getRawBits());
}

bool    Fixed::operator==(Fixed const &copy) const {
    return (this->getRawBits() == copy.getRawBits());
}

bool    Fixed::operator!=(Fixed const &copy) const {
    return (this->getRawBits() != copy.getRawBits());
}

// increment operators

Fixed   Fixed::operator++(void) {
    this->_value++;
    return (*this);
}

Fixed   Fixed::operator--(void) {
    this->_value--;
    return (*this);
}

Fixed   Fixed::operator++(int tmp) {
    (void)tmp;
    Fixed   duplicate(*this);
    ++(*this);
    return (duplicate);
}

Fixed   Fixed::operator--(int tmp) {
    (void)tmp;
    Fixed   duplicate(*this);
    --(*this);
    return (duplicate);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b) {
    return (a > b ? b : a);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

int     Fixed::getRawBits(void) const {
    return (this->_value);
}

void    Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

int     Fixed::toInt(void) const {
    return (this->_value / (1 << Fixed::_bits));
}

float   Fixed::toFloat(void) const {
    return ((float)this->_value / (float)(1 << Fixed::_bits));
}

std::ostream    &operator<<(std::ostream &out, Fixed const &copy) {
    out << copy.toFloat();
    return (out);
}

