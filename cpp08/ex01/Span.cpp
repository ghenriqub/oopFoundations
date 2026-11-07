/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:57:58 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/10/31 16:23:03 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(void) : _max(0) {}

Span::Span(unsigned int n) : _max(n) {
	_data.reserve(n);
}

Span::Span(Span const &other) : _max(other._max), _data(other._data) {}

Span	&Span::operator=(Span const &other) {
	if (this != &other)
	{
		_max = other._max;
		_data = other._data;
	}
	return (*this);
}

Span::~Span(void) {}

void	Span::addNumber(int n)
{
	if (_data.size() >= _max)
		throw std::length_error("Span: already full");
	_data.push_back(n);
}

static unsigned int distance(int lo, int hi) {
    return (static_cast<unsigned int>(hi) - static_cast<unsigned int>(lo));
}

unsigned int	Span::shortestSpan(void) const {
	if (_data.size() < 2)
		throw std::logic_error("Span: need at least 2 numbers");

	std::vector<int>	sorted(_data);
	std::sort(sorted.begin(), sorted.end());

	unsigned int	shortest = distance(sorted[0], sorted[1]);
	for (std::size_t i = 2; i < sorted.size(); i++)
		shortest = std::min(shortest, distance(sorted[i - 1], sorted[i]));
	return (shortest);
}

unsigned int	Span::longestSpan(void) const
{
	if (_data.size() < 2)
		throw std::logic_error("Span: need at least 2 numbers");

	int	lo = *std::min_element(_data.begin(), _data.end());
	int	hi = *std::max_element(_data.begin(), _data.end());
	return (distance(lo, hi));
}
