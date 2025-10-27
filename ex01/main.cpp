#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
    try
    {
        Bureaucrat bureaucrat("Aron", 1);
        // Bureaucrat bureaucrat("Aron", 150);

		std::cout << bureaucrat;

        bureaucrat.increment_grade();
        // bureaucrat.decrement_grade();
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}