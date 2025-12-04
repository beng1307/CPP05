#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other):
	AForm(other), target(other.target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

void	ShrubberyCreationForm::executeAction() const
{
	std::string	trees =
	"  /\\  /\\  /\\  \n"
	" /  \\/  \\/  \\ \n"
	" /  \\/  \\/  \\ \n"
	"  ||  ||  || \n";

	std::ofstream file((target + "_shrubbery").c_str());
	if (!file)
	{
		std::cout << "File didn't open!" << std::endl;
		return ;
	}
	file << trees;
	file.close();
}
