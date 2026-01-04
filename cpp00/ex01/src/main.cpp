/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:35:55 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/04 18:58:30 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	SignalHandler(int signum) {
    if (signum == SIGINT) {
        std::cout << "\n\033[33m$>\033[0mYou pressed ^C, bye!\n";
        std::exit(0);
    }
	if (signum == SIGQUIT) {
        std::cout << "\n\033[33m$>\033[0mYou pressed ^C, bye!\n";
        std::exit(0);
    }
}

bool	IsOnlyWhitespace(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

int	main() {
	PhoneBook 	PhoneBook;
	bool		run = true;
	std::string	command;

	PhoneBook.ShowInstruction();
	std::signal(SIGINT, SignalHandler);
	std::cout << "\033[33m$>\033[0m";
	while (run && std::getline(std::cin, command)) {
		if (std::cin.eof() == true)
		{
			std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
			exit(0);
		}
		else if (command.compare("ADD") == 0)
			PhoneBook.SetInformation();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.GetInformation();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "Goodbye!" << std::endl;
			run = false;
			continue ;
		}
		PhoneBook.ShowInstruction();
		std::cout << "\033[33m$>\033[0m";
	}
	if (run)
		std::cout << "You pressed ^D, bye!" << command << std::endl;
	else if (command.length() == 0 || IsOnlyWhitespace(command))
		std::cout << "We dont accept only spaces" << command << std::endl;
	return (0);
}
