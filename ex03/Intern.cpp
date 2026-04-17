#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <iostream>

Intern::Intern()
{
	return ;
}

Intern	&Intern::operator=(Intern &other)
{
	(void)other;

	return (*this);
}

Intern::Intern(Intern &other)
{
	(void)other;

	return ;
}

Intern::~Intern()
{
	return ;
}

const char	*Intern::NotExistingForm::what() const throw()
{
	return "Form doesn't exist!";
}

AForm	*Intern::createShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::createPresidentialForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::createRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	const std::string	form_names[3] =
	{
		"shrubbery creation",
		"presidential pardon",
		"robotomy request"
	};

	AForm	*(Intern::*form_functions[3])(const std::string &) =
	{
		&Intern::createShrubberyForm,
		&Intern::createPresidentialForm,
		&Intern::createRobotomyForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == form_names[i])
		{
			std::cout << "Intern creates " << form_names[i] << std::endl;
			return ((this->*form_functions[i])(target));
		}
	}
	throw NotExistingForm();
}
