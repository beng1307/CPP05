#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
    try
    {
        Bureaucrat bureaucrat("Aron", 130);
        // Bureaucrat bureaucrat("Aron", 131);
		std::cout << bureaucrat;
		
		Form	form("Form", 130, 130);
		bureaucrat.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}