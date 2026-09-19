/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:46:17 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/19 13:15:28 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("default", 1, 1), _target("default") {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) : AForm(source), _target(source._target) {
	*this = source;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source) {
	if (this != &source) {
		AForm::operator=(source);
		_target = source._target;
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file;
	std::string filename = _target + "_shrubbery";
	file.open(filename.c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException();
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
	file << "      ||      " << std::endl;
	file << "    \\****/    " << std::endl;
	file << "     \\**/     " << std::endl;
	file << "      \\/      " << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	return ("Error: could not open file.");
}
