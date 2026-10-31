/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:59:31 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/26 18:01:34 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template    <typename T, typename F>
void        iter(T* array, const size_t length, F func) {
    if (!array)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif
