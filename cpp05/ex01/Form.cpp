/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:51:49 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/19 13:14:46 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// ORTHODOX CANNONICAL FORM
Form::Form(void) : _name("default"), _signed(false), _grade_to_sign(150), _grade_to_execute(150) {
	return ;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	if (grade_to_sign < _max_grade || grade_to_execute < _max_grade)
		throw Form::GradeTooHighException();
	if (grade_to_sign > _min_grade || grade_to_execute > _min_grade)
		throw Form::GradeTooLowException();
	return ;
}

Form::Form(const Form &source) : _name(source._name), _signed(source._signed), _grade_to_sign(source._grade_to_sign), _grade_to_execute(source._grade_to_execute) {
	*this = source;
	return ;
}

Form::~Form(void) {
	return ;
}

// OPERATOR OVERLOAD
Form	&Form::operator=(const Form &other) {
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

// GETTER
std::string	Form::getName(void) const {
	return (_name);
}
bool		Form::getSigned(void) const {
	return (_signed);
}
int			Form::getGradeToSign(void) const {
	return (_grade_to_sign);
}
int			Form::getGradeToExecute(void) const {
	return (_grade_to_execute);
}

// MEMBER FUNCTIONS
void		Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
	return ;
}

// EXCEPTION CLASSES
const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}
const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

// STREAM OPERATOR OVERLOAD
std::ostream	&operator<<(std::ostream &out, const Form &form) {
	out << GREEN << form.getName() << RESET << ", ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << ", form grade to sign " << YELLOW << form.getGradeToSign() << RESET << ", form grade to execute " << YELLOW << form.getGradeToExecute() << RESET << ".";
	return (out);
}
