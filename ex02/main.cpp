#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	///////////////////////////////////////////////////////////////////////////
	// Test case: Creating all forms
	std::cout << "\033[33m===Creating all forms===\033[0m" << std::endl;
	try
	{
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Jimmy");

		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Executing a form that is not signed
	std::cout << "\033[33m===Executing a form that is not signed===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Tony", 1);
		ShrubberyCreationForm shrub("toilet");

		shrub.execute(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Bureaucrat with too low grade signs a form
	std::cout << "\n\033[33m===Bureaucrat with too low grade signs a form===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Mr.Anderson", 150);
		RobotomyRequestForm robot("Clanker");

		bureaucrat.signForm(robot);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Signed form executed by bureaucrat with too low grade
	std::cout << "\n\033[33m===Signed form executed by bureaucrat with too low grade===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Hans", 6);
		PresidentialPardonForm pardon("Prisoner");

		bureaucrat.signForm(pardon);
		pardon.execute(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Bureaucrat signs and executes all forms successfully
	std::cout << "\n\033[33m===High grade bureaucrat signs and executes all forms successfully===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Fridolin", 1);
		ShrubberyCreationForm shrub("dishes");
		RobotomyRequestForm robot("R2D2");
		PresidentialPardonForm pardon("Gangster");

		bureaucrat.signForm(shrub);
		bureaucrat.signForm(robot);
		bureaucrat.signForm(pardon);

		shrub.execute(bureaucrat);
		robot.execute(bureaucrat);
		pardon.execute(bureaucrat);
	}
	catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

	return (0);
}
