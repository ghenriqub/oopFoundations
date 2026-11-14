/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:48:40 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/14 15:32:32 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

/* ------------------------- Orthodox Canonical Form ------------------------ */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* -------------------------------- Helpers -------------------------------- */

static void	stripCR(std::string &line)
{
	if (!line.empty() && line[line.size() - 1] == '\r')
		line.erase(line.size() - 1);
}

static bool	isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static bool	isValidDate(const std::string &date)
{
	static const int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); ++i)
		if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i])))
			return false;

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1)
		return false;
	int	maxDay = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;
	return day <= maxDay;
}

static bool	parseNumber(const std::string &str, double &out)
{
	size_t	i = 0;
	size_t	digits = 0;

	if (i < str.size() && (str[i] == '+' || str[i] == '-'))
		++i;
	while (i < str.size() && std::isdigit(static_cast<unsigned char>(str[i]))) {
		++i;
		++digits;
	}
	if (digits == 0)
		return false;
	if (i < str.size() && str[i] == '.') {
		size_t	fraction = 0;

		++i;
		while (i < str.size() && std::isdigit(static_cast<unsigned char>(str[i]))) {
			++i;
			++fraction;
		}
		if (fraction == 0)
			return false;
	}
	if (i != str.size())
		return false;
	out = std::strtod(str.c_str(), NULL);
	return true;
}

/* ----------------------------- Public methods ----------------------------- */

void	BitcoinExchange::loadDatabase(const std::string &path)
{
	std::ifstream	file(path.c_str());
	std::string		line;

	if (!file)
		throw std::runtime_error("Error: could not open database file.");
	if (!std::getline(file, line))
		throw std::runtime_error("Error: database is empty.");
	stripCR(line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid database header.");

	while (std::getline(file, line)) {
		stripCR(line);
		if (line.empty())
			continue ;

		size_t	comma = line.find(',');
		double	rate;

		if (comma == std::string::npos
			|| !isValidDate(line.substr(0, comma))
			|| !parseNumber(line.substr(comma + 1), rate)
			|| rate < 0)
			throw std::runtime_error("Error: corrupted database line => " + line);
		_rates[line.substr(0, comma)] = rate;
	}
	if (_rates.empty())
		throw std::runtime_error("Error: database has no entries.");
}

void	BitcoinExchange::processInput(const std::string &path) const
{
	std::ifstream	file(path.c_str());
	std::string		line;
	bool			firstLine = true;

	if (!file)
		throw std::runtime_error("Error: could not open file.");
	while (std::getline(file, line)) {
		stripCR(line);

		if (firstLine) {
			firstLine = false;
			if (line == "date | value")
				continue ;
		}
		processLine(line);
	}
}

/* ----------------------------- Private methods ---------------------------- */

void	BitcoinExchange::processLine(const std::string &line) const
{
	size_t	sep = line.find(" | ");

	if (sep == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}

	std::string	date = line.substr(0, sep);
	std::string	valueStr = line.substr(sep + 3);
	double		value;

	if (!isValidDate(date) || !parseNumber(valueStr, value)) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}
	if (value > 1000) {
		std::cerr << "Error: too large number." << std::endl;
		return ;
	}

	std::map<std::string, double>::const_iterator	it = _rates.upper_bound(date);

	if (it == _rates.begin()) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	--it;
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}
