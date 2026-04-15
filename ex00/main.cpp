#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	///////////////////////////////////////////////////////////////////////////
	// Test case: Creating a bureaucrat with invalid grades
	std::cout << "\033[33m===Creating a bureaucrat with invalid grades===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat1("Aron", 0);
		std::cout << bureaucrat1;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat bureaucrat2("Aron", 151);
		std::cout << bureaucrat2;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////
	// Test case: Incrementing grade above 1
	std::cout << "\n\033[33m===Incrementing grade above 1===\033[0m" << std::endl;
	try
    {
        Bureaucrat bureaucrat1("Aron", 1);
		std::cout << bureaucrat1;
        bureaucrat1.increment_grade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

	///////////////////////////////////////////////////////////////////////////
	// Test case: Decrementing grade below 150
	std::cout << "\n\033[33m===Decrementing grade below 150===\033[0m" << std::endl;
	try
	{
		Bureaucrat bureaucrat2("John", 150);
		std::cout << bureaucrat2;
        bureaucrat2.decrement_grade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

}