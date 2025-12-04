#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat test("Burny", 1);
		ShrubberyCreationForm shrub("shrubbery");
		RobotomyRequestForm robot("robotomy");
		PresidentialPardonForm pardon("presidential");
	
		std::cout << test << shrub << robot << pardon;
	
		shrub.beSigned(test);
		robot.beSigned(test);
		pardon.beSigned(test);

		shrub.execute(test);
		robot.execute(test);
		pardon.execute(test);
	}
	catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
