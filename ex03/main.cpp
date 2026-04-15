#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern		intern;

	///////////////////////////////////////////////////////////////////////////
	// Test case: Intern creates a shrubbery creation form successfully
	std::cout << "\033[33m===Intern creates a shrubbery creation form successfully===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Jimmy", 1);
		AForm *form = intern.makeForm("shrubbery creation", "toilet");

		std::cout << *form;
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Intern creates a robotomy request form successfully
	std::cout << "\n\033[33m===Intern creates a robotomy request form successfully===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Siegfried", 1);
		AForm *form = intern.makeForm("robotomy request", "R2D2");
	
		std::cout << *form;
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Intern creates a presidential pardon form successfully
	std::cout << "\n\033[33m===Intern creates a presidential pardon form successfully===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Jürgen", 1);
		AForm *form = intern.makeForm("presidential pardon", "Prisoner");

		std::cout << *form;
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Intern tries to create a form that does not exist
	std::cout << "\n\033[33m===Intern tries to create a form that does not exist===\033[0m" << std::endl;
	try
	{
		AForm *form = intern.makeForm("wrong form", "target");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Intern creates a form but bureaucrat grade is too low to sign it
	std::cout << "\n\033[33m===Intern creates a form but bureaucrat grade is too low to sign it===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Jimmy", 150);
		AForm *form = intern.makeForm("robotomy request", "Marvin");

		bureaucrat.signForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

}
