#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat()
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

const char *GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

const char *GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

void	Bureaucrat::increment_grade()
{
	grade--;
	if (grade < 1)
	throw GradeTooHighException();
	else if (grade > 150)
	throw GradeTooLowException();
}

void	Bureaucrat::decrement_grade()
{
	grade++;
	if (grade < 1)
	throw GradeTooLowException();
	else if (grade > 150)
	throw GradeTooHighException();
}

const std::string	Bureaucrat::getName() const
{
	return (name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (grade);
}

std::ostream	&operator<<(std::ostream &outputstream, const Bureaucrat &bureaucrat)
{
	return (outputstream << bureaucrat.getName() << ",  bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl);
}