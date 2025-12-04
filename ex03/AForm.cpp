#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

AForm::AForm(const std::string &name, unsigned signing_grade, unsigned executing_grade):
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

AForm	&AForm::operator=(AForm &other)
{
	if (this != &other)
		is_signed = other.is_signed;
	return (*this);
}

AForm::AForm(AForm &other):
	name(other.name), is_signed(other.is_signed),
	signing_grade(other.signing_grade), executing_grade(other.executing_grade)
{
	return ;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form not signed!";
}

AForm::~AForm()
{
	return ;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= signing_grade)
		is_signed = true;
	else
		throw (GradeTooLowException());
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!is_signed)
		throw (NotSignedException());
	if (executor.getGrade() > executing_grade)
		throw (GradeTooLowException());
	
	executeAction();
}

const std::string	AForm::get_name() const
{
	return (name);
}

bool	AForm::get_is_signed() const
{
	return (is_signed);
}

unsigned	AForm::get_signing_grade() const
{
	return (signing_grade);
}

unsigned	AForm::get_executing_grade() const
{
	return (executing_grade);
}

std::ostream &operator<<(std::ostream &output, const AForm &form)
{
    output << "Name: " << form.get_name() << std::endl;
    output << "Signed: " << form.get_is_signed() << std::endl;
    output << "Signing grade required: " << form.get_signing_grade() << std::endl;
    output << "Executing grade required: " << form.get_executing_grade() << std::endl;
    
	return (output);
}
