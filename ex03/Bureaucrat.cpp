#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &other): name(other.name), grade(other.grade)
{
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
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
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.get_name() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.get_name()
			<< " because " << e.what() <<  std::endl;
	}
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
	return (outputstream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl);
}