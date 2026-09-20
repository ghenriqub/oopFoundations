/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 17:24:20 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/20 14:04:29 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

/* ---------- helpers ---------- */

static const double INF = std::numeric_limits<double>::infinity();

static bool isNan(double d) { return d != d; }

static bool isPseudo(const std::string &s, double &d)
{
	if (s == "nan" || s == "nanf")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (s == "+inf" || s == "+inff")
		d = INF;
	else if (s == "-inf" || s == "-inff")
		d = -INF;
	else
		return false;
	return true;
}

// Blocks what strtol/strtod accepts but clean: spaces, hex, "infinity"...
static bool isNumeric(const std::string &s)
{
	return !s.empty() && s.find_first_not_of("0123456789.+-eE") == std::string::npos;
}

static bool parseInt(const std::string &s, double &d)
{
	if (!isNumeric(s))
		return false;
	char *end;
	errno = 0;
	long v = std::strtol(s.c_str(), &end, 10);
	if (*end != '\0' || errno == ERANGE || v < INT_MIN || v > INT_MAX)
		return false;
	d = static_cast<double>(static_cast<int>(v));
	return true;
}

static bool parseDouble(const std::string &s, double &d)
{
	if (!isNumeric(s))
		return false;
	char *end;
	errno = 0;
	d = std::strtod(s.c_str(), &end);
	return *end == '\0' && errno != ERANGE;
}

static bool parseFloat(const std::string &s, double &d)
{
	if (s.length() < 2 || s[s.length() - 1] != 'f')
		return false;
	if (!parseDouble(s.substr(0, s.length() - 1), d) || d > FLT_MAX || d < -FLT_MAX)
		return false;
	d = static_cast<double>(static_cast<float>(d));
	return true;
}

// Detects the type and converts to double
static bool parse(const std::string &s, double &d)
{
	if (isPseudo(s, d))
		return true;
	if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
	{
		d = static_cast<char>(s[0]);
		return true;
	}
	return parseInt(s, d) || parseFloat(s, d) || parseDouble(s, d);
}

// Adds ".0" when there's no '.', exponent or nan/inf
static std::string fmt(double d)
{
	std::ostringstream oss;
	oss << d;
	std::string s = oss.str();
	if (s.find_first_of(".en") == std::string::npos)
		s += ".0";
	return s;
}

/* ---------- output ---------- */

static void printChar(double d)
{
	std::cout << "char: ";
	if (isNan(d) || d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<unsigned char>(static_cast<char>(d))))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(d) << "'";
	std::cout << std::endl;
}

static void printInt(double d)
{
	std::cout << "int: ";
	if (isNan(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;
}

static void printFloat(double d)
{
	std::cout << "float: ";
	bool finite = !isNan(d) && d != INF && d != -INF;
	if (finite && (d > FLT_MAX || d < -FLT_MAX))
		std::cout << "impossible";
	else
		std::cout << fmt(static_cast<double>(static_cast<float>(d))) << "f";
	std::cout << std::endl;
}

static void printDouble(double d)
{
	std::cout << "double: " << fmt(d) << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	double d;

	if (!parse(literal, d))
	{
		std::cout << "Error: invalid literal" << std::endl;
		return;
	}
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
