#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	bureaucrat("Jimmy", 3);
	AForm		*form;
	Intern		intern;

	try
	{
		form = intern.makeForm("robotomy request", "C26");
		form->beSigned(bureaucrat);
		form->execute(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
