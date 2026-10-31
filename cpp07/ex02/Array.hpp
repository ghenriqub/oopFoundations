/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 18:08:24 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/26 18:19:54 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>

template    <typename T>
class       Array {
    private:
        T*              _data;
        unsigned int    _size;
    public:
        Array();
        Array(unsigned int  n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T&              operator[](unsigned int i);
        const T&        operator[](unsigned int i) const;
        unsigned int    size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

# include "Array.tpp"

#endif
