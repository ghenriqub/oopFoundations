/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:35:55 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/04 14:59:35 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

static void	SignalHandler(int signum) {
    if (signum == SIGINT) {
        std::cout << "\n\033[33m$>\033[0mYou pressed ^C, bye!\n";
        std::exit(0);
    }
}

int	main() {
	PhoneBook 	PhoneBook;
	bool		run = true;
	std::string	command;

	PhoneBook.ShowInstruction();
	std::signal(SIGINT, SignalHandler);
	std::cout << "\033[33m$>\033[0m";
	while (run && std::getline(std::cin, command))
	{
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
			std::cout << "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
			run = false;
			continue ;
		}
		command.clear();
		PhoneBook.ShowInstruction();
		std::cout << "\033[33m$>\033[0m";
	}
	if (run)
	{
		std::cout << "You pressed ^D, bye!" << command << std::endl;
	}
	return (0);
}
