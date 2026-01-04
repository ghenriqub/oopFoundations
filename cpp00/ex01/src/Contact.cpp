/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:10:25 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/04 15:31:52 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

std::string Contact::FieldName[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};


Contact::Contact()
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->Informations[i] = std::string();
	return;
}

Contact::~Contact()
{
	return ;
}

bool	Contact::SetContact()
{
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "Please enter the " << Contact::FieldName[i] << ":\n+";
		while ( !(std::getline(std::cin, this->Informations[i])) || this->Informations[i].length() == 0)
		{
			if (std::cin.eof() == true)
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (this->Informations[i].length() == 0)
			{
				this->Informations[i].clear();
				std::cout << "\033[31mEmpty contact information not allowed.\033[0m" << std::endl;
				std::cout << "Please enter the " << Contact::FieldName[i] << ":\n+";
			}
		}
	}
	std::cout << "\033[32mContact added successfully.\033[0m" << std::endl;
	return (true);
}

void	Contact::GetContact(int index) const {
	std::cout << "|" << std::setw(10) << index;
	for (int i = FirstName; i <= NickName; i++) {
		std::cout << "|";
		if (this->Informations[i].length() > 10)
			std::cout << this->Informations[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->Informations[i];
	}
	std::cout << "|" << std::endl;
}

void	Contact::DisplayContact() const {
	std::cout << "============== Contact Details ==============" << std::endl;
	for (int i = FirstName; i <= DarkestSecret; i++) {
		std::cout << std::setw(15) << std::left << Contact::FieldName[i] << ": "
				<< this->Informations[i] << std::endl;
	}
	std::cout << "=============================================" << std::endl;
}
