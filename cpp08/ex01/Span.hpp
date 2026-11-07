/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:49:59 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/10/31 17:09:53 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <stdexcept>

class Span {
    private:
		unsigned int		_max;
		std::vector<int>	_data;
    public:
        Span(void);
        Span(unsigned int n);
        Span(Span const &other);
        Span    &operator=(Span const &other);
        ~Span(void);

        void            addNumber(int n);
        unsigned int    shortestSpan(void) const;
        unsigned int    longestSpan(void) const;
        
        template <typename It>
        void    addNumbers(It begin, It end)
        {
            std::size_t count = static_cast<std::size_t>(std::distance(begin, end));
            
            if (count > _max - _data.size())
                throw std::length_error("Span: not enough space for this range");
            _data.insert(_data.end(), begin, end);
        }
};

#endif
