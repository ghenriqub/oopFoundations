/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:30:34 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/04 15:29:22 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <csignal>
# include "../includes/Contact.hpp"

class PhoneBook{
	private:
		Contact	Contacts[8];
		int		Index;
		bool	Full;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	SetInformation(void);
		void	GetInformation(void)const;
		void	ShowInstruction(void);
};

#endif
