/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:25:06 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/19 13:15:00 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ORTHODOX CANNONICAL FORM
AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {
	return ;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < _maxGrade || gradeToExecute < _maxGrade)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > _minGrade || gradeToExecute > _minGrade)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::AForm(const AForm &source) : _name(source._name), _signed(source._signed), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) {
	*this = source;
	return ;
}

AForm::~AForm(void) {
	return ;
}

// OPERATOR OVERLOAD
AForm	&AForm::operator=(const AForm &source) {
	if (this == &source)
		return (*this);
	_signed = source._signed;
	return (*this);
}

// GETTER
std::string AForm::getName(void) const {
	return (_name);
}
bool		AForm::getSigned(void) const {
	return (_signed);
}
int			AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}
int			AForm::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

// MEMBER FUNCTIONS
void		AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
	return ;
}

// EXCEPTION CLASSES
const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed!");
}

// STREAM OPERATOR OVERLOAD
std::ostream	&operator<<(std::ostream &os, const AForm &form) {
	os << "Form " << form.getName() << " is ";
	if (form.getSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute.";
	return (os);
}
