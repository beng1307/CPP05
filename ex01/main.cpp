#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	///////////////////////////////////////////////////////////////////////////
	// Test case: Creating a form
	std::cout << "\033[33m===Creating a form===\033[0m" << std::endl;
	try
	{
		Form form("Form A", 10, 1);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Creating a form with invalid signing and executing grades
	std::cout << "\n\033[33m===Creating a form with invalid signing and executing grades===\033[0m" << std::endl;
	try
	{
		Form form("Form A", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form form("Form A", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Form form("Form A", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Form form("Form A", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Bureaucrat with high enough grade signs it successfully
	std::cout << "\n\033[33m===Bureaucrat with high enough grade signs it successfully===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat("John", 10);
		Form form("Form A", 10, 1);

		bureaucrat.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Bureaucrat with too low grade signing a form that requires a higher grade
	std::cout << "\n\033[33m===Bureaucrat with too low grade signing a form that requires a higher grade===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat1("John", 10);
		Form form("Form A", 1, 1);

		bureaucrat1.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}