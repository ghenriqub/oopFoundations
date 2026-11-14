/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:48:51 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/14 19:11:52 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <exception>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange	exchange;

		exchange.loadDatabase("data.csv");
		exchange.processInput(argv[1]);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
