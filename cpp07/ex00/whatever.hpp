/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:47:41 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/26 17:56:13 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template    <typename T>
void        swap(T& a, T& b) {
    T   tmp = a;
    a = b;
    b = tmp;
}

template    <typename T>
const       T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template    <typename T>
const       T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

#endif
