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
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

class	Bureaucrat::GradeTooLowException: public std::exception
{
	public:

		const char *what() const noexcept override
		{
			return ("Grade too low!");
		}
};

class	Bureaucrat::GradeTooHighException: public std::exception
{
	public:

		const char *what() const noexcept override
		{
			return ("Grade too high!");
		}
};

const std::string	Bureaucrat::getName() const
{
	return (name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (grade);
}