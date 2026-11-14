/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:55:32 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/14 19:00:19 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <cctype>
#include <climits>
#include <cstddef>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

/* ------------------------- Orthodox Canonical Form ------------------------ */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

/* ------------------------- Container-agnostic helpers --------------------- */
static int	parseToken(const std::string &token)
{
	long	value = 0;

	if (token.empty())
		throw std::runtime_error("empty token");
	for (size_t i = 0; i < token.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			throw std::runtime_error("not a non-negative integer");
		int	digit = token[i] - '0';
		if (value > (INT_MAX - digit) / 10)
			throw std::runtime_error("value out of range");
		value = value * 10 + digit;
	}
	return static_cast<int>(value);
}

// Jacobsthal numbers:
// J(0)=0, J(1)=1, J(k)=J(k-1)+2*J(k-2) -> 0 1 1 3 5 11 21 43 ...
static size_t	jacobsthal(size_t k) {
	size_t	prev = 0;
	size_t	curr = 1;

	if (k == 0)
		return 0;
	for (size_t i = 1; i < k; ++i) {
		size_t	next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	return curr;
}

static double	elapsedUs(std::clock_t start, std::clock_t end) {
	return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

/* ----------------------------- std::vector version ------------------------ */

static size_t	searchVector(const std::vector<size_t> &chain, const std::vector<int> &keys, size_t elem)
{
	size_t	lo = 0;
	size_t	hi = chain.size();

	while (lo < hi) {
		size_t	mid = lo + (hi - lo) / 2;

		if (keys[chain[mid]] < keys[elem])
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

static void	mergeInsertVector(std::vector<size_t> &idx, const std::vector<int> &keys) {
	const size_t	n = idx.size();

	if (n < 2)
		return;

	std::vector<size_t>	larger;
	std::vector<size_t>	partner(keys.size());

	larger.reserve(n / 2);
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		size_t	a = idx[i];
		size_t	b = idx[i + 1];

		if (keys[a] < keys[b])
			std::swap(a, b);
		larger.push_back(a);
		partner[a] = b;
	}

	mergeInsertVector(larger, keys);

	std::vector<size_t>	chain;

	chain.reserve(n);
	chain.push_back(partner[larger[0]]);
	chain.insert(chain.end(), larger.begin(), larger.end());

	std::vector<size_t>	pend;

	for (size_t k = 1; k < larger.size(); ++k)
		pend.push_back(partner[larger[k]]);
	if (n % 2)
		pend.push_back(idx[n - 1]);

	const size_t	last = pend.size() + 1;
	size_t			prev = 1;
	size_t			k = 3;

	while (prev < last) {
		size_t	curr = jacobsthal(k++);
		size_t	top = std::min(curr, last);

		for (size_t b = top; b > prev; --b) {
			size_t	elem = pend[b - 2];

			chain.insert(chain.begin() + searchVector(chain, keys, elem), elem);
		}
		prev = curr;
	}
	idx.swap(chain);
}

void	PmergeMe::fillVector(int argc, char **argv)
{
	_vector.clear();
	for (int i = 1; i < argc; ++i) {
		std::istringstream	iss(argv[i]);
		std::string			token;
		bool				found = false;

		while (iss >> token) {
			_vector.push_back(parseToken(token));
			found = true;
		}
		if (!found)
			throw std::runtime_error("empty argument");
	}
}

void	PmergeMe::sortVector()
{
	std::vector<size_t>	idx(_vector.size());

	for (size_t i = 0; i < idx.size(); ++i)
		idx[i] = i;
	mergeInsertVector(idx, _vector);

	std::vector<int>	sorted;

	sorted.reserve(idx.size());
	for (size_t i = 0; i < idx.size(); ++i)
		sorted.push_back(_vector[idx[i]]);
	_vector.swap(sorted);
}

/* ----------------------------- std::deque version ------------------------- */

static size_t	searchDeque(const std::deque<size_t> &chain, const std::deque<int> &keys, size_t elem)
{
	size_t	lo = 0;
	size_t	hi = chain.size();

	while (lo < hi) {
		size_t	mid = lo + (hi - lo) / 2;

		if (keys[chain[mid]] < keys[elem])
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

static void	mergeInsertDeque(std::deque<size_t> &idx, const std::deque<int> &keys)
{
	const size_t	n = idx.size();

	if (n < 2)
		return;

	// 1. Pair adjacent elements; keep the larger one, remember its partner.
	std::deque<size_t>	larger;
	std::deque<size_t>	partner(keys.size());

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		size_t	a = idx[i];
		size_t	b = idx[i + 1];

		if (keys[a] < keys[b])
			std::swap(a, b);
		larger.push_back(a);
		partner[a] = b;
	}

	mergeInsertDeque(larger, keys);

	std::deque<size_t>	chain(larger);

	chain.push_front(partner[larger[0]]);

	std::deque<size_t>	pend;

	for (size_t k = 1; k < larger.size(); ++k)
		pend.push_back(partner[larger[k]]);
	if (n % 2)
		pend.push_back(idx[n - 1]);

	const size_t	last = pend.size() + 1;
	size_t			prev = 1;
	size_t			k = 3;

	while (prev < last) {
		size_t	curr = jacobsthal(k++);
		size_t	top = std::min(curr, last);

		for (size_t b = top; b > prev; --b) {
			size_t	elem = pend[b - 2];

			chain.insert(chain.begin() + searchDeque(chain, keys, elem), elem);
		}
		prev = curr;
	}
	idx.swap(chain);
}

void	PmergeMe::fillDeque(int argc, char **argv)
{
	_deque.clear();
	for (int i = 1; i < argc; ++i) {
		std::istringstream	iss(argv[i]);
		std::string			token;
		bool				found = false;

		while (iss >> token) {
			_deque.push_back(parseToken(token));
			found = true;
		}
		if (!found)
			throw std::runtime_error("empty argument");
	}
}

void	PmergeMe::sortDeque()
{
	std::deque<size_t>	idx(_deque.size());

	for (size_t i = 0; i < idx.size(); ++i)
		idx[i] = i;
	mergeInsertDeque(idx, _deque);

	std::deque<int>	sorted;

	for (size_t i = 0; i < idx.size(); ++i)
		sorted.push_back(_deque[idx[i]]);
	_deque.swap(sorted);
}

/* --------------------------------- Driver --------------------------------- */

void	PmergeMe::run(int argc, char **argv)
{
	// Each timing covers data management (parsing + filling) AND sorting.
	std::clock_t	start = std::clock();
	fillVector(argc, argv);
	sortVector();
	double			vectorUs = elapsedUs(start, std::clock());

	start = std::clock();
	fillDeque(argc, argv);
	sortDeque();
	double			dequeUs = elapsedUs(start, std::clock());

	// Output happens outside the timed sections. Input is already validated.
	std::cout << "Before:";
	for (int i = 1; i < argc; ++i) {
		std::istringstream	iss(argv[i]);
		std::string			token;

		while (iss >> token)
			std::cout << ' ' << parseToken(token);
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << ' ' << _vector[i];
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector : " << vectorUs << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
			  << " elements with std::deque  : " << dequeUs << " us" << std::endl;
}
