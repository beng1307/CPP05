#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

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
	if (name == "shrubbery creation")
		return (Intern::createShrubberyForm(target));
	else if (name == "presidential pardon")
		return (Intern::createPresidentialForm(target));
	else if (name == "robotomy request")
		return (Intern::createRobotomyForm(target));
	else
		throw NotExistingForm();
}
