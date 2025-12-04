#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <map>

Intern::Intern()
{
	return ;
}

Intern	&Intern::operator=(Intern &other)
{
	return (*this);
}

Intern::Intern(Intern &other)
{
	return ;
}

Intern::~Intern()
{
	return ;
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
	std::map<std::string, AForm *(*)(const std::string &)>	formMap;

	formMap["shrubbery creation"] = &Intern::createShrubberyForm;
	formMap["presidential pardon"] = &Intern::createPresidentialForm;
	formMap["robotomy request"] = &Intern::createRobotomyForm;

	std::map<std::string, AForm *(*)(const std::string &)>::iterator index = formMap.find(name);

	if (index != formMap.end())
		return (index->second(target));

	throw NotExistingForm();
}