#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Form::Form(const std::string &name, unsigned signing_grade, unsigned executing_grade):
	name(name), is_signed(false), signing_grade(signing_grade), executing_grade(executing_grade)
{
	if (signing_grade < 1)
		throw (GradeTooHighException());
	else if (signing_grade > 150)
		throw (GradeTooLowException());
	if (executing_grade < 1)
		throw (GradeTooHighException());
	else if (executing_grade > 150)
		throw (GradeTooLowException());
}

Form	&Form::operator=(Form &other)
{
	if (this != &other)
		is_signed = other.is_signed;
	return (*this);
}

Form::Form(Form &other):
	name(other.name), is_signed(other.is_signed),
	signing_grade(other.signing_grade), executing_grade(other.executing_grade)
{
	return ;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too Low!";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too High!";
}

Form::~Form()
{
	return ;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= signing_grade)
		is_signed = true;
	else
		throw (GradeTooLowException());
}

const std::string	Form::get_name() const
{
	return (name);
}

bool	Form::get_is_signed() const
{
	return (is_signed);
}

unsigned	Form::get_signing_grade() const
{
	return (signing_grade);
}

unsigned	Form::get_executing_grade() const
{
	return (executing_grade);
}

std::ostream &operator<<(std::ostream &output, const Form &form)
{
    output << "Name: " << form.get_name() << std::endl;
    output << "Signed: " << form.get_is_signed() << std::endl;
    output << "Signing grade required: " << form.get_signing_grade() << std::endl;
    output << "Executing grade required: " << form.get_executing_grade() << std::endl;
    
	return (output);
}
