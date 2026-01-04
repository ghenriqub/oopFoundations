/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:15:39 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/04 15:29:14 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->Index = 0;
	this->Full = false;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::SetInformation(void)
{
	std::string input;
	if (this->Full == false)
	{
		std::cout << "This is your contact #" << this->Index + 1 << std::endl;
		if (this->Contacts[this->Index].SetContact() == true)
		{
			if (this->Index == 7)
				this->Full = true;
			else
				this->Index++;
		}
	}
	else
	{
		std::cout << "Your phonebook is full.\nIf you want to add a new contact, the first contact will be deleted, index #1." << std::endl;
		std::cout << "If you want to proceed, press '1' and 'enter',\nOtherwise press anything but '1' and 'enter' to go back to main menu." << std::endl;
		std::cout << "Your choice: ";
		getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
			std::exit(0);
		}
		else if (input.compare("1") == 0)
		{
			for (int i = 1; i < 8; i++)
				this->Contacts[i - 1] = this->Contacts[i];
			std::cout << "This is your contact #8" << std::endl;
			this->Contacts[this->Index].SetContact();
		}
		else
			std::cout << "Back to main menu without deleting and creating a contact." << std::endl;
	}
}

void	PhoneBook::GetInformation() const
{
	int	index;

	if (this->Index == 0)
		std::cout << "\033[31mPlease add at least one contact before searching.\033[0m" << std::endl;
	else
	{
		std::string input;
		std::cout << "Please tell me which contact index i should show you. (0 to quit searching)\nIndex: ";
		while (!(std::getline(std::cin, input)) || input.length() > 1 || input.compare("0") < 0 || input.compare("8") > 0 || (std::atoi(input.c_str()) -1 >= this->Index && this->Full == false))
		{
			if (std::cin.eof() == true)
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (input.length() > 1 || input.compare("0") < 0 || input.compare("8") > 0)
			{
				std::cin.clear();
				std::cout << "\033[31mOnly digits in range of 1 to 8 are allowed.\033[0m\n";
				std::cout << "Please tell me which contact i should show you. (0 to quit searching)\nIndex: ";
			}
			else if (std::atoi(input.c_str()) - 1 >= this->Index && this->Full == false)
			{
				std::cout << "\033[33mYou only have " << this->Index << " Contacts saved.\033[0m" << std::endl;
				std::cin.clear();
				std::cout << "Please tell me which contact i should show you. (0 to quit searching)\nIndex: ";
			}
		}
		index = std::atoi(input.c_str());
		if (index > 0)
			this->Contacts[index - 1].DisplayContact();
		else
			std::cout << "Exiting search mode now." << std::endl;
	}
}

void	PhoneBook::ShowInstruction(void)
{
	std::cout << "\033[KEnter your command [ADD, SEARCH, EXIT]:" << std::endl;
}
