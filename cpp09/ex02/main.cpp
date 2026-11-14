/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:55:27 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/14 19:04:36 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <exception>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		PmergeMe	sorter;

		sorter.run(argc, argv);
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
