/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:15:39 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/04 18:58:37 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook(void) {
	this->Index = 0;
	this->Full = false;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::SetInformation(void) {
	std::string input;

	if (this->Full == false) {
		std::cout << "This is your contact #" << this->Index + 1 << std::endl;
		if (this->Contacts[this->Index].SetContact() == true) {
			if (this->Index == 7)
				this->Full = true;
			else
				this->Index++;
		}
	}
	else {
		std::cout << "Your phonebook is full.\nIf you want to add a new contact, the first contact will be deleted, index #1." << std::endl;
		std::cout << "If you want to proceed, press '1' and 'enter',\nOtherwise press anything but '1' and 'enter' to go back to main menu." << std::endl;
		std::cout << "Your choice: ";
		getline(std::cin, input);
		if (std::cin.eof() == true) {
			std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
			std::exit(0);
		}
		else if (input.compare("1") == 0) {
			for (int i = 1; i < 8; i++)
				this->Contacts[i - 1] = this->Contacts[i];
			std::cout << "This is your contact #8" << std::endl;
			this->Contacts[this->Index].SetContact();
		}
		else
			std::cout << "Back to main menu without deleting and creating a contact." << std::endl;
	}
}

void	PhoneBook::GetInformation() const {
	int			index;
	int			max_contacts;
	std::string	command;

	std::signal(SIGINT, SignalHandler);
	std::signal(SIGQUIT, SignalHandler);
	if (this->Index == 0) {
		std::cout << "Please add at least one contact before searching." << std::endl;
		return ;
	}
	if (this->Full)
		max_contacts = 8;
	else
		max_contacts = this->Index;

    std::cout << "\n|-------------------------------------------|\n";
    std::cout << "|    Index |First Name| Last Name| Nickname |\n";
    std::cout << "|----------|----------|----------|----------|\n";
    for (int i = 0; i < max_contacts; i++)
        this->Contacts[i].GetContact(i + 1);
    std::cout << "|-------------------------------------------|\n\n";
	std::cout << "Please tell me which contact index i should show you. (0 to quit searching)\nIndex: ";
	while (!(std::getline(std::cin, command)) || command.length() == 0 || 
    	IsOnlyWhitespace(command) || command.length() > 1 || 
    	command.compare("0") < 0 || command.compare("8") > 0 || 
    	(std::atoi(command.c_str()) - 1 >= this->Index && this->Full == false)) {
		if (std::cin.eof() == true) {
			std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
			std::exit(0);
		}
		else if (command.length() == 0 || IsOnlyWhitespace(command)) {
			std::cin.clear();
			std::cout << "Empty input not allowed.\n";
			std::cout << "Please tell me which contact i should show you. (0 to quit searching)\nIndex: ";
		}
		else if (command.length() > 1 || command.compare("0") < 0 || command.compare("8") > 0) {
			std::cin.clear();
			std::cout << "Only digits in range of 1 to 8 are allowed.\n";
			std::cout << "Please tell me which contact i should show you. (0 to quit searching)\nIndex: ";
		}
		else if (std::atoi(command.c_str()) - 1 >= this->Index && this->Full == false) {
			std::cout << "You only have " << this->Index << " Contacts saved." << std::endl;
			std::cin.clear();
			std::cout << "Please tell me which contact i should show you. (0 to quit searching)\nIndex: ";
		}
	}
	index = std::atoi(command.c_str());
	if (index > 0)
		this->Contacts[index - 1].DisplayContact();
	else
		std::cout << "Exiting search mode now." << std::endl;
}

void	PhoneBook::ShowInstruction(void) {
	std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
}
