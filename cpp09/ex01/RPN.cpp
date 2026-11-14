/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:54:16 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/14 18:11:59 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cctype>
#include <climits>
#include <stdexcept>

/* ------------------------- Orthodox Canonical Form ------------------------ */

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

/* -------------------------------- Helpers -------------------------------- */

static bool	isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

static long	applyOperator(char op, long lhs, long rhs)
{
	switch (op)
	{
		case '+': return lhs + rhs;
		case '-': return lhs - rhs;
		case '*': return lhs * rhs;
		default:
			if (rhs == 0)
				throw std::runtime_error("division by zero");
			return lhs / rhs;
	}
}

/* ----------------------------- Public methods ----------------------------- */

long	RPN::evaluate(const std::string &expression)
{
	while (!_stack.empty())
		_stack.pop();

	for (size_t i = 0; i < expression.size(); ++i)
	{
		char	c = expression[i];

		if (c == ' ')
			continue;
		if (i + 1 < expression.size() && expression[i + 1] != ' ')
			throw std::runtime_error("invalid token");

		if (std::isdigit(static_cast<unsigned char>(c)))
			_stack.push(c - '0');
		else if (isOperator(c))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("not enough operands");
			long	rhs = _stack.top();
			_stack.pop();
			long	lhs = _stack.top();
			_stack.pop();

			long	result = applyOperator(c, lhs, rhs);
			if (result > INT_MAX || result < INT_MIN)
				throw std::runtime_error("overflow");
			_stack.push(result);
		}
		else
			throw std::runtime_error("invalid character");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("invalid expression");
	return _stack.top();
}
