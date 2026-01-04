/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:10:25 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/04 18:58:43 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "main.hpp"

static bool	IsOnlyDigits(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

std::string Contact::FieldName[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact() {
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->Informations[i] = std::string();
	return;
}

Contact::~Contact() {
	return ;
}

bool	Contact::SetContact() {
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "Please enter the " << Contact::FieldName[i] << ":\n+";
		while (!(std::getline(std::cin, this->Informations[i])) || 
    		this->Informations[i].length() == 0 || 
    		IsOnlyWhitespace(this->Informations[i]) || 
			(i == PhoneNumber && !IsOnlyDigits(this->Informations[i]))) {
			if (std::cin.eof() == true) {
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (this->Informations[i].length() == 0 || IsOnlyWhitespace(this->Informations[i])) {
				this->Informations[i].clear();
				std::cout << "Empty contact information not allowed." << std::endl;
				std::cout << "Please enter the " << Contact::FieldName[i] << ":\n+";
			}
			else if (i == PhoneNumber && !IsOnlyDigits(this->Informations[i])) {
				this->Informations[i].clear();
				std::cout << "Phone number must contain only digits (0-9)." << std::endl;
				std::cout << "Please enter the " << Contact::FieldName[i] << ":\n+";
			}
		}
	}
	std::cout << "Contact added successfully." << std::endl;
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
