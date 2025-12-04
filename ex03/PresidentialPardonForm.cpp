#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", 25, 5), target(target)
{
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other):
	AForm(other), target(other.target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
