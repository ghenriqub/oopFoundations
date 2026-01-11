/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:21:42 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/11 19:34:27 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Address of string:\t\t" << &str << std::endl;
	std::cout << "Address of Pointer:\t\t" << &stringPTR << std::endl;
	std::cout << "Address of Reference:\t\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string:\t\t" << str << std::endl;
	std::cout << "Value pointed to by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Value of stringREF:\t\t" << stringREF << std::endl;

	return 0;
}
