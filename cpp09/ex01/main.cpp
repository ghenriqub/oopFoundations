/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:52:38 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/14 19:04:43 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <exception>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		RPN	rpn;

		std::cout << rpn.evaluate(argv[1]) << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
