/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:51:57 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/19 13:14:58 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

// ORTHODOX CANNONICAL FORM
Intern::Intern(void) {
    _form_types[ROBOTOMY_REQUEST] = "robotomy request";
    _form_types[PRESIDENTIAL_PARDON] = "presidential pardon";
    _form_types[SHRUBBERY_CREATION] = "shrubbery creation";
    return ;
}

Intern::Intern(const Intern &source) {
	*this = source;
	return ;
}

Intern  &Intern::operator=(const Intern &source) {
    if (this != &source) {
        for (int i = 0; i < 3; i++)
            _form_types[i] = source._form_types[i];
    }
    return (*this);
}

Intern::~Intern(void) {
    return ;
}

// MAKE FORM
AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm*  form = NULL;
    int     form_type = -1;

    while (++form_type < 3)
        if (name == _form_types[form_type])
            break ;

    switch (form_type) {
        case ROBOTOMY_REQUEST:
            form = new RobotomyRequestForm(target);
            break;
        case PRESIDENTIAL_PARDON:
            form = new PresidentialPardonForm(target);
            break;
        case SHRUBBERY_CREATION:
            form = new ShrubberyCreationForm(target);
            break;
        default:
            throw Intern::FormNotFoundException();
    }
    std::cout << YELLOW << "Intern" << RESET << " creates " << GREEN << form->getName() << RESET << std::endl;
    return (form);
}

// EXCEPTION CLASS
const char* Intern::FormNotFoundException::what() const throw() {
    return ("Type of form specified cannot be created. Please, try creating a different form.");
}
